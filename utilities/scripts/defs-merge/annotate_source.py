#!/usr/bin/env python3
"""Add dated review comments without changing any C tokens or function names."""
from pathlib import Path
import json,csv,re,zipfile
O=Path(__file__).resolve().parent;B=O.parent/'60E15120_N3J1E'
rows={r['address']:r for r in csv.DictReader((B/'decompiled/function_index.tsv').open(),delimiter='\t')}
findings=json.loads((O/'function_findings.json').read_text());combined=B/'decompiled/firmware_decompiled.c';named=B/'named/firmware_named.c'
files=[combined,named]+[B/'decompiled'/rows[x['address']]['file'] for x in findings]
backup=B/'backups/pre_defs_20260930.zip'
if not backup.exists():
 with zipfile.ZipFile(backup,'w',zipfile.ZIP_DEFLATED) as z:
  for p in files:z.write(p,p.relative_to(B))
changed=[]
def strip(s):return re.sub(r'/\*.*?\*/|//[^\n]*','',s,flags=re.S)
for p in files:
 old=p.read_text();new=old
 for f in findings:
  marker='/* [RX8DEFS 2026-09-30 '+f['address']+']'
  if marker in new:continue
  anchor='/* ROM address: 0x'+f['address']+';'
  if anchor not in new:continue
  note=marker+'\n * Suggested interpretation: '+f['suggested_name']+'.\n * Confidence: '+f['confidence']+'.\n * '+f['evidence']+'\n */\n'
  new=new.replace(anchor,note+anchor,1)
 assert strip(old).split()==strip(new).split()
 if new!=old:p.write_text(new);changed.append(str(p.relative_to(B)))
(O/'source_annotation_validation.json').write_text(json.dumps({'comments_only':True,'changed_files':changed,'findings':len(findings),'ghidra_database_changed':False},indent=2)+'\n')
print('Source review comments added; C tokens unchanged:',len(changed),'files')
