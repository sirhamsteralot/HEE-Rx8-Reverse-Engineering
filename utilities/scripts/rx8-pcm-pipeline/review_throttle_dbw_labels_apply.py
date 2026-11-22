#!/usr/bin/env python3
"""Apply the throttle/DBW aliases to the already-integrated export (idempotent).

Runs after review_throttle_dbw_labels.py in scripts/rebuild.sh, in place of a
full integrate_reviewed_names.py re-run (one-shot on a fresh export).
Restricted to the source_review_throttle_dbw rows recorded in
metadata/throttle_dbw_labels.json (function_aliases + ram_aliases +
ram_carried + the three corrections), it updates:

  - decompiled/functions/*.c, decompiled/firmware_decompiled.c, named/firmware_named.c
    (code parts only; provenance comments keep historical names) plus the
    [ADDITIONAL SOURCE REVIEW] comment block for each newly labeled function
  - decompiled/function_index.tsv (name column), decompiled/callgraph.tsv (callee_name)
  - decompiled/symbols.tsv (DAT_ RAM labels -> alias_address)
  - metadata/integrated_names.json (identifier_map extended)
  - snapshot_DAT_<addr> locals -> snapshot_<alias>_<addr>

Medium-confidence aliases get the candidate_ prefix, matching the integrator.
Run refine_comment_merge.py afterwards to re-canonicalize the comment blocks.
"""

from pathlib import Path
import csv, json, re, sys

from paths import b, base, rom_file, ROOT

BASIS = 'source_review_throttle_dbw'


def rows(p):
    return list(csv.DictReader((b / p).open(encoding='utf-8', errors='surrogateescape'), delimiter='\t'))


def write_tsv(p, rs, fields):
    with (b / p).open('w', encoding='utf-8', errors='surrogateescape', newline='') as f:
        w = csv.DictWriter(f, fieldnames=fields, delimiter='\t')
        w.writeheader()
        w.writerows(rs)


