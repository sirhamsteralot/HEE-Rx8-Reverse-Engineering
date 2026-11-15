#!/usr/bin/env python3
"""Apply the ignition-key / power-state aliases to the already-integrated export (idempotent).

Runs after annotate_source_review.py in scripts/rebuild.sh, in place of a full
integrate_reviewed_names.py re-run (which is one-shot on a fresh export: its
assert requires old names still present). This pass renames only the
source_review_ignition_power_state rows in every synchronized view:

  - decompiled/functions/*.c, decompiled/firmware_decompiled.c, named/firmware_named.c
    (code parts only; provenance comments keep historical names, as the integrator does)
  - decompiled/function_index.tsv (name column), decompiled/callgraph.tsv (callee_name)
  - decompiled/symbols.tsv (DAT_ RAM labels -> alias_address)
  - metadata/integrated_names.json (identifier_map extended)
  - snapshot_DAT_<addr> locals -> snapshot_<alias>_<addr>

Medium-confidence aliases get the candidate_ prefix, matching the integrator.
"""

from pathlib import Path
import csv, json, re, sys

from paths import b, base, rom_file, ROOT

BASIS = 'source_review_ignition_power_state'


def rows(p):
    return list(csv.DictReader((b / p).open(encoding='utf-8', errors='surrogateescape'), delimiter='\t'))


def write_tsv(p, rs, fields):
    with (b / p).open('w', encoding='utf-8', errors='surrogateescape', newline='') as f:
        w = csv.DictWriter(f, fieldnames=fields, delimiter='\t')
        w.writeheader()
        w.writerows(rs)


def main():
    fn = {}
    for r in rows('source_review/accepted_function_aliases.tsv'):
        if r.get('confidence') == 'medium':
            fn[r['address']] = 'candidate_' + r['alias']
        else:
            fn[r['address']] = r['alias']
    ram = {r['address']: r['alias'] for r in rows('source_review/accepted_ram_aliases.tsv')}

    # Restrict to this pass's basis: re-derive from the pass's own labels JSON so a
    # later rename of the same address by another pass does not get double-applied.
    record = json.loads((b / 'metadata/ignition_power_state_labels.json').read_text(encoding='utf-8', errors='surrogateescape'))
    my_fn = {a: ('candidate_' if e['confidence'] == 'medium' else '') + e['alias']
             for a, e in record['function_aliases'].items()}
    my_ram = {a: e['alias'] for a, e in record['ram_aliases'].items()}

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
    # Pending thunk renames: a jump_to_* thunk whose target was relabeled by this
    # pass must be renamed too (its name embeds the old target name after '_',
    # which the \b-anchored pattern cannot reach).
    for r in rows('source_review/accepted_function_aliases.tsv'):
        a = r['address']
        if a not in byaddr or not byaddr[a]['name'].startswith('jump_to_'):
            continue
        want = ('candidate_' if r['confidence'] == 'medium' else '') + r['alias']
        if byaddr[a]['name'] != want:
            mapping[byaddr[a]['name']] = want
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
    for rel in ('decompiled/firmware_decompiled.c', 'named/firmware_named.c'):
        p = b / rel
        old = p.read_text(encoding='utf-8', errors='surrogateescape')
        new = transform(old)
        if new != old:
            p.write_text(new, encoding='utf-8', errors='surrogateescape')
            changed += 1

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
    data['ignition_power_state_applied'] = True
    manifest.write_text(json.dumps(data, indent=2) + '\n', encoding='utf-8', errors='surrogateescape')

    # Sanity: every renamed function body now carries its new name in all three views.
    monolith = (b / 'decompiled/firmware_decompiled.c').read_text(encoding='utf-8', errors='surrogateescape')
    for a, new in my_fn.items():
        body = next((b / 'decompiled/functions').glob(a + '_*.c')).read_text(encoding='utf-8', errors='surrogateescape')
        assert re.search(r'\b' + re.escape(new) + r'\s*\(', body), a
        assert body in monolith or new in monolith, a

    print(json.dumps({'renames': len(mapping), 'views_changed': changed,
                      'functions': len(my_fn), 'ram': len(my_ram)}, indent=2))


if __name__ == '__main__':
    main()
