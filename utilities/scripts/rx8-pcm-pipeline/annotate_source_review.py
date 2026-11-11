#!/usr/bin/env python3
"""Reapply reviewed source-based comments after a fresh export; no symbol renaming."""
from pathlib import Path
import csv,re
from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
d=b/'source_review'
def rows(n):return list(csv.DictReader((d/n).open(),delimiter='\t'))
notes={}
# Keep every accepted row per address (an address may carry a medium and a high hypothesis);
# evidence may be missing on legacy 4-field RAM rows (ROADMAP discrepancy D12) - render as empty.
for r in rows('accepted_function_aliases.tsv'):notes.setdefault(r['address'],[]).append(r['alias']+' ['+r['confidence']+']: '+(r['evidence'] or ''))
for r in rows('accepted_ram_aliases.tsv'):notes.setdefault(r['reader'],[]).append('RAM 0x'+r['address']+' '+r['alias']+' ('+r['type']+'): '+(r['evidence'] or ''))
patt=r'/\* \[ADDITIONAL SOURCE REVIEW\].*?\*/\n';combined=b/'decompiled/firmware_decompiled.c';s=re.sub(patt,'',combined.read_text(),flags=re.S)
for a,lines in notes.items():
 p=next((b/'decompiled/functions').glob(a+'_*'));raw=re.sub(patt,'',p.read_text(),flags=re.S);note='/* [ADDITIONAL SOURCE REVIEW]\n * '+'\n * '.join(lines)+'\n */\n';p.write_text(note+raw);marker='/* ROM address: 0x'+a+';';assert s.count(marker)==1;s=s.replace(marker,note+marker)
combined.write_text(s)
# Keep the named compatibility view byte-identical to the canonical monolith (as integrate_reviewed_names.py does).
(b/'named/firmware_named.c').write_text(s)
assert s.count('/* [ADDITIONAL SOURCE REVIEW]')==len(notes)
print('Verified source-review comments:',len(notes))
