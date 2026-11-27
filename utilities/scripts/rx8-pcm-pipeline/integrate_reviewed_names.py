#!/usr/bin/env python3
"""Integrate reviewed names into canonical C; retain address-based identity and provenance.

The identifier map is anchored on each function's **address identity**, not on the name
`function_index.tsv` happens to carry: for an accepted alias at 0x00026a42 the map
covers `FUN_00026a42` in both hex cases, the export-time stem of
`decompiled/functions/00026a42_FUN_00026a42.c`, and the name currently in the index.
A re-run over a half-renamed export therefore finishes the job instead of staying a
near no-op (its keys were consumed by the run that renamed the index).

`thunk_FUN_<target>` / `jump_to_FUN_<target>` embed the *target* address rather than
the thunk's own, so those forms are derived from the thunk row's stem
(`thunk_FUN_000270aa` -> `jump_to_<alias of the thunk>`) and never from the thunk's
own address: a thunk that carries no alias of its own keeps the export's target-derived
convention (`jump_to_<target alias>`), and a form two thunks share is left alone because
the substitution cannot tell their bodies apart. File names stay address-keyed
(`00028992_thunk_FUN_000270aa.c` is the stable export identity `validate_export.py`
matches against the index).

Run after the review passes and before refine_comment_merge.py (rebuild.sh).
Idempotent: a second run changes nothing, and the pass fails if any accepted alias is
still missing from the export.
"""
from pathlib import Path
import csv, json, re, zipfile

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo

# Address-based identifier forms. `FUN_`/`DAT_` name the row's own address; the thunk
# prefixes name the target, so they are mapped through the stem instead (see module doc).
ADDRESS_IDENT = re.compile(r'\b(jump_to_FUN_|thunk_FUN_|FUN_|DAT_)([0-9A-Fa-f]{8})\b')
COMMENT_SPLIT = re.compile(r'(/\*.*?\*/|//[^\n]*)', re.S)


def rows(p):
    return list(csv.DictReader((b / p).open(encoding='utf-8', errors='surrogateescape'), delimiter='\t'))


def write(p, rs):
    with (b / p).open('w', encoding='utf-8', errors='surrogateescape') as f:
        w = csv.DictWriter(f, fieldnames=list(rs[0]), delimiter='\t')
        w.writeheader()
        w.writerows(rs)


def stem(row):
    """Export-time identifier stem of a function file: `FUN_00026a42`, `thunk_FUN_000270aa`, ..."""
    return Path(row['file']).stem.split('_', 1)[1]


index = rows('decompiled/function_index.tsv')
byaddr = {r['address']: r for r in index}

accepted = {}
for r in rows('cross_ecu/symbol_aliases.tsv'):
    accepted[r['address']] = r['proposed_alias']
for r in rows('cross_ecu/romraider_function_aliases.tsv'):
    accepted[r['address']] = 'candidate_' + r['proposed_alias']
for r in rows('source_review/accepted_function_aliases.tsv'):
    accepted[r['address']] = ('candidate_' if r['confidence'] == 'medium' else '') + r['alias']

manifest_path = b / 'metadata/integrated_names.json'
prior = json.loads(manifest_path.read_text(encoding='utf-8', errors='surrogateescape')) if manifest_path.exists() else {}

addr_map = {}   # own-address forms, matched case-insensitively on the hex digits
name_map = {}   # forms that do not carry their own address (stems, thunk targets, lookup ids)
claimed = {}    # name currently in the export -> how many rows of the index carry it


def bind(name, alias):
    if name and alias and name != alias:
        name_map[name] = alias


# A name the export carries can be shared by several rows; that makes it unusable as a
# rename source, because the substitution cannot tell the two bodies apart.
for r in index:
    claimed[r['name']] = claimed.get(r['name'], 0) + 1

# Carry the cumulative record first, so renames applied by earlier runs keep resolving;
# this run's TSV-derived names are bound afterwards and win.
for k, v in prior.get('identifier_map', {}).items():
    m = ADDRESS_IDENT.fullmatch(k)
    if m and not m.group(1).startswith(('jump_to_', 'thunk_')):
        addr_map.setdefault(m.group(1) + m.group(2).lower(), v)
    else:
        name_map.setdefault(k, v)

for a, alias in accepted.items():
    row = byaddr.get(a)
    if row is None:
        raise SystemExit('accepted alias for %s, but function_index.tsv has no such function' % a)
    st = stem(row)
    addr_map['FUN_' + a.lower()] = alias
    bind(st, alias)                 # export-time identity, e.g. thunk_FUN_000270aa
    own = ADDRESS_IDENT.fullmatch(row['name'])
    # A name the export carries can be claimed by several rows (two rows aliased alike);
    # renaming it then would hit the wrong body, and the address identity covers the row.
    if claimed.get(row['name'], 0) == 1 and (not own or own.group(2).lower() == a):
        bind(row['name'], alias)    # identity left behind by an earlier partial run

# A thunk's body names its target (`jump_to_FUN_000270aa`), so the form is derived from
# the thunk's own stem. Two thunks can jump to the same target and share that form - the
# substitution then cannot tell their bodies apart, so the form is left alone.
thunks = {}
for r in index:
    st = stem(r)
    if st.startswith('thunk_FUN_'):
        thunks.setdefault('jump_to_FUN_' + st[len('thunk_FUN_'):], []).append(r)
