from pathlib import Path
import csv,re,struct,json
import sys
b=Path(__file__).resolve().parents[1];s=Path(sys.argv[1])/'G_ROM_FlexFuel'
rows=list(csv.DictReader((b/'metadata/matched_functions.tsv').open(),delimiter='\t')); ref=(b.parents[1]/'Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E0FC00.bin').read_bytes();dst=(b.parents[1]/'Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin').read_bytes()
idx=list(csv.DictReader((b/'decompiled/function_index.tsv').open(),delimiter='\t'));rf=list(csv.DictReader((b/'metadata/reference_functions.tsv').open(),delimiter='\t'))

def norm(raw):
 out=[]
 for i in range(0,len(raw),2):
  w=int.from_bytes(raw[i:i+2],'big')
  if w>>12 in (9,13):w &=0xff00
  out.append(w)
 return tuple(out)
by={}
for r in idx:
 a=int(r['address'],16);n=int(r.get('size',r.get('body_bytes','0')));by.setdefault(norm(dst[a:a+n]),[]).append(r)
extra=[]
for r in rf:
 if r['contiguous']!='true' or int(r['size'])<16:continue
 raw=bytes.fromhex(r['bytes']);m=by.get(norm(raw),[])
 if len(m)==1 and not any(z['reference_address']==r['address'] for z in rows):extra.append({'address':m[0]['address'],'reference_address':r['address'],'size':r['size'],'name':r['name'],'method':'unique_target_PC_literal_displacement_masked'})
(b/'source_review/normalized_function_candidates.json').write_text(json.dumps(extra,indent=2)+'\n')
rows+=extra

trans={};evidence={}
for r in rows:
 a=int(r['reference_address'],16);t=int(r['address'],16)
 for off in range(0,int(r['size']),2):
  op=int.from_bytes(ref[a+off:a+off+2],'big')
  if op>>12!=13:continue
  p=((a+off+4)&~3)+(op&255)*4;q=((t+off+4)&~3)+(op&255)*4
  if p+4>len(ref) or q+4>len(dst):continue
  x=int.from_bytes(ref[p:p+4],'big');y=int.from_bytes(dst[q:q+4],'big')
  if x>=0xffff8000 and y>=0xffff8000:
   trans.setdefault(x,set()).add(y);evidence.setdefault((x,y),[]).append({'reference_function':r['reference_address'],'target_function':r['address'],'instruction_offset':off,'reference_literal':f'{p:08x}','target_literal':f'{q:08x}'})
out=[]
for n,h in re.findall(r'^#define\s+(\w+)\s+\(\((?:float|char)\*\)(0x[\da-fA-F]+)\)',(s/'vars.h').read_text(),re.M):
 x=int(h,16);ys=sorted(trans.get(x,[]));out.append({'name':n,'reference_address':f'{x:08x}','target_candidates':[f'{y:08x}' for y in ys],'evidence':{f'{y:08x}':evidence[x,y] for y in ys}})
func=[]
for n,h in re.findall(r'^\.equ\s+_(\w+),\s*(0x[\da-fA-F]+)',(s/'RomAddresses.s').read_text(),re.M):
 x=int(h,16); m=[r for r in rows if int(r['reference_address'],16)==x];func.append({'name':n,'reference_address':f'{x:08x}','target_address':m[0]['address'] if m else None})
(b/'source_review/flex_ram_expanded_candidates.json').write_text(json.dumps(out,indent=2)+'\n');(b/'source_review/flex_function_expanded_candidates.json').write_text(json.dumps(func,indent=2)+'\n')
for x in out:print(x['name'],x['reference_address'],x['target_candidates'])
print('FUNCTIONS');print(json.dumps(func,indent=1))
