"""validate_reports.py must classify and resolve every memory-map row.

The map check used to look only at a row's first cell, only when the immediately
preceding heading said "memory map", so rows written with a backticked address, a
symbol-led register cell, or under a `#### Functions` sub-heading were skipped
without a trace (and a whole map could contribute zero checked rows). These tests
pin the row forms that must resolve, the ones that must fail, the accounting
invariant that no row can leave unclassified, and the debt ledger's
shrink-only rule. Run: python -m pytest tests/test_validate_reports_map_rows.py
"""
import importlib.util
import json
import os
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
SCRIPT_DIR = os.path.join(ROOT, 'utilities', 'scripts', 'rx8-pcm-pipeline')
SCRIPT = os.path.join(SCRIPT_DIR, 'validate_reports.py')

if SCRIPT_DIR not in sys.path:
    sys.path.insert(0, SCRIPT_DIR)


def _load():
    spec = importlib.util.spec_from_file_location('validate_reports_under_test', SCRIPT)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


MOD = _load()


def _fn_entry():
    """Any function entry with an index name, as (address, name)."""
    for addr, row in sorted(MOD.index.items()):
        if row.get('name') and row['name'].startswith('FUN_'):
            return addr, row['name']
    raise AssertionError('no FUN_ entry in function_index.tsv')


def _ram_backed():
    """A RAM cell that carries a tracked alias."""
    addr, row = sorted(MOD.ram_tsv.items())[0]
    return addr, row['alias']


def _ram_free():
    """A RAM cell that still has no tracked alias anywhere."""
    for val in range(0xffffd800, 0xffffe000):
        addr = f'{val:08x}'
        if MOD.resolved(addr, 'ram') or ('DAT_' + addr) in MOD.idmap:
            continue
        return addr
    raise AssertionError('no unbacked RAM cell left - update this test')


def _data_addr():
    """A ROM address that is not a function entry (table/descriptor/pool)."""
    for val in range(0x6c000, 0x7c000, 2):
        addr = f'{val:08x}'
        if not MOD.is_function_entry(addr):
            return addr
    raise AssertionError('no non-function ROM address found')


def _report(*rows, heading='## 4. Proof'):
    body = '\n'.join(rows)
    return f'# Report\n\nROM SHA-256 `{MOD.ROM_SHA}`\n\n{heading}\n\n### 4.1 Memory map\n\n{body}\n'


def test_validator_passes_on_committed_tree():
    # no PYTHONUTF8 override: the validator decodes report text as UTF-8 itself
    r = subprocess.run([sys.executable, SCRIPT], capture_output=True, text=True, cwd=ROOT)
    out = json.loads(r.stdout)
    assert out['result'] == 'PASS', out['failures']
    assert r.returncode == 0
    totals = {}
    for stats in out['reports'].values():
        for k, v in stats.items():
            totals[k] = totals.get(k, 0) + v
    assert totals['map_rows'] > 1300, totals
    assert totals['ram_checked'] > 300 and totals['fn_checked'] > 600, totals
    for key, stats in out['reports'].items():
        assert stats['map_rows'] == (stats['fn_checked'] + stats['ram_checked']
                                     + stats['data_rows'] + stats['io_rows']), key


def test_backticked_and_wide_addresses_parse():
    assert MOD.row_address('`0x0002f890`') == ('0002f890', 'plain')
    assert MOD.row_address('**0x0000563de**') == ('000563de', 'plain')
    assert MOD.row_address('0x563de') == ('000563de', 'plain')
    assert MOD.row_address('_0xffffd1ea_') == ('ffffd1ea', 'plain')


def test_wrapped_address_row_resolves_not_skipped():
    addr, name = _fn_entry()
    text = _report(f'| `0x{addr}` | `{name}` | role |')
    failures, _, stats = MOD.check_report(text, 'x', (), baseline={})
    assert failures == []
    assert stats['map_rows'] == 1 and stats['fn_checked'] == 1


def test_subsection_heading_inherits_map_scope():
    """`#### Functions` under `### 4.1 Memory map` is still map scope."""
    addr, name = _fn_entry()
    text = (f'# R\n\n`{MOD.ROM_SHA}`\n\n## 4. Proof\n\n### 4.1 Memory map\n\n'
            f'#### Functions\n\n| Address | Name | Role |\n|---|---|---|\n'
            f'| 0x{addr} | `{name}` | role |\n')
    failures, _, stats = MOD.check_report(text, 'x', (), baseline={})
    assert failures == []
    assert stats['map_rows'] == 1 and stats['fn_checked'] == 1


def test_bold_ram_sublabel_counts_as_map_scope():
    addr, alias = _ram_backed()
    text = (f'# R\n\n`{MOD.ROM_SHA}`\n\n## 4. Proof\n\n**RAM**\n\n'
            f'| Address | Name | Role |\n|---|---|---|\n| 0x{addr} | `{alias}` | role |\n')
    failures, _, stats = MOD.check_report(text, 'x', (), baseline={})
    assert failures == []
    assert stats['ram_checked'] == 1


