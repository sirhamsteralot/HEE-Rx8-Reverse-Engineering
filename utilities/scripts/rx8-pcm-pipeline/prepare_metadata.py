#!/usr/bin/env python3
"""Generate labels and conservative function seeds from local evidence."""
from pathlib import Path
import csv, hashlib, json, re, struct, xml.etree.ElementTree as ET
root=Path(__file__).resolve().parents[3]
out=Path(__file__).resolve().parents[1]
rom=root/'Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin'
b=rom.read_bytes()
meta=out/'metadata'
def ident(s): return re.sub(r'[^a-zA-Z0-9_]', '_',s)
tree=ET.parse(root/'RX8Defs/RomRaider/rx8_defs.xml')
r=next(r for r in tree.getroot().iter('rom') if any(x.text=='60E15120' for x in r.findall('./romid/xmlid')))
with (meta/'calibration_labels.tsv').open('w') as f:
 f.write('address\tname\toriginal_name\n')
 for i,t in enumerate(r.iter('table')):
  a=t.get('storageaddress')
  if a: f.write(f'{int(a,16):08x}\tCAL_{ident(t.get("name","table"))}_{i}\t{t.get("name")}\n')
rows=list(csv.DictReader((meta/'reference_functions.tsv').open(),delimiter='\t'))
with (meta/'matched_functions.tsv').open('w') as f:
 f.write('address\tname\treference_address\tsize\tmethod\n')
 for row in rows:
  raw=bytes.fromhex(row['bytes'])
  if len(raw)<12: continue
  first=b.find(raw)
  if first<0 or first%2 or b.find(raw,first+1)>=0: continue
  name=row['name']
  if name.startswith(('FUN_','thunk_FUN_')): name=f'FUN_{first:08x}'
  else: name='ref_'+ident(name)
  f.write(f'{first:08x}\t{name}\t{row["address"]}\t{len(raw)}\tunique_exact_bytes\n')
(meta/'input.json').write_text(json.dumps({'file':str(rom),'size':len(b),'sha256':hashlib.sha256(b).hexdigest(),'firmware_id':b[0x2000:0x2008].decode(),'calibration_id':b[0x6c046:0x6c04b].decode(),'initial_pc':hex(struct.unpack_from('>I',b)[0]),'initial_sp':hex(struct.unpack_from('>I',b,4)[0])},indent=2)+'\n')
print((meta/'input.json').read_text())
print('Exact function matches:',sum(1 for _ in (meta/'matched_functions.tsv').open())-1)
