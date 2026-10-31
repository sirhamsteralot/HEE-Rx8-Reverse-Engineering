from pathlib import Path
import xml.etree.ElementTree as E
import json,csv,re,hashlib,zipfile
b=Path(__file__).resolve().parents[1];w=b.parents[1];defs=w/'RX8Defs';out=defs/'Analysis/60E15120';out.mkdir(parents=True,exist_ok=True)
p=defs/'RomRaider/rx8_defs.xml';raw=p.read_text(encoding='utf-8-sig')
if '[60E15120 analysis 2026-09-18]' in raw:
 print('Definitions already extended; restore the backup before regenerating.');raise SystemExit(0)
root=E.fromstring(raw);target=next(x for x in root.findall('rom') if x.findtext('romid/xmlid')=='60E15120')
backup=out/'definitions_before_review.zip'
if not backup.exists():
 with zipfile.ZipFile(backup,'w',zipfile.ZIP_DEFLATED) as z:
  for f in ['rx8_defs.xml','logger_rx8_defs.xml']:z.write(defs/'RomRaider'/f,f)
base=next(x for x in root.findall('rom') if x.findtext('romid/xmlid','').casefold()==target.get('base').casefold());bt={x.get('name'):x for x in base.findall('table')}
desc=json.loads((b/'cross_ecu/romraider_descriptor_matches.json').read_text());calls=json.loads((b/'named/lookup_calls.json').read_text());aliases=list(csv.DictReader((b/'named/lookup_aliases.tsv').open(),delimiter='\t'));ram={x['original']:x['alias'] for x in aliases if x['original'].startswith('DAT_ffff')}
for r in csv.DictReader((b/'cross_ecu/romraider_ram_candidates.tsv').open(),delimiter='\t'):ram.setdefault('DAT_'+r['address'],r['proposed_alias'])
bydata={int(x['data_address'],16):x for x in desc};typed={0:'float32',4:'uint8',8:'uint16',12:'int8',16:'int16'};changes=[];axiscount=0
for t in target.findall('table'):
 d=bydata.get(int(t.get('storageaddress','0'),16))
 if not d:continue
 uses=[c for c in calls if c['descriptor']==d['descriptor']];note=f"[60E15120 analysis 2026-09-18] Lookup descriptor 0x{d['descriptor']}; {d['dimension']}D; data 0x{d['data_address']}; counts {d['counts']}; dispatch type {d['type_code']} ({typed.get(d['type_code'],'unresolved')}). Descriptor/data/axis/count correspondence verified against this ROM. Table purpose follows community definitions unless independently corroborated."
 if uses:note+=' Referencing functions: '+', '.join(sorted({c['function'] for c in uses}))+'.'
 inherited=bt.get(t.get('name'));axnotes=[]
 for axis in t.findall('table'):
  axis_type=axis.get('type');ix=0 if d['dimension']==2 or axis_type=='X Axis' else 1
  prior=next((x.get('name','Unknown') for x in d['axes'] if x.get('type')==axis_type),'Unknown')
  labels=set()
  for c in uses:
   if c['arity_matches']:
    arg=c['arguments'][ix]
    if arg in ram:labels.add(re.sub(r'_ffff[0-9a-f]{4}$','',ram[arg]).removeprefix('inferred_'))
  if len(labels)==1 and prior in ('Unknown','Value',''):
   label=next(iter(labels)).replace('_',' ').capitalize()+' (inferred)';axis.set('name',label);axiscount+=1;axnotes.append(axis_type+': '+label)
 if axnotes:note+=' Axis labels inferred from direct lookup arguments: '+'; '.join(axnotes)+'. Distinct raw/filtered/requested variants are not established.'
 existing=t.find('description')
 if existing is None:
  existing=E.SubElement(t,'description');inherited_desc=inherited.findtext('description') if inherited is not None else None
  existing.text=(inherited_desc+'\n' if inherited_desc else '')+note
 else:existing.text=(existing.text or '').split('[60E15120 analysis')[0].rstrip()+'\n'+note
 changes.append({'table':t.get('name'),'descriptor':d['descriptor'],'axes_added':axnotes})
