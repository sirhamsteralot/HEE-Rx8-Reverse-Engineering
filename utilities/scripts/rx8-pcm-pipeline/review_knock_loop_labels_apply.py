#!/usr/bin/env python3
"""Post-integration knock/loop labeling pass (idempotent).

Runs after integrate_reviewed_names.py and the refine passes in
scripts/rebuild.sh, because refine_readability.py would re-introduce the
0x13bd2 export bug on a fresh rebuild. Three jobs:

1. Fix the 0x13bd2 export bug in all three synchronized views: the function
   returns the rx8_clamp_float result (SH fr0), but was exported as void with
   the call result discarded. Disassembly 0x13bd2-0x13c26: fr4 (param) saved at
   0x13be2, min lookup -> fr14 (0x13c0a), max lookup 0x6af90 -> fr6 (0x13c12),
   jsr rx8_clamp_float (0x2404) at 0x13c18 with delay slot fmov.s @r15,fr4
   restoring fr4=param, fr5=min, fr6=max; rts at 0x13c24 returns fr0.
2. Rename snapshot_ locals of renamed RAM globals (snapshot_DAT_ffffa750 ->
   snapshot_coolant_timing_derate_leading_ffffa750); the integrator's
   word-boundary rename does not touch them because '_' is a word character.
3. Write metadata/knock_loop_labels.json recording the pass.
"""
from pathlib import Path
import csv, json, re

b = Path(__file__).resolve().parents[1]


def fn_file():
    matches = sorted((b / 'decompiled/functions').glob('00013bd2_*.c'))
    assert len(matches) == 1, 'expected one 0x13bd2 function file, found %s' % matches
    return matches[0]


def views():
    yield fn_file()
    yield b / 'decompiled/firmware_decompiled.c'
    yield b / 'named/firmware_named.c'


def fix_13bd2(path):
    s = path.read_text()
    fixed_sig = re.subn(r'\bvoid (FUN_00013bd2|knock_retard_clamp)\(float param_1\)',
                        r'float \1(float param_1)', s)
    if fixed_sig[1] == 0:
        assert re.search(r'\bfloat (FUN_00013bd2|knock_retard_clamp)\(float param_1\)', s), \
            '0x13bd2 signature not found in %s' % path
        fixed_sig = (s, 0)
    s = fixed_sig[0]
    old = '  rx8_clamp_float(param_1,arg1,arg2);\n  return;\n'
    new = '  return rx8_clamp_float(param_1,arg1,arg2);\n'
    if old in s:
        assert s.count(old) == 1, 'ambiguous clamp call in %s' % path
        s = s.replace(old, new)
        ret_fixed = 1
    else:
        assert s.count(new) == 1, 'clamp return not found in %s' % path
        ret_fixed = 0
    path.write_text(s)
    return fixed_sig[1], ret_fixed


def snapshot_renames():
    mapping = {}
    with (b / 'source_review/accepted_ram_aliases.tsv').open(newline='') as f:
        for r in csv.DictReader(f, delimiter='\t'):
            old = 'snapshot_DAT_' + r['address']
            new = 'snapshot_' + r['alias'] + '_' + r['address']
            mapping[old] = new
    return mapping


