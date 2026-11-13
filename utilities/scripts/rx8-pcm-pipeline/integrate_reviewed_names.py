#!/usr/bin/env python3
"""Integrate reviewed names into canonical C; retain address-based identity and provenance."""
from pathlib import Path
import csv,json,re,zipfile,hashlib
from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
def rows(p):return list(csv.DictReader((b/p).open(encoding='utf-8',errors='surrogateescape'),delimiter='\t'))
def write(p,rs):
 with (b/p).open('w',encoding='utf-8',errors='surrogateescape') as f:
  w=csv.DictWriter(f,fieldnames=list(rs[0]),delimiter='\t');w.writeheader();w.writerows(rs)
backup=b/'backups/pre_name_integration.zip';backup.parent.mkdir(exist_ok=True)
if not backup.exists():
 with zipfile.ZipFile(backup,'w',zipfile.ZIP_DEFLATED) as z:
  for p in (b/'decompiled').rglob('*'):
   if p.is_file():z.write(p,str(p.relative_to(b)))
index=rows('decompiled/function_index.tsv');byaddr={r['address']:r for r in index};mapping={};fn={}
for r in rows('cross_ecu/symbol_aliases.tsv'):fn[r['address']]=r['proposed_alias']
for r in rows('cross_ecu/romraider_function_aliases.tsv'):fn[r['address']]='candidate_'+r['proposed_alias']
for r in rows('source_review/accepted_function_aliases.tsv'):fn[r['address']]=('candidate_' if r['confidence']=='medium' else '')+r['alias']
for a,n in fn.items():mapping[byaddr[a]['name']]=n
for r in rows('named/lookup_aliases.tsv'):mapping[r['original']]=r['alias']
for r in rows('cross_ecu/romraider_ram_candidates.tsv'):mapping.setdefault('DAT_'+r['address'],r['proposed_alias']+'_'+r['address'])
for r in rows('source_review/accepted_ram_aliases.tsv'):mapping['DAT_'+r['address']]=r['alias']+'_'+r['address']
manifest=b/'metadata/integrated_names.json'
if manifest.exists():mapping={**json.loads(manifest.read_text(encoding='utf-8',errors='surrogateescape'))['identifier_map'],**mapping}
mapping={k:v for k,v in mapping.items() if k!=v}
pattern=re.compile(r'\b(?:'+ '|'.join(re.escape(k) for k in sorted(mapping,key=len,reverse=True))+r')\b')
def transform(s):
 parts=re.split(r'(/\*.*?\*/|//[^\n]*)',s,flags=re.S)
 for i in range(0,len(parts),2):parts[i]=pattern.sub(lambda m:mapping[m[0]],parts[i])
 return ''.join(parts)
changed=0
for p in (b/'decompiled/functions').glob('*.c'):
 old=p.read_text(encoding='utf-8',errors='surrogateescape');new=transform(old)
 if new!=old:p.write_text(new,encoding='utf-8',errors='surrogateescape');changed+=1
p=b/'decompiled/firmware_decompiled.c';s=transform(p.read_text(encoding='utf-8',errors='surrogateescape'))
header='/* [INTEGRATED REVIEWED NAMES]\n * Canonical analysis C includes wiring, Denso, RX8Defs, G-ROM and CAN reviews.\n * inferred_ and candidate_ names remain hypotheses; address suffixes preserve identity.\n * Provenance comments retain historical symbols. This is not buildable firmware.\n * Saved Ghidra database has not been updated; see metadata/integrated_names.json.\n */\n'
if '[INTEGRATED REVIEWED NAMES]' not in s:s=header+s
p.write_text(s,encoding='utf-8',errors='surrogateescape')
for r in index:
 if r['address'] in fn:r['name']=fn[r['address']]
write('decompiled/function_index.tsv',index)
calls=rows('decompiled/callgraph.tsv')
for r in calls:
 if r['callee'] in fn:r['callee_name']=fn[r['callee']]
write('decompiled/callgraph.tsv',calls)
syms=rows('decompiled/symbols.tsv')
for r in syms:r['name']=mapping.get(r['name'],r['name'])
write('decompiled/symbols.tsv',syms)
# Named view becomes a synchronized compatibility copy, no longer the sole named artifact.
(b/'named/firmware_named.c').write_text(s)
# Ensure individual function bodies occur intact in the canonical listing.
for r in index:
 body=(b/'decompiled'/r['file']).read_text(encoding='utf-8',errors='surrogateescape');anchor='/* ROM address: 0x'+r['address']+';'
 assert body[body.index(anchor):].strip() in s, r['address']
 assert re.search(r'\b'+re.escape(r['name'])+r'\s*\(',body),r['address']
manifest.write_text(json.dumps({'identifier_map':mapping,'function_names_integrated':len(fn),'files_changed_this_run':changed,'canonical_and_individual_bodies_verified':len(index),'backup':'backups/pre_name_integration.zip','ghidra_database_updated':False},indent=2)+'\n')
print(json.dumps({'function_names':len(fn),'identifier_renames':len(mapping),'individual_files_updated':changed,'verified_function_bodies':len(index)},indent=2))
