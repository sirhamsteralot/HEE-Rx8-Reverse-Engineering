#!/usr/bin/env python3
"""Audit all 53 `thunk`-named functions and relabel them per the label ladder (idempotent).

ROADMAP C item 19. The 53 rows in rx8defs-analysis/function_labels.tsv carrying a
`thunk` name are NOT "unknown indirect call" markers: 51 are Ghidra auto-named
single-jump functions (14 x 4-byte `bra <target>` + 37 x 6-byte
`mov.l @(pool,pc),r3; jmp @r3`), whose jump target is fixed and ROM-provable;
0x35d36 is a 14-byte `jsr @r14` whose r14 is loaded once by its sole caller
0x35a8c from pool 0x35b74 = 0x00037ea4 (e2ram_shadow_byte_write); 0x5fd3c is a
conditional tail-jump already resolved as dtc_set_fault_xdefault by
review_dtc_thunk_labels.py.

This script re-derives every body and target from the raw ROM bytes (big-endian
SH-2E word decode, no disassembly parsing), then:

  1. replaces the 0x35d36 TSV row (e2ram_write_thunk/medium ->
     e2ram_shadow_byte_write_trampoline/high) in accepted_function_aliases.tsv;
  2. appends a high-confidence `jump_to_<target>` row for each of the 50 generic
     thunk functions (0x5fd3c and 0x576c2 keep their existing high aliases);
  3. writes metadata/thunk_audit_labels.json with all 53 records;
  4. moves 0x35d36 from kept_candidate to promoted_to_high in
     metadata/candidate_promotions.json;
  5. updates metadata/source_review/validation.json.

Runs after review_candidate_promotions.py and before annotate_source_review.py in
scripts/rebuild.sh. The raw ROM is never written; its SHA-256 is asserted unchanged.
"""
from pathlib import Path
import csv, hashlib, json, re, struct, sys

from paths import b, base, rom_file, ROOT, INV  # legacy-layout shim (paths.py)
BASIS = 'source_review_thunk_audit'

ROM_SHA256 = "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1"
ROM2 = ROOT / 'submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E0FC00.bin'

# addresses that already carry a proven high alias from another pass - keep them
KEEP_EXISTING = {'0005fd3c', '000576c2'}
# the one register-indirect thunk: sole caller fixes r14
JSR_THUNK = '00035d36'
JSR_ALIAS = 'e2ram_shadow_byte_write_trampoline'
OLD_ALIAS = 'e2ram_write_thunk'


def read_rows(path, fields):
    if not path.exists():
        return []
    text = path.read_text(encoding='utf-8', errors='surrogateescape')
    lines = text.split('\n')
    rows = []
    rdr = csv.DictReader(lines, delimiter='\t')
    for raw, row in zip(lines[1:], rdr):
        if raw == '' and all(v in (None, '') for v in row.values()):
            continue
        row = {k: (v if v is not None else '') for k, v in row.items()}
        row['_raw'] = raw
        rows.append(row)
    return rows


def write_rows(path, fields, rows):
    with path.open('w', newline='', encoding='utf-8', errors='surrogateescape') as f:
        f.write('\t'.join(fields) + '\n')
        for r in rows:
            raw = r.get('_raw')
            if raw is not None:
                f.write(raw + '\n')
            else:
                f.write('\t'.join(r.get(k, '') for k in fields) + '\n')


def u16(rom, a):
    return struct.unpack('>H', rom[a:a + 2])[0]


def u32(rom, a):
    return struct.unpack('>I', rom[a:a + 4])[0]


def sgn12(w):
    return w - 0x1000 if w & 0x800 else w


