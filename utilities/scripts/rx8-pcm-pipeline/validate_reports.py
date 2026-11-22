#!/usr/bin/env python3
"""Validate the subsystem + labeling reports against the export and the raw ROM.

Checks every <subsystem>_report.md at the investigation root, every
labeling/<name>_report.md (10-section template: fueling_control_report.md) and
every docs/subsystem-logic/<name>_report.md (human-first template), for:
  - required sections present
  - ROM SHA-256 quoted in the header equals the actual ROM hash
  - every memory-map row classified *by its address* and resolved against a
    tracked label source - see below
  - ROM data claims of the form `0xADDR ... = VALUE` re-read from the ROM
  - all bare 6-8 hex digit 0x addresses within ROM bounds

Memory-map rows
---------------
A row is in map scope when it sits under a heading that mentions "memory map"
(its subsections inherit the scope) or under a bold **Functions** / **RAM** /
**ROM tables** sub-label. The address cell may be plain (``0x0002f890``), wrapped
(`` `0x0002f890` ``, ``**0x0002f890**``), written with extra leading zeros
(``0x0000563de``), or led by a register symbol (`` `PEDR_W` 0xfffff754 ``); 0x
width and leading zeros do not matter. The row is then classified by the address
itself, never by the heading:

  * 0xffffe000 and above      -> peripheral I/O window, counted, no alias check
  * 0xffff0000-0xffffdfff     -> RAM cell: the reported alias must appear in
                                 accepted_ram_aliases.tsv, integrated_names.json,
                                 or a per-subsystem label record under
                                 data/labels/<rom-id>/
  * below 0xffff0000 and the address is a function entry (function_index.tsv,
                                 accepted_function_aliases.tsv or a label
                                 record) -> the reported name must match one of
                                 those sources
  * any other ROM address      -> table / descriptor / axis / pool address,
                                 range checked only (contents are covered by
                                 extract_maps.py and the defs passes)

Allowed row forms that stay unresolved, each counted so the totals still add up:
  * grouped - one row naming several cells (`0xffffa6a0/a6a2`, `...`, a range,
    a base pointer) -> counted in grouped_rows
  * unnamed - the cell carries no alias yet, written `DAT_<addr>` (rule 6:
    `DAT_`/`FUN_` mean unnamed, address only) -> counted in unnamed_rows

Anything else that cannot be classified or resolved fails the run, so a map row
is never skipped silently. The per-report counts (map_rows against
fn_checked + ram_checked + data_rows + io_rows) are asserted to add up.

Debt ledger
-----------
A report whose backing label record does not exist yet may declare the exact
addresses in `report_map_baseline.json`: `ram` entries (no tracked alias at all)
and `ram_conflict` entries (a tracked alias exists but the report's name agrees
with none of them - the dual-labeled cells). Declared rows are counted in
`declared_unbacked`, and conflicts are also listed in `label_conflicts` so they
stay visible. The ledger may only shrink: an entry whose address now resolves,
whose conflict is gone, or whose report no longer exists fails the run as stale.

Writes metadata/report_validation.json; exits non-zero on any failure.
"""
from pathlib import Path
import csv, json, re, struct, sys, hashlib

from paths import b, base, rom_file, ROOT, INV  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
WS = b.parents[1]
ROM_PATH = WS / 'Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin'
ROM = ROM_PATH.read_bytes()
ROM_SHA = hashlib.sha256(ROM).hexdigest()

REPORTS_DIR = INV  # reports live in docs/investigations/<rom-id>/ in this repo
REPORTS = sorted(p.name for p in REPORTS_DIR.glob('*_report.md')) + \
    sorted('labeling/' + p.name for p in (REPORTS_DIR / 'labeling').glob('*_report.md'))
SUBSYS_DIR = ROOT / 'docs' / 'subsystem-logic'  # shared-logic reports, human-first format
SUBSYS_REPORTS = sorted(p.name for p in SUBSYS_DIR.glob('*_report.md'))
REQUIRED_SECTIONS = ['Executive summary', 'pseudocode', 'Labeling applied', 'Corrections',
                     'Files', 'Validation', 'Memory map', 'Limits']
SUBSYS_REQUIRED_SECTIONS = ['Introduction', 'How it works', 'pseudocode', 'Proof',
                            'Memory map', 'Validation', 'Limits']
