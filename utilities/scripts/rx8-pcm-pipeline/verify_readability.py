from pathlib import Path
import csv,json,re,collections
from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
s=(b/'decompiled/firmware_decompiled.c').read_text();changes=json.loads((b/'readability/changes.json').read_text());idx=list(csv.DictReader((b/'decompiled/function_index.tsv').open(),delimiter='\t'))
for r in idx:
 t=(b/'decompiled'/r['file']).read_text();marker='/* ROM address: 0x'+r['address']+';';assert t[t.index(marker):].strip() in s
for c in changes:
 for action in c['actions']:
  vals=list(action.get('local_names',{}).values());assert len(vals)==len(set(vals))
# Audit raw lookup calls, excluding definitions. Missing FPU operands stay visible.
issues=[]
for r in idx:
 t=re.sub(r'/\*.*?\*/','',(b/'decompiled'/r['file']).read_text(),flags=re.S)
 for m in re.finditer(r'\b(lookup_2d_descriptor_scaled|lookup_3d_descriptor_scaled)\(',t):
  pos=m.end();depth=1;commas=0
  while pos<len(t) and depth:
   ch=t[pos];depth += (ch=='(')-(ch==')')
   if ch==',' and depth==1:commas+=1
   pos+=1
  if t[pos:].lstrip().startswith('{'):continue
  expected=2 if '2d' in m[1] else 3
  if commas+1!=expected:issues.append({'function':r['address'],'callee':m[1],'observed_arity':commas+1,'expected_arity':expected,'raw_call':t[m.start():pos]})
(b/'readability/unresolved_lookup_calls.json').write_text(json.dumps(issues,indent=2)+'\n')
stats={'functions_changed':len(changes),'local_identifiers_named':sum(len(ac.get('local_names',{})) for c in changes for ac in c['actions']),'signature_or_ABI_refinements':sum('signature' in ac for c in changes for ac in c['actions']),'structure_definitions':5,'unresolved_lookup_calls':len(issues),'function_bodies_consistent':len(idx),'ghidra_database_updated':False,'whole_firmware_compilable':False}
(b/'readability/validation.json').write_text(json.dumps(stats,indent=2)+'\n');print(json.dumps(stats,indent=2))