def main():
    rom = rom_file().read_bytes()
    assert hashlib.sha256(rom).hexdigest() == ROM_SHA256, 'ROM hash changed - refusing to run'

    index = {r['address']: r for r in read_rows(b / 'decompiled/function_index.tsv',
                                                 ['address', 'name', 'body_bytes', 'status', 'file'])}
    accepted = {r['address']: r for r in read_rows(b / 'source_review/accepted_function_aliases.tsv',
                                                   ['address', 'alias', 'confidence', 'evidence'])}
    callers = {}
    for r in read_rows(b / 'decompiled/callgraph.tsv', ['caller', 'callee', 'callee_name']):
        callers.setdefault(r['callee'], []).append(r['caller'])

    thunk_rows = [r for r in read_rows(INV / 'labeling/rx8defs-analysis/function_labels.tsv',
                                       ['address', 'name', 'body_bytes', 'source', 'file'])
                  if 'thunk' in r['name'].lower()]
    assert len(thunk_rows) == 53, 'expected 53 thunk rows, got %d' % len(thunk_rows)
    thunk_addr_set = {r['address'] for r in thunk_rows}

    records = []
    classes = {'bra': 0, 'pool_jmp': 0, 'jsr_reg': 0, 'other': 0}
    for tr in thunk_rows:
        addr = int(tr['address'], 16)
        blen = int(tr['body_bytes'])
        old_name = tr['name']
        w = [u16(rom, addr + 2 * i) for i in range(blen // 2)]
        call_list = sorted(callers.get(tr['address'], []))
        call_txt = ('callers in callgraph: ' + ', '.join('0x' + c for c in call_list)) if call_list \
            else 'no callgraph callers (vector/dispatch-table entry only)'

        if addr == 0x35d36:
            # jsr @r14 ; nop ; lds.l pr ; pop r12 ; pop r13 ; rts ; pop r14
            assert w == [0x4e0b, 0x0009, 0x4f26, 0x6cf6, 0x6df6, 0x000b, 0x6ef6], \
                '0x35d36 body changed: %s' % [hex(x) for x in w]
            # sole caller 0x35a8c loads r14 exactly once, from pool 0x35b74
            assert u16(rom, 0x35a94) == 0xde37, 'r14 load at 0x35a94 changed'
            pool = ((0x35a94 + 4) & ~3) + (0x37) * 4
            assert pool == 0x35b74
            target = u32(rom, pool)
            assert target == 0x37ea4, 'pool 0x35b74 = 0x%08x, expected 0x00037ea4' % target
            # no other write to r14 between the load and the jsr sites in 0x35a8c's body
            disasm = (b / 'disassembly/firmware_disassembly.asm').read_text(errors='surrogateescape')
            lines = disasm.splitlines()
            start = next(i for i, ln in enumerate(lines) if re.match(r'^00035a8c\s', ln))
            end = next(i for i, ln in enumerate(lines) if re.match(r'^00035d36\s', ln))
            r14_writes = [ln for ln in lines[start:end]
                          if re.search(r',r14\s*$', ln) and 'mov.l r14,@-r15' not in ln]
            assert len(r14_writes) == 1 and r14_writes[0].startswith('00035a94'), r14_writes
            assert rom[0x35d36:0x35d44] == ROM2.read_bytes()[0x36456:0x36464], \
                'cross-ROM byte match with 60E0FC00 0x36456 failed'
            tname = accepted['00037ea4']['alias']
            ev = ("14-byte body (words %s at 0x35d36, ROM-verified; byte-exact match with "
                  "60E0FC00 0x36456): `jsr @r14; nop; lds.l @r15+,pr; mov.l @r15+,r12; "
                  "mov.l @r15+,r13; rts; mov.l @r15+,r14`. Sole caller 0x35a8c loads r14 exactly "
                  "once, at 0x35a94 `mov.l @(0x35b74,pc),r14` with pool 0x35b74 = 0x00037ea4 "
                  "(%s), and all 14 dispatch arms `bra 0x35d36`; the epilogue pops the frame "
                  "0x35a8c pushed (r14/r13/r12/pr), so this is a tail-call trampoline to %s "
                  "0x37ea4, not an unknown indirect call. Target proven -> promoted from "
                  "candidate_ to a high-confidence label; inherited ref_writeToE2RAMAreaTHUNK_"
                  " was a misnomer (the real ref_writeToE2RAMArea_INDEX_ADDR_LEN is 0x37ea4)."
                  ) % (' '.join('%04x' % x for x in w), tname, tname)
            classes['jsr_reg'] += 1
            records.append(dict(address=tr['address'], old_name=old_name, cls='jsr_reg',
                                target='00037ea4', target_name=tname, alias=JSR_ALIAS,
                                confidence='high', evidence=ev))
            continue

        if blen == 4 and (w[0] & 0xf000) == 0xa000:
            target = addr + 4 + sgn12(w[0] & 0xfff) * 2
            cls = 'bra'
            detail = '4-byte body: word 0x%04x = `bra 0x%x` + delay-slot word 0x%04x' % (w[0], target, w[1])
            pool = None
        elif blen == 6 and (w[0] & 0xff00) == 0xd300 and w[1] == 0x432b and w[2] == 0x0009:
            pool = ((addr + 4) & ~3) + (w[0] & 0xff) * 4
            target = u32(rom, pool)
            cls = 'pool_jmp'
            detail = ('6-byte body: word 0x%04x = `mov.l @(0x%x,pc),r3`, 0x432b = `jmp @r3`, '
                      '0x0009 nop; pool 0x%x = 0x%08x (ROM-verified, big-endian)'
                      ) % (w[0], pool, pool, target)
        else:
            cls = 'other'
            target = None
            pool = None
            detail = 'body words: ' + ' '.join('%04x' % x for x in w)

        classes[cls] += 1
        taddr = '%08x' % target if target else None
        trow = accepted.get(taddr) if taddr else None
        tname = index.get(taddr, {}).get('name', '') if taddr else ''
        if taddr in thunk_addr_set:
            # target is itself an audited thunk: cite its address (stable before/after integration)
            tlabel = '0x%s' % taddr
        elif trow:
            tlabel = trow['alias']
        elif tname:
            tlabel = tname
        elif target:
            tlabel = '0x%08x' % target
        else:
            tlabel = None
        if tr['address'] in KEEP_EXISTING:
            assert cls == 'other' or taddr, 'unexpected kept row %s' % tr['address']
            keep = accepted[tr['address']]
            records.append(dict(address=tr['address'], old_name=old_name, cls=cls,
                                target=taddr, target_name=tlabel,
                                alias=keep['alias'], confidence=keep['confidence'],
                                evidence='Kept existing high-confidence alias %s (proven by the DTC '
                                         'thunk-cluster pass / diag22 pass): %s' % (keep['alias'], keep['evidence']),
                                kept=True))
            continue
        alias = 'jump_to_' + tlabel
        ev = ('%s (ROM-verified at 0x%s). Direct tail-jump to `%s` 0x%08x; %s. Upstream name '
              '`%s` is Ghidra\'s mechanical thunk auto-name (single-jump function), not a semantic '
              'label and not an uncertainty marker - the target is proven from the bra displacement '
              'resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).'
              ) % (detail, tr['address'], tlabel, target, call_txt, old_name)
        records.append(dict(address=tr['address'], old_name=old_name, cls=cls,
                            target=taddr, target_name=tlabel, alias=alias,
                            confidence='high', evidence=ev))

    assert classes == {'bra': 14, 'pool_jmp': 37, 'jsr_reg': 1, 'other': 1}, classes

    # 1+2. TSV: replace the jsr-thunk row, append the generic jump_to_* rows
    p = b / 'source_review/accepted_function_aliases.tsv'
    fields = ['address', 'alias', 'confidence', 'evidence']
    rows = read_rows(p, fields)
    existing = {r['address']: r for r in rows}
    added = replaced = 0
    conflicts = []
    for rec in records:
        a = rec['address']
        if rec.get('kept'):
            continue
        if a in existing:
            old = existing[a]
            if old['alias'] == rec['alias'] and old['confidence'] == rec['confidence']:
                continue  # already applied
            if a == JSR_THUNK and old['alias'] == OLD_ALIAS:
                old['alias'] = rec['alias']
                old['confidence'] = rec['confidence']
                old['evidence'] = rec['evidence']
                old['_raw'] = None
                replaced += 1
                continue
            conflicts.append('function %s: have %s, want %s' % (a, old['alias'], rec['alias']))
            continue
        rows.append({'address': a, 'alias': rec['alias'], 'confidence': rec['confidence'],
                     'evidence': rec['evidence'], '_raw': None})
        added += 1
    if conflicts:
        for c in conflicts:
            print('CONFLICT:', c, file=sys.stderr)
        raise SystemExit('alias conflicts; resolve before rerunning')
    if added or replaced:
        write_rows(p, fields, rows)

    # 3. labels JSON
    record = {
        'basis': BASIS,
        'finding': ('All 53 `thunk`-named rows audited at binary level: 51 are Ghidra auto-named '
                    'single-jump functions (14 x `bra` + 37 x pool `jmp @r3`) with ROM-proven fixed '
                    'targets, renamed to jump_to_<target>; 0x35d36 is a `jsr @r14` trampoline whose '
                    'sole caller 0x35a8c fixes r14 = pool 0x35b74 = 0x00037ea4 (e2ram_shadow_byte_write), '
                    'promoted to e2ram_shadow_byte_write_trampoline (high); 0x5fd3c keeps '
                    'dtc_set_fault_xdefault and 0x576c2 keeps diag22_pidc116_dtc_state_machine. '
                    '"thunk" upstream = Ghidra single-jump auto-name, not an "unknown call" marker.'),
        'classes': classes,
        'functions': records,
        'added_this_run': added,
        'replaced_this_run': replaced,
        'rom_sha256': ROM_SHA256,
        'rom_unchanged': True,
        'ghidra_database_updated': False,
    }
    out = b / 'metadata/thunk_audit_labels.json'
    out.write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8', errors='surrogateescape')

    # 4. candidate_promotions.json: move 0x35d36 to promoted_to_high
    cp = b / 'metadata/candidate_promotions.json'
    if cp.exists():
        cpj = json.loads(cp.read_text(encoding='utf-8', errors='surrogateescape'))
        if JSR_THUNK in cpj.get('kept_candidate', {}):
            del cpj['kept_candidate'][JSR_THUNK]
        cpj.setdefault('promoted_to_high', {})[JSR_THUNK] = {
            'alias': JSR_ALIAS, 'name': JSR_ALIAS,
            'source': 'thunk audit: sole caller 0x35a8c fixes r14 = 0x37ea4 (pool 0x35b74)'}
        counts = cpj.get('counts')
        if isinstance(counts, dict):
            counts['promoted'] = len(cpj['promoted_to_high'])
            counts['kept_candidate'] = len(cpj['kept_candidate'])
            counts['candidate_total'] = (counts['promoted'] + counts.get('renamed', 0)
                                         + counts['kept_candidate'])
        cp.write_text(json.dumps(cpj, indent=2) + '\n', encoding='utf-8', errors='surrogateescape')

    # 5. validation.json
    vp = b / 'source_review/validation.json'
    val = json.loads(vp.read_text(encoding='utf-8', errors='surrogateescape')) if vp.exists() else {
        'date': '', 'function_annotations': 0, 'ram_aliases': 0,
        'ghidra_database_updated': False, 'sources': []}
    val['function_annotations'] = len(read_rows(p, fields))
    if BASIS not in val.get('sources', []):
        val.setdefault('sources', []).append(BASIS)
    vp.write_text(json.dumps(val, indent=2) + '\n', encoding='utf-8', errors='surrogateescape')

    print(json.dumps({'thunk_rows': len(records), 'classes': classes,
                      'added_function_aliases': added, 'replaced_function_aliases': replaced,
                      'record': str(out)}))


if __name__ == '__main__':
    main()