ALL_REPORTS = [(rep, REPORTS_DIR, REQUIRED_SECTIONS, rep) for rep in REPORTS] + \
              [(rep, SUBSYS_DIR, SUBSYS_REQUIRED_SECTIONS, f'subsystem-logic/{rep}') for rep in SUBSYS_REPORTS]

BASELINE_PATH = Path(__file__).resolve().parent / 'report_map_baseline.json'
BASELINE = json.loads(BASELINE_PATH.read_text(encoding='utf-8')) if BASELINE_PATH.exists() else {}

index = {r['address']: r for r in csv.DictReader((b / 'decompiled/function_index.tsv').open(newline=''), delimiter='\t')}
fn_tsv = {}
for r in csv.DictReader((b / 'source_review/accepted_function_aliases.tsv').open(newline=''), delimiter='\t'):
    fn_tsv.setdefault(r['address'], []).append(r['alias'])
ram_tsv = {r['address']: r for r in csv.DictReader((b / 'source_review/accepted_ram_aliases.tsv').open(newline=''), delimiter='\t')}
manifest = json.loads((b / 'metadata/integrated_names.json').read_text())
idmap = manifest.get('identifier_map', {})

GROUPED_MARKS = ('\u2026', '/')  # one row naming several cells stays unresolved
SEPARATOR = re.compile(r'^\s*\|[\s:|-]+\|\s*$')


def norm_addr(text):
    """Normalize an address key ('0x0000563de', 'ffffd1ea', '563de') to 8 hex digits."""
    digits = re.sub(r'[^0-9a-fA-F]', '', str(text).lower())
    if not digits:
        return None
    try:
        return f'{int(digits, 16):08x}'
    except ValueError:
        return None


def load_records():
    """Per-subsystem label records: the aliases a report's own record already carries."""
    fn, ram = {}, {}
    labels = ROOT / 'data' / 'labels'
    if not labels.is_dir():
        return fn, ram
    for rom_dir in sorted(p for p in labels.iterdir() if p.is_dir() and p.name != 'cross_rom'):
        for jf in sorted(rom_dir.glob('*_labels.json')):
            try:
                rec = json.loads(jf.read_text(encoding='utf-8'))
            except (json.JSONDecodeError, OSError):
                continue
            for key, target in (('function_aliases', fn), ('functions', fn), ('ram_aliases', ram)):
                block = rec.get(key)
                if not isinstance(block, dict):
                    continue
                for addr, entry in block.items():
                    if not isinstance(entry, dict):
                        continue
                    alias = entry.get('alias') or entry.get('name')
                    key_addr = norm_addr(addr)
                    if alias and key_addr:
                        target.setdefault(key_addr, set()).add(alias)
    return fn, ram


rec_fn, rec_ram = load_records()


def resolved(addr, kind):
    """Every tracked alias for an address, from all sources."""
    if kind == 'ram':
        names = set(rec_ram.get(addr, set()))
        if addr in ram_tsv:
            names.add(ram_tsv[addr]['alias'])
        return names
    names = set(fn_tsv.get(addr, [])) | rec_fn.get(addr, set())
    if addr in index:
        have = index[addr]['name']
        names |= {have, have.removeprefix('candidate_')}
    return names


def is_function_entry(addr):
    return addr in index or addr in fn_tsv or addr in rec_fn


def norm_fn(addr, reported):
    """True when `reported` names function `addr` under any accepted naming."""
    have = index.get(addr, {}).get('name', '')
    if reported in (have, have.removeprefix('candidate_')):
        return True
    return reported in fn_tsv.get(addr, []) or reported in rec_fn.get(addr, set())


def split_row(line):
    return [c.strip() for c in line.strip().strip('|').split('|')]


def row_address(cell):
    """The 0x address a table cell carries, plus the form it is written in.

    Returns (address, form): 'plain' for a leading address (optionally wrapped in
    `code` or **bold**), 'symbol' for a register-table cell such as
    `PEDR_W` 0xfffff754, and 'grouped' when one cell names several addresses
    (0x51c8/0x51de, a list, a range).
    """
    lead = re.match(r'^[\s`*_~]*0x([0-9a-fA-F]{4,10})', cell)
    found = re.findall(r'0x([0-9a-fA-F]{4,10})', cell)
    if lead:
        grouped = len(found) > 1 or any(t in cell for t in ('/', '\u2026', 'range', 'base'))
        return norm_addr(lead.group(1)), ('grouped' if grouped else 'plain')
    if len(found) == 1:
        addr = norm_addr(found[0])
        if addr and int(addr, 16) >= 0xffffe000:
            return addr, 'symbol'
    if len(found) > 1:
        return norm_addr(found[0]), 'grouped'
    return None, None