def main():
    record = json.loads((b / 'metadata/throttle_dbw_labels.json').read_text(encoding='utf-8', errors='surrogateescape'))
    my_fn = {a: ('candidate_' if e['confidence'] == 'medium' else '') + e['alias']
             for a, e in record['function_aliases'].items()}
    my_ram = {a: e['alias'] for a, e in record['ram_aliases'].items()}
    # corrections rename RAM aliases too
    for a, c in record.get('corrections', {}).items():
        my_ram[a] = c['new_alias']

    fn_rows = {r['address']: r for r in rows('source_review/accepted_function_aliases.tsv')}
    ram_rows = rows('source_review/accepted_ram_aliases.tsv')

    index = rows('decompiled/function_index.tsv')
    byaddr = {r['address']: r for r in index}
    mapping = {}
    for a, new in my_fn.items():
        old = byaddr[a]['name']
        if old != new:
            mapping[old] = new
    for a, alias in my_ram.items():
        mapping['DAT_' + a] = alias + '_' + a
        mapping['snapshot_DAT_' + a] = 'snapshot_' + alias + '_' + a
    # symbols.tsv rows keyed by address (their name may already be a renamed
    # alias with the _<addr> suffix, not DAT_<addr>): rename by address column.
    for r in rows('decompiled/symbols.tsv'):
        a = r['address'].lower()
        if a in my_ram and not r['name'].startswith(my_ram[a]):
            mapping[r['name']] = my_ram[a] + '_' + a
    # Pointer labels embedding an old function name after 'PTR_'.
    sym_names = {r['name'] for r in rows('decompiled/symbols.tsv')}
    for old, new in list(mapping.items()):
        for sn in sym_names:
            if sn.startswith('PTR_' + old):
                mapping[sn] = 'PTR_' + new + sn[len('PTR_' + old):]
    mapping = {k: v for k, v in mapping.items() if k != v}

    pattern = re.compile(r'\b(?:' + '|'.join(re.escape(k) for k in sorted(mapping, key=len, reverse=True)) + r')\b')

    def transform(s):
        parts = re.split(r'(/\*.*?\*/|//[^\n]*)', s, flags=re.S)
        for i in range(0, len(parts), 2):
            parts[i] = pattern.sub(lambda m: mapping[m[0]], parts[i])
        return ''.join(parts)

    changed = 0
    for p in (b / 'decompiled/functions').glob('*.c'):
        old = p.read_text(encoding='utf-8', errors='surrogateescape')
        new = transform(old)
        if new != old:
            p.write_text(new, encoding='utf-8', errors='surrogateescape')
            changed += 1
    monoliths = []
    for rel in ('decompiled/firmware_decompiled.c', 'named/firmware_named.c'):
        p = b / rel
        old = p.read_text(encoding='utf-8', errors='surrogateescape')
        new = transform(old)
        monoliths.append((p, old, new))
        if new != old:
            p.write_text(new, encoding='utf-8', errors='surrogateescape')
            changed += 1

    # [ADDITIONAL SOURCE REVIEW] comment blocks for the newly labeled functions.
    notes = {}
    for a, e in record['function_aliases'].items():
        r = fn_rows.get(a)
        lines = [e['alias'] + ' [' + e['confidence'] + ']: ' + (r['evidence'] if r else e['evidence'])]
        for rr in ram_rows:
            if rr['reader'] == a:
                lines.append('RAM 0x' + rr['address'] + ' ' + rr['alias'] + ' (' + rr['type'] + '): ' + rr['evidence'])
        notes[a] = lines
    patt = r'/\* \[ADDITIONAL SOURCE REVIEW\].*?\*/\n'
    for a, lines in notes.items():
        note = '/* [ADDITIONAL SOURCE REVIEW]\n * ' + '\n * '.join(lines) + '\n */\n'
        # per-function file: merge into an existing block (comment_merge re-canonicalizes)
        p = next((b / 'decompiled/functions').glob(a + '_*'))
        raw = patt and re.sub(patt, '', p.read_text(encoding='utf-8', errors='surrogateescape'), flags=re.S)
        p.write_text(note + raw, encoding='utf-8', errors='surrogateescape')
        for mp, old, new in monoliths:
            marker = '/* ROM address: 0x' + a + ';'
            assert new.count(marker) == 1, a
            new = new.replace(marker, note + marker)
            mp.write_text(new, encoding='utf-8', errors='surrogateescape')

    for r in index:
        if r['address'] in my_fn:
            r['name'] = my_fn[r['address']]
        r['name'] = mapping.get(r['name'], r['name'])
    write_tsv('decompiled/function_index.tsv', index,
              ['address', 'name', 'body_bytes', 'status', 'file'])

    calls = rows('decompiled/callgraph.tsv')
    for r in calls:
        if r['callee'] in my_fn:
            r['callee_name'] = my_fn[r['callee']]
        r['callee_name'] = mapping.get(r['callee_name'], r['callee_name'])
    write_tsv('decompiled/callgraph.tsv', calls, ['caller', 'callee', 'callee_name'])

    syms = rows('decompiled/symbols.tsv')
    for r in syms:
        r['name'] = mapping.get(r['name'], r['name'])
    write_tsv('decompiled/symbols.tsv', syms, ['address', 'name', 'type', 'source'])

    manifest = b / 'metadata/integrated_names.json'
    data = json.loads(manifest.read_text(encoding='utf-8', errors='surrogateescape'))
    data['identifier_map'] = {**data.get('identifier_map', {}), **mapping}
    data['throttle_dbw_applied'] = True
    manifest.write_text(json.dumps(data, indent=2) + '\n', encoding='utf-8', errors='surrogateescape')

    print(json.dumps({'renames': len(mapping), 'views_changed': changed,
                      'functions': len(my_fn), 'ram': len(my_ram),
                      'comment_blocks_added': len(notes)}, indent=2))


if __name__ == '__main__':
    main()