def main():
    sig_fixes = ret_fixes = 0
    for p in views():
        s, r = fix_13bd2(p)
        sig_fixes += s
        ret_fixes += r

    # Rename snapshot_ locals in every synchronized view.
    smap = snapshot_renames()
    targets = list((b / 'decompiled/functions').glob('*.c')) + [
        b / 'decompiled/firmware_decompiled.c', b / 'named/firmware_named.c']
    renames = {}
    total = 0
    for old, new in sorted(smap.items(), key=lambda kv: -len(kv[0])):
        pat = re.compile(r'\b' + re.escape(old) + r'\b')
        for p in targets:
            s = p.read_text()
            s, n = pat.subn(new, s)
            if n:
                p.write_text(s)
                renames[old] = {'new': new, 'occurrences': renames.get(old, {}).get('occurrences', 0) + n}
                total += n

    # The per-function 0x13bd2 body must occur intact in both combined views.
    body = fn_file().read_text()
    anchor = '/* ROM address: 0x00013bd2;'
    tail = body[body.index(anchor):].strip()
    for p in (b / 'decompiled/firmware_decompiled.c', b / 'named/firmware_named.c'):
        assert tail in p.read_text(), '0x13bd2 body not intact in %s' % p

    with (b / 'source_review/accepted_function_aliases.tsv').open(newline='') as f:
        fn_rows = list(csv.DictReader(f, delimiter='\t'))
    with (b / 'source_review/accepted_ram_aliases.tsv').open(newline='') as f:
        ram_rows = list(csv.DictReader(f, delimiter='\t'))
    with (b / 'source_review/accepted_lookup_aliases.tsv').open(newline='') as f:
        lut_rows = list(csv.DictReader(f, delimiter='\t'))

    record = {
        'date': '2026-10-29',
        'pass': 'knock_control_and_loop_mode_labeling',
        'function_aliases': {r['address']: {'alias': r['alias'], 'confidence': r['confidence']}
                             for r in fn_rows if r['address'] in {
                                 '00013826', '0001388a', '000138b2', '000139c4', '00013a60', '00013b40',
                                 '00013bd2', '000125bc', '000125f6', '000123ba', '000123ca', '00011f00',
                                 '0001206c', '00049fac', '0004a084', '000336c4', '00033632', '00033970',
                                 '000335e4', '0000c486', '0000c8dc', '0000c3ce', '0000c276', '0000c116',
                                 '000339ea', '0001c13c', '0001f0c4', '0001ee30', '0001ee4a', '0005535e',
                                 '000553d8', '000142a4', '000145c8', '000390b8', '000064ba', '0001467c',
                                 '00013034', '0003d010', '00022144'}},
        'ram_aliases': {r['address']: {'alias': r['alias'], 'type': r['type'], 'reader': r['reader']}
                        for r in ram_rows},
        'lookup_aliases': {r['original']: r['alias'] for r in lut_rows},
        'fix_00013bd2': {
            'address': '00013bd2',
            'before': 'void FUN_00013bd2(float param_1) { ... rx8_clamp_float(param_1,arg1,arg2); return; }',
            'after': 'float FUN_00013bd2(float param_1) { ... return rx8_clamp_float(param_1,arg1,arg2); }',
            'disassembly': ('0x13bd2-0x13c26: fr4 (param) saved 0x13be2; descriptor select 0x6af7c/0x6af68; '
                            'min lookup -> fr14 (0x13c0a); max lookup 0x6af90 -> fr6 (0x13c12); '
                            'jsr rx8_clamp_float (0x2404) at 0x13c18, delay slot fmov.s @r15,fr4 restores '
                            'fr4=param, fr5=min, fr6=max; rts 0x13c24 returns fr0 = clamp result (SH float return)'),
            'callers': ['000139c4', '00013a60', '00013b40'],
            'signature_replacements': sig_fixes,
            'return_replacements': ret_fixes,
            'views': ['decompiled/functions/00013bd2_FUN_00013bd2.c',
                      'decompiled/firmware_decompiled.c', 'named/firmware_named.c'],
        },
        'snapshot_local_renames': renames,
        'snapshot_local_rename_total': total,
        'misnomer_corrections': {
            '0001ee30': {'old': 'ref_setClosedLoopBool', 'new': 'set_open_loop_flag',
                         'note': 'sets the OPEN-loop flag b12c = (b12a != 0); blocks closed loop in 0x1c13c'},
            '0000c116': {'old': 'ref_enableDisableCruiseControl__', 'new': 'reset_knock_state_on_mode_change',
                         'note': 'only resets knock rotor index / detection state on mode change'},
        },
        'polarity_correction': {
            'ffffb12a': 'open_loop_request (set by 0x1f0c4 from closed-loop fuelling threshold tables)',
            'ffffb12c': 'open_loop_active = (b12a != 0), set by 0x1ee30; 1 = open loop, blocks closed loop',
            'note': 'earlier sessions labeled b12a/b12c as closed-loop flags; OBD PID 0x0003 handler 0x568ca and the 0x1c13c/0x1ee4a logic establish the opposite polarity',
        },
        'backup': 'backups/pre_knock_loop_labels.zip',
        'rom_unchanged': True,
        'ghidra_database_updated': False,
    }
    (b / 'metadata/knock_loop_labels.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({
        'signature_fixes': sig_fixes,
        'return_fixes': ret_fixes,
        'snapshot_local_renames': len(renames),
        'snapshot_local_rename_total': total,
        'function_aliases_recorded': len(record['function_aliases']),
        'ram_aliases_recorded': len(record['ram_aliases']),
        'lookup_aliases_recorded': len(record['lookup_aliases']),
    }, indent=2))


if __name__ == '__main__':
    main()
