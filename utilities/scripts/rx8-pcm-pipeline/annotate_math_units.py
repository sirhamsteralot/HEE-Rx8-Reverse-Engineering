#!/usr/bin/env python3
from pathlib import Path
import csv,json,re,struct,math
b=Path(__file__).resolve().parents[1];d=b/'math_units'
def read(p):return list(csv.DictReader((b/p).open(),delimiter='\t'))
def write(p,rs):
 with (b/p).open('w') as f:
  w=csv.DictWriter(f,fieldnames=list(rs[0]),delimiter='\t');w.writeheader();w.writerows(rs)
idx=read('decompiled/function_index.tsv');by={r['address']:r for r in idx};aliases=read('math_units/helper_aliases.tsv');rename={by[r['address']]['name']:r['alias'] for r in aliases};newnames={r['address']:r['alias'] for r in aliases}
notes={a:[v] for a,v in json.loads((d/'manual_annotations.json').read_text()).items()}
for r in aliases:notes.setdefault(r['address'],[]).append(r['alias']+': '+r['evidence'])
# Bind names by address so the scan works before and after renaming.
enc={by['00002490']['name']:16,by['000024d0']['name']:8,'rx8_encode_u16_affine_saturate':16,'rx8_encode_u8_affine_saturate':8}
callpat=re.compile(r'\b('+'|'.join(re.escape(n) for n in enc)+r')\(\s*([^,;()]+),\s*(0x[0-9a-fA-F]+|[-+0-9.eE]+),\s*(0x[0-9a-fA-F]+|[-+0-9.eE]+)\s*\)')
units={'engine_speed_rpm':'RPM','coolant_temperature':'degC','intake_air_temperature':'degC','leading_ignition_timing':'degrees','trailing_ignition_timing':'degrees','knock_retard':'degrees','vehicle_speed':'km/h','mass_air_flow':'g/s','lambda_target':'dimensionless lambda','engine_load':'logger-defined load units'}
def fp(s):return struct.unpack('>f',int(s,16).to_bytes(4,'big'))[0] if s.startswith('0x') else float(s)
conversions=[]
for r in idx:
 s=re.sub(r'/\*.*?\*/','',(b/'decompiled'/r['file']).read_text(),flags=re.S)
 for m in callpat.finditer(s):
  try:step,offset=fp(m[3]),fp(m[4])
  except (ValueError,OverflowError):continue
  if not math.isfinite(step) or not math.isfinite(offset) or step==0:continue
  signal=m[2].strip();unit=next((v for k,v in units.items() if signal.startswith(k+'_')),'unassigned units')
  entry={'function':r['address'],'signal':signal,'bits':enc[m[1]],'step':step,'offset':offset,'step_literal':m[3],'offset_literal':m[4],'units':unit};conversions.append(entry)
  line=f'Affine encoding ({enc[m[1]]}-bit): {signal}; decode = raw * {step:.10g} + ({offset:.10g}) [{unit}]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.'
  if line not in notes.setdefault(r['address'],[]):notes[r['address']].append(line)
(d/'affine_conversions.json').write_text(json.dumps(conversions,indent=2)+'\n')
pat=re.compile(r'\b(?:'+'|'.join(re.escape(k) for k in rename)+r')\b');oldnote=r'/\* \[MATH AND UNITS REVIEW\].*?\*/\n'
def transform(s):
 s=re.sub(oldnote,'',s,flags=re.S);parts=re.split(r'(/\*.*?\*/|//[^\n]*)',s,flags=re.S)
 for i in range(0,len(parts),2):parts[i]=pat.sub(lambda m:rename[m[0]],parts[i])
 return ''.join(parts)
combined=b/'decompiled/firmware_decompiled.c';s=transform(combined.read_text())
for r in idx:
 p=b/'decompiled'/r['file'];t=transform(p.read_text());a=r['address']
 if a in notes:
  comment='/* [MATH AND UNITS REVIEW]\n * '+'\n * '.join(notes[a])+'\n */\n';anchor='/* ROM address: 0x'+a+';';assert s.count(anchor)==1;s=s.replace(anchor,comment+anchor);t=t.replace(anchor,comment+anchor)
 p.write_text(t)
 if a in newnames:r['name']=newnames[a]
combined.write_text(s);(b/'named/firmware_named.c').write_text(s);write('decompiled/function_index.tsv',idx)
for file,col in [('decompiled/callgraph.tsv','callee_name'),('decompiled/symbols.tsv','name')]:
 rs=read(file)
 for r in rs:r[col]=rename.get(r[col],r[col])
 write(file,rs)
# Preserve full reproducible integrated rename chain.
p=b/'metadata/integrated_names.json';manifest=json.loads(p.read_text());mp=manifest['identifier_map']
for k,v in list(mp.items()):mp[k]=rename.get(v,v)
mp.update({k:v for k,v in rename.items() if k!=v});p.write_text(json.dumps(manifest,indent=2)+'\n')
for r in idx:
 t=(b/'decompiled'/r['file']).read_text();anchor='/* ROM address: 0x'+r['address']+';';assert t[t.index(anchor):].strip() in s
stats={'helper_names':len(aliases),'annotated_functions':len(notes),'affine_calls_decoded':len(conversions),'affine_calls_with_signal_units':sum(x['units']!='unassigned units' for x in conversions),'canonical_function_bodies_verified':len(idx),'library_origin_proven':False}
(d/'validation.json').write_text(json.dumps(stats,indent=2)+'\n');print(json.dumps(stats,indent=2))