derived = {}    # thunk address -> target-derived name, for a thunk with no alias of its own
for form, rws in thunks.items():
    if len(rws) != 1:
        continue
    r = rws[0]
    name = accepted.get(r['address'])
    if name is None:
        # keeps the export's target-derived convention for an unlabeled thunk
        target_alias = accepted.get(stem(r)[len('thunk_FUN_'):])
        if not target_alias:
            continue
        name = derived[r['address']] = 'jump_to_' + target_alias
    bind(form, name)
for r in rows('cross_ecu/romraider_ram_candidates.tsv'):
    addr_map.setdefault('DAT_' + r['address'].lower(), r['proposed_alias'] + '_' + r['address'])
for r in rows('source_review/accepted_ram_aliases.tsv'):
    addr_map['DAT_' + r['address'].lower()] = r['alias'] + '_' + r['address']
for r in rows('named/lookup_aliases.tsv'):
    bind(r['original'], r['alias'])

addr_map = {k: v for k, v in addr_map.items() if k != v}
name_map = {k: v for k, v in name_map.items() if k != v}
name_pat = re.compile(r'\b(?:' + '|'.join(re.escape(k) for k in sorted(name_map, key=len, reverse=True)) + r')\b') \
    if name_map else None


def rewrite(text):
    """Rename every identifier form of an accepted alias."""
    text = ADDRESS_IDENT.sub(lambda m: addr_map.get(m.group(1) + m.group(2).lower(), m.group(0)), text)
    return name_pat.sub(lambda m: name_map[m.group(0)], text) if name_pat else text


def transform(s):
    parts = COMMENT_SPLIT.split(s)   # provenance comments keep the historical symbols
    for i in range(0, len(parts), 2):
        parts[i] = rewrite(parts[i])
    return ''.join(parts)


def stale(s):
    """Accepted aliases whose address-based identity is still present in the code of `s`."""
    found = []
    for m in ADDRESS_IDENT.finditer(s):
        alias = addr_map.get(m.group(1) + m.group(2).lower())
        if alias and not m.group(1).startswith(('jump_to_', 'thunk_')):
            found.append((m.group(0), alias))
    if name_pat:
        found.extend((m.group(0), name_map[m.group(0)]) for m in name_pat.finditer(s))
    return found


backup = b / 'backups/pre_name_integration.zip'
backup.parent.mkdir(exist_ok=True)
if not backup.exists():
    with zipfile.ZipFile(backup, 'w', zipfile.ZIP_DEFLATED) as z:
        for p in (b / 'decompiled').rglob('*'):
            if p.is_file():
                z.write(p, str(p.relative_to(b)))
changed = 0
for p in (b / 'decompiled/functions').glob('*.c'):
    old = p.read_text(encoding='utf-8', errors='surrogateescape')
    new = transform(old)
    if new != old:
        p.write_text(new, encoding='utf-8', errors='surrogateescape')
        changed += 1
p = b / 'decompiled/firmware_decompiled.c'
s = transform(p.read_text(encoding='utf-8', errors='surrogateescape'))
header = '/* [INTEGRATED REVIEWED NAMES]\n * Canonical analysis C includes wiring, Denso, RX8Defs, G-ROM and CAN reviews.\n * inferred_ and candidate_ names remain hypotheses; address suffixes preserve identity.\n * Provenance comments retain historical symbols. This is not buildable firmware.\n * Saved Ghidra database has not been updated; see metadata/integrated_names.json.\n */\n'
if '[INTEGRATED REVIEWED NAMES]' not in s:
    s = header + s
p.write_text(s, encoding='utf-8', errors='surrogateescape')
final = {**derived, **accepted}   # an accepted alias of the thunk's own wins
for r in index:
    if r['address'] in final:
        r['name'] = final[r['address']]
write('decompiled/function_index.tsv', index)
calls = rows('decompiled/callgraph.tsv')
for r in calls:
    if r['callee'] in final:
        r['callee_name'] = final[r['callee']]
write('decompiled/callgraph.tsv', calls)
syms = rows('decompiled/symbols.tsv')
for r in syms:
    r['name'] = rewrite(r['name']) or r['name']
write('decompiled/symbols.tsv', syms)
# Named view becomes a synchronized compatibility copy, no longer the sole named artifact.
(b / 'named/firmware_named.c').write_text(s, encoding='utf-8', errors='surrogateescape')
# Ensure individual function bodies occur intact in the canonical listing.
for r in index:
    body = (b / 'decompiled'/r['file']).read_text(encoding='utf-8', errors='surrogateescape')
    anchor = '/* ROM address: 0x' + r['address'] + ';'
    assert body[body.index(anchor):].strip() in s, r['address']
    assert re.search(r'\b' + re.escape(r['name']) + r'\s*\(', body), r['address']
assert not stale(COMMENT_SPLIT.sub('', s)), 'address-based identity left in the export: %r' % stale(COMMENT_SPLIT.sub('', s))[:5]
manifest_path.write_text(json.dumps({
    **prior,
    'identifier_map': {**prior.get('identifier_map', {}), **addr_map, **name_map},
    'function_names_integrated': len(final),
    'files_changed_this_run': changed,
    'canonical_and_individual_bodies_verified': len(index),
    'backup': 'backups/pre_name_integration.zip',
    'ghidra_database_updated': False,
}, indent=2) + '\n', encoding='utf-8', errors='surrogateescape')
print(json.dumps({
    'function_names': len(final),
    'address_identifiers': len(addr_map),
    'name_identifiers': len(name_map),
    'individual_files_updated': changed,
    'verified_function_bodies': len(index),
}, indent=2))