def test_symbol_led_peripheral_row_counts_as_io():
    text = _report('| `PEDR_W` 0xfffff754 | port expander data | bit0 = pump relay |')
    failures, _, stats = MOD.check_report(text, 'x', (), baseline={})
    assert failures == []
    assert stats['map_rows'] == 1 and stats['io_rows'] == 1


def test_grouped_row_is_counted_not_failed():
    text = _report('| `0xffffa6a0`/`0xffffa6a2` | paired cells, one descriptor |',
                   '| 0xffffa700 … 0xffffa70f | block of axis cells |')
    failures, _, stats = MOD.check_report(text, 'x', (), baseline={})
    assert failures == []
    assert stats['map_rows'] == 2 and stats['grouped_rows'] == 2


def test_unnamed_dat_row_is_allowed():
    addr = _ram_free()
    text = _report(f'| 0x{addr} | `DAT_{addr}` | unnamed cell |')
    failures, _, stats = MOD.check_report(text, 'x', (), baseline={})
    assert failures == []
    assert stats['unnamed_rows'] == 1


def test_unbacked_ram_row_fails():
    addr = _ram_free()
    text = _report(f'| 0x{addr} | `some_invented_alias` | role |')
    failures, _, _ = MOD.check_report(text, 'x', (), baseline={})
    assert len(failures) == 1 and 'not in accepted_ram_aliases.tsv' in failures[0]


def test_misnamed_function_row_fails():
    addr, name = _fn_entry()
    text = _report(f'| 0x{addr} | `ref_somethingElse` | role |')
    failures, _, _ = MOD.check_report(text, 'x', (), baseline={})
    assert len(failures) == 1 and 'reported' in failures[0]


def test_ram_alias_disagreeing_with_tsv_is_a_conflict_not_a_failure():
    addr, alias = _ram_backed()
    text = _report(f'| 0x{addr} | `{alias}_something` | role |')
    failures, conflicts, stats = MOD.check_report(text, 'x', (), baseline={})
    assert failures == []
    assert stats['ram_checked'] == 1


def test_map_row_without_address_fails():
    text = _report('| cell described in prose 0x | `alias` | role |')
    failures, _, _ = MOD.check_report(text, 'x', (), baseline={})
    assert len(failures) == 1 and 'no 0x address' in failures[0]


def test_accounting_covers_every_row_kind():
    fn_addr, fn_name = _fn_entry()
    ram_addr, ram_alias = _ram_backed()
    data_addr = _data_addr()
    text = _report(f'| 0x{fn_addr} | `{fn_name}` | role |',
                   f'| 0x{ram_addr} | `{ram_alias}` | role |',
                   f'| 0x{data_addr} | tbl_lookup_descriptor | role |',
                   '| `PEDR_W` 0xfffff754 | port expander | role |')
    failures, _, stats = MOD.check_report(text, 'x', (), baseline={})
    assert failures == []
    assert stats['map_rows'] == 4
    assert stats['map_rows'] == (stats['fn_checked'] + stats['ram_checked']
                                 + stats['data_rows'] + stats['io_rows'])


def test_declared_debt_is_counted_and_never_fails():
    free = _ram_free()
    text = _report(f'| 0x{free} | `provisional_alias` | role |')
    baseline = {'x': {'ram': [free]}}
    failures, _, stats = MOD.check_report(text, 'x', (), baseline=baseline)
    assert failures == []
    assert stats['declared_unbacked'] == 1


def test_declared_conflict_is_reported_as_conflict():
    addr, _ = _ram_backed()
    text = _report(f'| 0x{addr} | `unmatched_alias` | role |')
    failures, conflicts, stats = MOD.check_report(text, 'x', (), baseline={'x': {'ram_conflict': [addr]}})
    assert failures == []
    assert stats['declared_unbacked'] == 1 and len(conflicts) == 1


def test_stale_ledger_entries_fail():
    ram_addr, _ = _ram_backed()
    stats = {'x': {'map_rows': 0, 'fn_checked': 0, 'ram_checked': 0, 'data_rows': 0, 'io_rows': 0}}
    stale_ram = MOD.stale_baseline_entries({'x': {'ram': [ram_addr]}}, stats)
    assert any('stale RAM entry' in f for f in stale_ram)
    stale_conflict = MOD.stale_baseline_entries({'x': {'ram_conflict': [_ram_free()]}}, stats)
    assert any('stale conflict entry' in f for f in stale_conflict)
    orphan = MOD.stale_baseline_entries({'gone/report.md': {'ram': [_ram_free()]}}, stats)
    assert any('stale report' in f for f in orphan)
