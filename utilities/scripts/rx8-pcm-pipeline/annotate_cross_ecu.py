#!/usr/bin/env python3
"""Apply review comments to exported C, retaining original identities and Ghidra database."""
from pathlib import Path
import csv,json,re
from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
c=b/'cross_ecu'
rows=list(csv.DictReader((c/'symbol_aliases.tsv').open(),delimiter='\t'))
notes={r['address']:[r['proposed_alias']+' ['+r['confidence']+']: '+r['comment']] for r in rows}
logger=json.loads((c/'romraider_logger_matches.json').read_text()); aliases=[]
for x in logger:
 if not x['handler']:continue
 a=x['handler'];name=x['name']
 notes.setdefault(a,[]).append('RX8Defs service 0x22 identifier 0x'+x['did']+': '+name+'. '+('CONFLICT: same identifier also named '+', '.join(x['conflicts'])+'. Do not assign a semantic alias.' if x['conflicts'] else 'Dispatch identifier match; logger meaning is definition-derived.'))
 if not x['conflicts']:aliases.append({'address':a,'proposed_alias':'diag_read_'+re.sub('[^a-z0-9]+','_',name.lower()).strip('_'),'confidence':'definition_and_dispatch_match'})
ram=[('ffffb548','engine_speed_rpm','00055484','00056982'),('ffff9f70','coolant_temperature','0005542a','00056940'),('ffffbbb4','vehicle_speed','0005549a','00056998'),('ffffa630','leading_ignition_timing','000554ae','000569ae'),('ffffa638','trailing_ignition_timing','00056cc8','00056cc8'),('ffff9f60','intake_air_temperature','000554c6','000569c4'),('ffffa734','knock_retard','0005707a','0005707a'),('ffffc0b4','engine_load','00055748','00056b8a'),('ffffadfc','lambda_target','0005575e','00056b9e'),('ffffa9ec','mass_air_flow','00055528','000569da'),('ffffd380','tire_revolutions_per_mile','00057004','00057004')]
with (c/'romraider_ram_candidates.tsv').open('w') as f:
 w=csv.writer(f,delimiter='\t');w.writerow(['address','proposed_alias','reader','diagnostic_handler','confidence'])
 for a,n,reader,handler in ram:
  src=next((b/'decompiled/functions').glob(reader+'_*')).read_text();assert 'DAT_'+a in src
  w.writerow([a,n,reader,handler,'logger_identifier_plus_C_dataflow_candidate'])
  notes.setdefault(reader,[]).append('RX8Defs diagnostic chain suggests RAM 0x'+a+' = '+n+'. Direct C dataflow to handler 0x'+handler+'; semantic candidate, not a recovered original symbol.')
with (c/'romraider_function_aliases.tsv').open('w') as f:
 w=csv.DictWriter(f,fieldnames=['address','proposed_alias','confidence'],delimiter='\t');w.writeheader();w.writerows(aliases)
# Reference annotations link actual descriptor literals to their matched XML metadata.
desc=json.loads((c/'romraider_descriptor_matches.json').read_text()); count=0
for p in (b/'decompiled/functions').glob('*.c'):
 s=p.read_text(); hits=[]
 for d in desc:
  if re.search(r'(?i)(?:0x0*'+d['descriptor'].lstrip('0')+r'\b|(?:DAT|PTR|LAB)_'+d['descriptor']+r'\b)',s):hits.append('Descriptor 0x'+d['descriptor']+': '+d['name']+' (RX8Defs data pointer, axes and dimensions match).')
 if hits:notes.setdefault(p.name.split('_')[0],[]).extend(hits);count+=1
combined=b/'decompiled/firmware_decompiled.c';alltext=combined.read_text()
pattern=r'/\* \[CROSS-ECU / RX8DEFS REVIEW\].*?\*/\n'
alltext=re.sub(pattern,'',alltext,flags=re.S)
for a,lines in notes.items():
 paths=list((b/'decompiled/functions').glob(a+'_*'));assert len(paths)==1
 p=paths[0];s=re.sub(pattern,'',p.read_text(),flags=re.S)
 comment='/* [CROSS-ECU / RX8DEFS REVIEW]\n * '+'\n * '.join(lines).replace('*/','* /')+'\n */\n'
 p.write_text(comment+s)
 marker='/* ROM address: 0x'+a+';';assert alltext.count(marker)==1
 alltext=alltext.replace(marker,comment+marker)
combined.write_text(alltext)
(c/'annotation_validation.json').write_text(json.dumps({'annotated_function_files':len(notes),'functions_with_descriptor_literals':count,'ram_candidates':len(ram),'diagnostic_alias_candidates':len(aliases),'ghidra_database_updated':False},indent=2)+'\n')
print((c/'annotation_validation.json').read_text())