def map_scope(headings, label):
    scope = f'{" ".join(headings)} {label}'.lower()
    return 'memory map' in scope or label.startswith(('function', 'ram', 'rom tables'))


def check_report(text, stat_key, required_sections=(), baseline=None):
    """Check one report's text; returns (failures, conflicts, stats)."""
    baseline = BASELINE if baseline is None else baseline
    failures, conflicts = [], []
    stats = {'map_rows': 0, 'fn_checked': 0, 'ram_checked': 0, 'data_rows': 0,
             'io_rows': 0, 'grouped_rows': 0, 'unnamed_rows': 0,
             'declared_unbacked': 0, 'rom_refs': 0, 'rom_claims': 0}
    for sec in required_sections:
        if sec.lower() not in text.lower():
            failures.append(f'{stat_key}: missing section {sec!r}')
    if ROM_SHA not in text:
        failures.append(f'{stat_key}: ROM SHA-256 not quoted or wrong')
    declared = baseline.get(stat_key, {}) if isinstance(baseline, dict) else {}

    headings = []  # [(level, text)] - a "memory map" heading governs its subsections
    label = ''     # bold sub-label inside a section, e.g. **Functions:** / **RAM:**
    lines = text.splitlines()
    for i, line in enumerate(lines):
        if line.startswith('#'):
            level = len(line) - len(line.lstrip('#'))
            headings = [h for h in headings if h[0] < level] + [(level, line.lower())]
            label = ''
            continue
        bold = re.match(r'^\s*\*\*([^*]{1,40})\*\*', line)
        if bold and not line.startswith('|'):
            label = bold.group(1).strip(' :').strip('*').lower()
            continue
        if not line.startswith('|'):
            continue
        cells = split_row(line)
        if len(cells) < 2 or set(cells[0]) <= set('-: '):
            continue
        if i + 1 < len(lines) and SEPARATOR.match(lines[i + 1]):
            continue  # header row of a table
        in_map = map_scope([h[1] for h in headings], label)
        addr, form = row_address(cells[0])
        if addr is None:
            if in_map and any('0x' in c.lower() for c in cells[:2]):
                failures.append(f'{stat_key}: memory-map row that carries no 0x address in '
                                f'its first cell: {line[:70]!r}')
            continue
        val = int(addr, 16)
        if in_map:
            stats['map_rows'] += 1
        if val >= 0xffffe000:
            stats['rom_refs'] += 1  # volatile peripheral I/O window, valid
            if in_map:
                stats['io_rows'] += 1
        elif val >= 0xffff0000:
            if not (0xffff6000 <= val <= 0xffffdfff):
                failures.append(f'{stat_key}: RAM address 0x{val:x} outside RAM window: {line[:60]!r}')
            stats['rom_refs'] += 1
        else:
            if val >= len(ROM):
                failures.append(f'{stat_key}: address 0x{val:x} out of ROM range: {line[:60]!r}')
                continue
            stats['rom_refs'] += 1

        name_m = re.search(r'`([^`]+)`', cells[1])
        name = name_m.group(1) if name_m else cells[1]
        grouped = form == 'grouped' or any(t in name for t in GROUPED_MARKS)
        unnamed = bool(re.match(r'^DAT_[0-9a-fA-F]{0,8}\b', name))

        if 0xffff0000 <= val < 0xffffe000:
            if not in_map:
                continue
            stats['ram_checked'] += 1
            if grouped:
                stats['grouped_rows'] += 1
                continue
            if unnamed:
                stats['unnamed_rows'] += 1
                continue
            names = resolved(addr, 'ram')
            if not names:
                mv = idmap.get('DAT_' + addr, '')
                if mv and any(part in mv for part in re.split(r'[/\u2026\s]+', name) if len(part) > 3):
                    continue
                if addr in declared.get('ram', []):
                    stats['declared_unbacked'] += 1
                    continue
                failures.append(f'{stat_key}: RAM 0x{addr} ({name}) not in accepted_ram_aliases.tsv, '
                                f'integrated_names or any label record')
            elif not any(name.startswith(n) or n in name for n in names):
                if addr in declared.get('ram_conflict', []):
                    stats['declared_unbacked'] += 1
                    conflicts.append(f'{stat_key}: RAM 0x{addr} reported {name!r}, '
                                     f'tracked aliases {sorted(names)}')
                    continue
                failures.append(f'{stat_key}: RAM 0x{addr} reported {name!r} != tracked aliases {sorted(names)}')
            elif addr in ram_tsv and ram_tsv[addr]['alias'] not in names:
                conflicts.append(f'{stat_key}: RAM 0x{addr} reported {name!r} while '
                                 f'accepted_ram_aliases.tsv says {ram_tsv[addr]["alias"]!r}')
        elif val < 0xffff0000:
            if not in_map:
                continue
            if is_function_entry(addr):
                stats['fn_checked'] += 1
                if grouped:
                    stats['grouped_rows'] += 1
                    continue
                if not norm_fn(addr, name):
                    if addr in declared.get('function', []):
                        stats['declared_unbacked'] += 1
                        continue
                    have = index.get(addr, {}).get('name', '')
                    failures.append(f'{stat_key}: function 0x{addr} reported {name!r} != index {have!r} '
                                    f'/ accepted {sorted(resolved(addr, "fn"))}')
            else:
                stats['data_rows'] += 1  # table/descriptor/axis/pool address: range check only

    for m in re.finditer(r'0x([0-9a-f]{6})[^\n]{0,60}?=\s*(\d+)\b', text):
        a, claimed = int(m.group(1), 16), int(m.group(2))
        if a + 2 <= len(ROM) and 0x6c000 <= a:  # data-area claims
            stats['rom_claims'] += 1
            w = struct.unpack('>H', ROM[a:a+2])[0]
            if w != claimed:
                failures.append(f'{stat_key}: ROM claim 0x{a:x} = {claimed} but ROM u16 = {w}')
    accounted = stats['fn_checked'] + stats['ram_checked'] + stats['data_rows'] + stats['io_rows']
    if accounted != stats['map_rows']:
        failures.append(f'{stat_key}: {stats["map_rows"] - accounted} memory-map row(s) went unclassified')
    return failures, conflicts, stats


