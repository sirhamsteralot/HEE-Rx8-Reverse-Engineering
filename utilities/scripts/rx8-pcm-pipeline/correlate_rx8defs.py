#!/usr/bin/env python3
"""Correlate local definitions with ROM descriptors and diagnostic records; no ROM edits."""
from pathlib import Path
import xml.etree.ElementTree as E
import struct,csv,json,re,hashlib
from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
workspace=base.parents[1]
rom=rom_file().read_bytes()
xml=workspace/'RX8Defs/RomRaider/rx8_defs.xml'; logger=xml.with_name('logger_rx8_defs.xml')
r=E.parse(xml).getroot(); target=next(x for x in r.findall('rom') if x.findtext('romid/xmlid')=='60E15120')
parent=next(x for x in r.findall('rom') if x.findtext('romid/xmlid','').casefold()==target.get('base').casefold())
base_tables={x.get('name'):x for x in parent.findall('table')}; matches=[]
for t in target.findall('table'):
 b=base_tables.get(t.get('name'))
 if b is None or b.get('type') not in ('2D','3D') or not t.get('storageaddress'):continue
 dim=int(b.get('type')[0]); data=int(t.get('storageaddress'),16)
 axes={x.get('type'):int(x.get('storageaddress'),16) for x in t.findall('table') if x.get('storageaddress')}
 needle=struct.pack('>I',data); pos=0
 while True:
  pos=rom.find(needle,pos)
  if pos<0:break
  a=pos-(8 if dim==2 else 12);pos+=1
  if a<0 or a%4:continue
  if dim==2:
   n,typ,_,axis,dp=struct.unpack_from('>HBBII',rom,a)
   if axis not in axes.values() or n!=int(b.get('sizey',b.get('sizex','0'))):continue
   counts=[n]; pointers=[axis]
  else:
   nx,ny,ax,ay,dp,typ=struct.unpack_from('>HHIIIB',rom,a)
   if nx!=int(b.get('sizex','0')) or ny!=int(b.get('sizey','0')) or ax!=axes.get('X Axis') or ay!=axes.get('Y Axis'):continue
   counts=[nx,ny];pointers=[ax,ay]
  if not all(0<n<1024 and p+n*4<=len(rom) for n,p in zip(counts,pointers)):continue
  scale=b.find('scaling')
  matches.append(dict(descriptor=f'{a:08x}',dimension=dim,name=t.get('name').strip(),data_address=f'{data:08x}',counts=counts,axis_addresses=[f'{p:08x}' for p in pointers],type_code=typ,storage_type=b.get('storagetype'),scaling=scale.attrib if scale is not None else {},axes=[x.attrib for x in b.findall('table')],confidence='definition_pointer_axis_count_match'))
(base/'cross_ecu/romraider_descriptor_matches.json').write_text(json.dumps(matches,indent=2)+'\n')
dispatch=list(csv.DictReader((base/'metadata/diagnostic_dispatch.tsv').open(),delimiter='\t')); bydid={int(x['descriptor'],16)>>16:x for x in dispatch}
params=E.parse(logger).getroot().findall('.//protocol[@id="MAZDA"]/parameters/parameter'); out=[]
for p in params:
 request=int(p.findtext('address'),16);did=request&65535;d=bydid.get(did)
 conflicts=[q.get('name') for q in params if q is not p and q.findtext('address','').lower()==p.findtext('address').lower()]
 out.append(dict(name=p.get('name'),request=f'{request:06x}',did=f'{did:04x}',handler=d['target'] if d else '',response_bytes=(int(d['descriptor'],16)>>8)&255 if d else None,conflicts=conflicts,conversions=[x.attrib for x in p.findall('conversions/conversion')],status='conflicting_definition' if conflicts else 'dispatch_identifier_match' if d else 'not_in_recovered_dispatch'))
(base/'cross_ecu/romraider_logger_matches.json').write_text(json.dumps(out,indent=2)+'\n')
report={'descriptor_matches':len(matches),'descriptively_named_matches':sum(not x['name'].startswith('Table ') for x in matches),'logger_parameters':len(out),'logger_dispatch_matches':sum(bool(x['handler']) for x in out),'logger_conflicts':sum(bool(x['conflicts']) for x in out),'source_sha256':{str(p.relative_to(workspace)):hashlib.sha256(p.read_bytes()).hexdigest() for p in [xml,logger]},'inheritance_note':'Rx8Base resolved case-insensitively to RX8Base','semantic_equivalence_verified':False}
(base/'cross_ecu/validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
for x in out:print(x['did'],x['handler'],x['name'],x['status'])
