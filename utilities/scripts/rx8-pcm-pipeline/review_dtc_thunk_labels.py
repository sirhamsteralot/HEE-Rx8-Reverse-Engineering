#!/usr/bin/env python3
"""Append reviewed DTC set-fault thunk-cluster aliases to the curated TSV (idempotent).

Verifies the 0x5fd38/0x5fd3c/0x5fd4a cluster at the binary level and promotes the
labels: these are direct tail-call trampolines / a plain setter, NOT indirect-call
stubs, so the "thunk = uncertainty" reading does not apply here.

  0x5fd38 FUN_0005fd38                  -> dtc_set_fault_x0
  0x5fd3c ref_updateFaultStatusTHUNKNoR6_ -> dtc_set_fault_xdefault
  0x5fd4a FUN_0005fd4a                  -> dtc_set_eval_enable

Runs after review_dsc_can_labels.py and before annotate_source_review.py in
scripts/rebuild.sh. Also writes metadata/dtc_thunk_labels.json.
"""
from pathlib import Path
import csv, json, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py)
BASIS = 'source_review_dtc_thunks'

FUNCTIONS = [
    # address, alias, confidence, evidence
    ("0005fd38", "dtc_set_fault_x0", "high",
     "Body is `bra 0x5fe20` with delay slot `mov #0,r6` (words a072/e600 at 0x5fd38/0x5fd3a, ROM-verified): a direct tail-call trampoline to dtc_set_fault 0x5fe20 with param_3 (r6, the x ORed into first-stored-code 0xffffd3c0 by 0x601cc) fixed to 0. 0x5fe20's only callers are the two trampolines 0x5fd38/0x5fd3c (callgraph); 0x5fd38 has 71 monitor callers. Not an indirect call, so no candidate_ prefix: the target is proven exact."),
    ("0005fd3c", "dtc_set_fault_xdefault", "high",
     "Entry 0x5fd3c: extu.w r6,r3; tst r3,r3; bf/s skip; mov.l @(0x5fe0c,pc),r6 where pool 0x5fe0c = 0x0000ffff; then bra 0x5fe20 (a06b at 0x5fd46): trampoline to dtc_set_fault with x defaulted to 0xffff when the caller passes r6==0. 2 callers (0x44724, 0x44cec), both computing r6 from flag bits before the call (jsr via pool words 0x447ac/0x44d54). Inherited ref_updateFaultStatusTHUNKNoR6_ is a misnomer: the body is set_fault, not a fault-status update; 'NoR6' = trampoline for callers that leave r6 unset."),
    ("0005fd4a", "dtc_set_eval_enable", "high",
     "Entry 0x5fd4a: extu.b r4; r5 = pool 0x5fe10 = 0xffffd688 (dtc_eval_enable RAM); r4==1 -> mov.b #1,@r5; r4==0 -> mov.b #0,@r5; rts (000b at 0x5fd68). Plain setter of the global DTC eval-enable flag, not a thunk. Callers: 0x5fd6c (boot DTC RAM init sets 1) and 0x5dde8 (UDS 0x85 control-DTC-setting path, handler 0x5dc44)."),
]


def read_rows(path, fields):
    if not path.exists():
        return []
    with path.open(newline='', encoding='utf-8', errors='surrogateescape') as f:
        text = f.read()
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


def main():
    index = {r['address'] for r in read_rows(b / 'decompiled/function_index.tsv',
                                             ['address', 'name', 'body_bytes', 'status', 'file'])}
    for a, alias, conf, ev in FUNCTIONS:
        assert a in index, 'function %s not in index' % a

    p = b / 'source_review/accepted_function_aliases.tsv'
    rows = read_rows(p, ['address', 'alias', 'confidence', 'evidence'])
    existing = {r['address']: r for r in rows}
    added, conflicts = 0, []
    for a, alias, conf, ev in FUNCTIONS:
        if a in existing:
            if existing[a]['alias'] != alias:
                conflicts.append('function %s: have %s, want %s' % (a, existing[a]['alias'], alias))
            continue
        rows.append({'address': a, 'alias': alias, 'confidence': conf, 'evidence': ev, '_raw': None})
        added += 1
    if conflicts:
        for c in conflicts:
            print('CONFLICT:', c, file=sys.stderr)
        raise SystemExit('alias conflicts; resolve before rerunning')
    if added:
        write_rows(p, ['address', 'alias', 'confidence', 'evidence'], rows)

    vp = b / 'source_review/validation.json'
    val = json.loads(vp.read_text()) if vp.exists() else {
        'date': '', 'function_annotations': 0, 'ram_aliases': 0,
        'ghidra_database_updated': False, 'sources': []}
    val['function_annotations'] = len(read_rows(p, ['address', 'alias', 'confidence', 'evidence']))
    if BASIS not in val.get('sources', []):
        val.setdefault('sources', []).append(BASIS)
    vp.write_text(json.dumps(val, indent=2) + '\n', encoding='utf-8', errors='surrogateescape')

    record = {
        'basis': BASIS,
        'finding': '0x5fd38/0x5fd3c are direct tail-call trampolines to dtc_set_fault 0x5fe20 '
                   '(x fixed to 0 / defaulted to 0xffff), not indirect-call stubs; 0x5fd4a is a '
                   'plain setter of dtc_eval_enable 0xffffd688. Inherited ref_updateFaultStatusTHUNKNoR6_ '
                   'misnomer replaced by proven semantic names.',
        'functions': [{'address': a, 'alias': al, 'confidence': c, 'evidence': ev}
                      for a, al, c, ev in FUNCTIONS],
        'added_this_run': added,
        'ghidra_database_updated': False,
    }
    out = b / 'metadata' / 'dtc_thunk_labels.json'
    out.write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8', errors='surrogateescape')
    print(json.dumps({'added_function_aliases': added, 'record': str(out)}))


if __name__ == '__main__':
    main()