# Modify only this ROM block; preserve all other variants byte-for-byte.
blocks=list(re.finditer(r'<rom\b[^>]*>.*?</rom>',raw,re.S));match=next(m for m in blocks if '<xmlid>60E15120</xmlid>' in m[0]);E.indent(target,space='    ');new=raw[:match.start()]+E.tostring(target,encoding='unicode')+raw[match.end():];p.write_text('\ufeff'+new,encoding='utf-8')
# A separate stock-target logger avoids asserting these addresses for all Mazda variants.
log=E.parse(defs/'RomRaider/logger_rx8_defs.xml').getroot();proto=log.find('.//protocol[@id="MAZDA"]');params=proto.find('parameters');matches=json.loads((b/'cross_ecu/romraider_logger_matches.json').read_text());approved={x['request']:x for x in matches if x['handler'] and not x['conflicts'] and x['response_bytes'] in (1,2)}
for x in list(params):params.remove(x)
orig=E.parse(defs/'RomRaider/logger_rx8_defs.xml').getroot().findall('.//protocol[@id="MAZDA"]/parameters/parameter');seen=set()
for x in orig:
 req=x.findtext('address').lower().removeprefix('0x');m=approved.get(req)
 if not m or req in seen:continue
 seen.add(req);x.set('id','RX8_60E15120_'+m['did'].upper());x.set('desc',(x.get('name','')+'; Reviewed for stock 60E15120 only. Handler 0x'+m['handler']+'. Meaning from RX8Defs, correlated with firmware dispatch.'))
 for cv in x.findall('conversions/conversion'):cv.set('storagetype','uint8' if m['response_bytes']==1 else 'uint16')
 params.append(x)
def add(id,name,addr,units,expr,desc):
 x=E.SubElement(params,'parameter',id=id,name=name,desc=desc);E.SubElement(x,'address').text=addr;cs=E.SubElement(x,'conversions');E.SubElement(cs,'conversion',storagetype='uint16',units=units,expr=expr,format='0.000')
add('RX8_60E15120_0042','Control Module Voltage (candidate)','0x220042','V','x*0.001','60E15120 only. Dispatch 0x56b76 -> 0x55732 -> RAM 0xffffb590; uint16 scaling approximately 0.001. Battery-voltage meaning corroborated by injector-latency axes; candidate until vehicle logging validates it.')
add('RX8_60E15120_1410_RAW','Identifier 1410 - raw (meaning unresolved)','0x221410','raw','x','60E15120 only. Handler 0x56f6c emits uint16 from RAM 0xffffbe24 using step 8. Existing injector/throttle interpretations conflict; no physical unit assigned here.')
E.indent(log,space='    ');dest=defs/'RomRaider/logger_60E15120_reviewed.xml';E.ElementTree(log).write(dest,encoding='utf-8',xml_declaration=True)
# Consolidate non-calibration information in a supported sidecar instead of fake editor tables.
symbols=[]
for rel in ['cross_ecu/symbol_aliases.tsv','cross_ecu/romraider_ram_candidates.tsv','source_review/accepted_function_aliases.tsv','source_review/accepted_ram_aliases.tsv','math_units/helper_aliases.tsv']:
 for r in csv.DictReader((b/rel).open(),delimiter='\t'):symbols.append({'source':rel,**r})
(out/'recovered_symbols.json').write_text(json.dumps(symbols,indent=2)+'\n');(out/'table_changes.json').write_text(json.dumps(changes,indent=2)+'\n')
# Ensure editor bytes/shape/scaling/state definitions are unchanged except annotations.
def structural(x):
 attrs={k:v for k,v in x.attrib.items() if not (x.tag=='table' and x.get('type') in ('X Axis','Y Axis') and k=='name')}
 return (x.tag,attrs,(x.text or '').strip(),[structural(c) for c in x if c.tag!='description'])
oldtarget=E.fromstring(match[0]);assert structural(oldtarget)==structural(target)
assert new[:match.start()]==raw[:match.start()];assert new.endswith(raw[match.end():])
E.parse(p);parsed=E.parse(dest);ids=[x.get('id') for x in parsed.findall('.//parameter')];assert len(ids)==len(set(ids))
result={'rom':'60E15120','tables_annotated':len(changes),'axis_labels_added':axiscount,'reviewed_logger_parameters':len(ids),'editor_addresses_scaling_shapes_and_states_unchanged':True,'other_rom_blocks_unchanged':True,'xml_parse_passed':True,'logger_ids_unique':True,'live_RomRaider_load_tested':False}
(out/'validation.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