def stale_baseline_entries(baseline, report_stats):
    """The debt ledger may only shrink: entries whose cause is gone must be pruned."""
    failures = []
    for stat_key, entry in baseline.items():
        if stat_key.startswith('_'):
            continue  # ledger comment keys
        if stat_key not in report_stats:
            failures.append(f'report_map_baseline.json: stale report {stat_key!r}')
            continue
        for addr in entry.get('ram', []):
            names = resolved(norm_addr(addr), 'ram')
            if names:
                failures.append(f'report_map_baseline.json: stale RAM entry {stat_key} 0x{addr} '
                                f'(now tracked as {sorted(names)})')
        both = set(entry.get('ram', [])) & set(entry.get('ram_conflict', []))
        for addr in sorted(both):
            failures.append(f'report_map_baseline.json: {stat_key} 0x{addr} listed as unbacked and as a conflict')
        for addr in entry.get('ram_conflict', []):
            if not resolved(norm_addr(addr), 'ram'):
                failures.append(f'report_map_baseline.json: stale conflict entry {stat_key} 0x{addr} '
                                f'(no tracked alias)')
        for addr in entry.get('function', []):
            key = norm_addr(addr)
            if key in index or fn_tsv.get(key) or rec_fn.get(key):
                failures.append(f'report_map_baseline.json: stale function entry {stat_key} 0x{addr}')
    return failures


def main():
    failures, conflicts, report_stats = [], [], {}
    for rep, base_dir, required_sections, stat_key in ALL_REPORTS:
        text = (base_dir / rep).read_text(encoding='utf-8', errors='replace')
        f, c, stats = check_report(text, stat_key, required_sections)
        failures += f
        conflicts += c
        report_stats[stat_key] = stats
    failures += stale_baseline_entries(BASELINE, report_stats)
    out = {'rom_sha256': ROM_SHA, 'reports': report_stats,
           'label_conflicts': conflicts, 'failures': failures,
           'result': 'PASS' if not failures else 'FAIL'}
    (b / 'metadata/report_validation.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps(out, indent=2))
    return 1 if failures else 0


if __name__ == '__main__':
    sys.exit(main())
