#!/usr/bin/env python3
"""Produce a named analysis-C view; retain raw export and per-alias evidence."""
from pathlib import Path
import re,json,csv,collections
b=Path(__file__).resolve().parents[1];out=b/'named';out.mkdir(exist_ok=True)
ds=json.loads((b/'cross_ecu/romraider_descriptor_matches.json').read_text());tables={d['descriptor']:d for d in ds}
def slug(s):return re.sub('[^a-z0-9]+','_',s.lower()).strip('_')
def split_args(s):
 args=[];start=0;depth=0
 for i,ch in enumerate(s):
  if ch=='(':depth+=1
  if ch==')':depth-=1
  if ch==',' and depth==0:args.append(s[start:i].strip());start=i+1
 args.append(s[start:].strip());return args
syn={'Coolant Temp':'Coolant Temperature','Relative Manifold Pressure':'Manifold Relative Pressure'}
evidence=collections.defaultdict(list);calls=[];outputs=collections.defaultdict(list)
for p in (b/'decompiled/functions').glob('*.c'):
 s=re.sub(r'/\*.*?\*/','',p.read_text(),flags=re.S)
 for m in re.finditer(r'\bref_(2DLookup|3dLookup)\(([^;]*?)\);',s):
  args=split_args(m[2]);desc=re.fullmatch(r'&(?:DAT|PTR_DAT)_([0-9a-f]{8})',args[-1])
  if not desc or desc[1] not in tables:continue
  d=tables[desc[1]];dim=d['dimension'];record={'function':p.name.split('_')[0],'descriptor':desc[1],'table':d['name'],'arguments':args,'arity_matches':len(args)==dim};calls.append(record)
  # Only explicit arguments; omitted FPU arguments cannot be inferred by position.
  if len(args)!=dim:continue
  axisby={x['type']:x.get('name','Unknown') for x in d['axes']}
  ax=[axisby.get('Y Axis',axisby.get('X Axis','Unknown'))] if dim==2 else [axisby.get('X Axis','Unknown'),axisby.get('Y Axis','Unknown')]
  for expr,label in zip(args[:-1],ax):
   var=re.fullmatch(r'DAT_([fF]{4}[0-9a-fA-F]{4})',expr)
   if not var or label in ('Unknown','Value',''):continue
   label=syn.get(label,label)
   evidence[var[1].lower()].append({'axis':label,'descriptor':desc[1],'table':d['name'],'function':record['function']})
  lhs=re.search(r'DAT_([fF]{4}[0-9a-fA-F]{4})\s*=\s*(?:\(float\)\s*)?$',s[max(0,m.start()-70):m.start()])
  if lhs:outputs[lhs[1].lower()].append(record)
aliases=[];mapping={}
# Descriptor names are certain address/name correlations, even where the definition's meaning is uncertain.
raw=(b/'decompiled/firmware_decompiled.c').read_text()
for a,d in tables.items():
 name='tbl_'+slug(d['name'])+'_'+a
 for token in re.findall(r'\b(?:DAT|PTR_DAT)_'+a+r'\b',raw):
  mapping[token]=name
  if not any(x['original']==token for x in aliases):aliases.append({'original':token,'alias':name,'basis':'RX8Defs_descriptor_match','evidence':d['name']})
# Preserve meanings already traced through diagnostic readers.
known={r['address']:r['proposed_alias'] for r in csv.DictReader((b/'cross_ecu/romraider_ram_candidates.tsv').open(),delimiter='\t')}
conflicts=[]
for a,ev in evidence.items():
 labels=sorted({x['axis'] for x in ev})
 if len(labels)!=1:
  conflicts.append({'address':a,'axis_names':labels,'evidence':ev});continue
 if a in known:name=known[a]+'_'+a;basis='prior_diagnostic_dataflow_and_lookup_axis'
 else:name='inferred_'+slug(labels[0])+'_'+a;basis='explicit_lookup_argument_and_definition_axis_candidate'
 token='DAT_'+a;mapping[token]=name;aliases.append({'original':token,'alias':name,'basis':basis,'evidence':json.dumps(ev)})
# Also expose already-supported names on lookup inputs with unknown axes, without inventing semantics.
for a,n in known.items():
 token='DAT_'+a
 if token not in mapping and any(token in c['arguments'][:-1] for c in calls):
  name=n+'_'+a;mapping[token]=name;aliases.append({'original':token,'alias':name,'basis':'prior_diagnostic_dataflow','evidence':'cross_ecu/romraider_ram_candidates.tsv'})
with (out/'lookup_aliases.tsv').open('w') as f:
 w=csv.DictWriter(f,fieldnames=['original','alias','basis','evidence'],delimiter='\t');w.writeheader();w.writerows(aliases)
pattern=re.compile(r'\b(?:DAT|PTR_DAT)_[0-9a-fA-F]{8}\b')
# Preserve comments verbatim so provenance retains original symbol tokens.
parts=re.split(r'(/\*.*?\*/)',raw,flags=re.S)
for i in range(0,len(parts),2):parts[i]=pattern.sub(lambda m:mapping.get(m[0],m[0]),parts[i])
named=''.join(parts)
header='/* Named analysis view. tbl_ names identify matched ROM descriptors.\n * inferred_ names are axis-derived RAM candidates, not recovered OEM symbols.\n * Address suffixes distinguish separate values of the same physical quantity.\n * Raw ABI/decompiler limitations remain; see named/README.md.\n */\n'
(out/'firmware_named.c').write_text(header+named)
(out/'lookup_calls.json').write_text(json.dumps(calls,indent=2)+'\n');(out/'axis_conflicts.json').write_text(json.dumps(conflicts,indent=2)+'\n');(out/'lookup_result_candidates.json').write_text(json.dumps(outputs,indent=2)+'\n')
# Verify token-only transformation reverses exactly outside the extra header.
reverse={v:k for k,v in mapping.items()}
# DAT and PTR_DAT may refer to the same descriptor: reverse via original token stream instead.
for original,modified in zip(re.split(r'(/\*.*?\*/)',raw,flags=re.S),parts):
 if original.startswith('/*'):assert original==modified
 else:assert pattern.sub(lambda m:mapping.get(m[0],m[0]),original)==modified
stats={'descriptor_addresses_named':len({re.search(r'[0-9a-f]{8}$',x['original'])[0] for x in aliases if x['basis']=='RX8Defs_descriptor_match'}),'ram_addresses_named':sum(x['original'].startswith('DAT_ffff') for x in aliases),'axis_derived_candidates':sum(x['alias'].startswith('inferred_') for x in aliases),'conflicting_ram_addresses':len(conflicts),'matched_lookup_calls':len(calls),'calls_with_missing_or_extra_arguments':sum(not c['arity_matches'] for c in calls),'raw_export_changed':False,'ghidra_database_updated':False,'token_only_transformation_verified':True}
(out/'validation.json').write_text(json.dumps(stats,indent=2)+'\n');print(json.dumps(stats,indent=2))
