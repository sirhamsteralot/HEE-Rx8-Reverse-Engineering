#!/usr/bin/env python3
"""Export cleanup: resolve duplicate C identifiers, annotate indirect-jump sites,
and replace the generic decompiler_issues text with observed warning categories.

Evidence for every change is recorded in metadata/export_cleanup.json. The saved
Ghidra database is not modified; a pre-change backup is kept in backups/.
Historical per-function filenames are kept (house convention); index names,
bodies, callgraph and symbols are updated."""
from pathlib import Path
import csv,json,re,zipfile
from collections import Counter
from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
combined_path=b/'decompiled/firmware_decompiled.c'
if '[EXPORT CLEANUP]' in combined_path.read_text():
 raise SystemExit('Export cleanup already applied; rerun only after a fresh export.')
backup=b/'backups/pre_cleanup.zip'
if not backup.exists():
 with zipfile.ZipFile(backup,'w',zipfile.ZIP_DEFLATED) as z:
  for p in (b/'decompiled').rglob('*'):
   if p.is_file():z.write(p,str(p.relative_to(b)))
  z.write(b/'named/firmware_named.c','named/firmware_named.c')
def rows(p):return list(csv.DictReader((b/p).open(),delimiter='\t'))
def write(p,rs):
 with (b/p).open('w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=list(rs[0]),delimiter='\t');w.writeheader();w.writerows(rs)
index=rows('decompiled/function_index.tsv');byaddr={r['address']:r for r in index}
calls=rows('decompiled/callgraph.tsv')
# --- 1. Duplicate function names receive address suffixes (identity convention).
counts=Counter(r['name'] for r in index)
dups={n:[r['address'] for r in index if r['name']==n] for n,k in counts.items() if k>1}
addr2new={a:n.rstrip('_')+'_'+a for n,aa in dups.items() for a in aa}
assert not (set(addr2new.values()) & {r['name'] for r in index}),'new name collision'
caller_targets={}
for r in calls:
 if r['callee'] in addr2new:
  caller_targets.setdefault(r['caller'],{}).setdefault(r['callee_name'],set()).add(r['callee'])
# FUN_00061092 calls both thunks named thunk_FUN_00060c7a. Disassembly evidence:
# jsr at 0x61132 loads ROM32[0x61254]=0x64912 (first C call site in body order),
# jsr at 0x61146 loads ROM32[0x61258]=0x64004 (second C call site).
ORDERED={'00061092':{'thunk_FUN_00060c7a':[addr2new['00064912'],addr2new['00064004']]}}
NOTES={
'00000040':'/* [EXPORT CLEANUP]\n * jmp @r4 at 0x42 is an indirect tail jump through register r4, preceded only by\n'
 ' * a PC-relative constant load into r15. No ROM switch or index data is read, so\n'
 ' * the decompiler warning is expected; the parameter formerly named\n'
 ' * UNRECOVERED_JUMPTABLE has been renamed indirect_target. The producer of r4\n'
 ' * is not established in this dump.\n */\n',
'00001090':'/* [EXPORT CLEANUP]\n * jmp @r4 at 0x1092 is an indirect tail jump through register r4, preceded only\n'
 ' * by a PC-relative constant load into r15. No ROM switch or index data is read,\n'
 ' * so the decompiler warning is expected; the parameter formerly named\n'
 ' * UNRECOVERED_JUMPTABLE has been renamed indirect_target. The producer of r4\n'
 ' * is not established in this dump.\n */\n',
'0000375c':'/* [EXPORT CLEANUP]\n * Computed indirect jump at 0x37ac: slot = incoming r2 + ROM32[0x37c0] (=0x4b34)\n'
 ' * - zero-extended byte at [r13]; target = ROM32[slot]. The sibling path at\n'
 ' * 0x3794-0x379a tail-jumps to ROM32[0x37bc] (=0x3848). Index bounds, record\n'
 ' * layout and pointer-table extent are not established; this stays a computed\n'
 ' * dispatch, not a recovered switch.\n */\n',
'0000420c':'/* [EXPORT CLEANUP]\n * Indirect jump at 0x4214: target = ROM32[0x426c + r0] (table base constant at\n'
 ' * 0x4224 = 0x426c). r0 is decremented by 4 before the jump and the delay slot\n'
 ' * loads the next table word through r2, so consecutive calls walk a chained\n'
 ' * pointer table. Entry count, terminator and incoming-register ABI are not\n'
 ' * established.\n */\n',
'00004218':'/* [EXPORT CLEANUP]\n * Indirect jump at 0x4220: target = ROM32[0x426c + r0] (table base constant at\n'
 ' * 0x4224 = 0x426c). r0 is decremented by 4 before the jump and the delay slot\n'
 ' * loads the next table word through r3, so consecutive calls walk a chained\n'
 ' * pointer table. Entry count, terminator and incoming-register ABI are not\n'
 ' * established.\n */\n',
'000043c8':'/* [EXPORT CLEANUP]\n * Jump-table dispatch at 0x43e6 recovered from ROM data. Cases r1 = 0x00-0x1f\n'
 ' * (range checks at 0x43ca-0x43d2); index byte at ROM[0x43a8 + r1] (32 signed\n'
 ' * bytes at 0x43a8-0x43c7), target = 0x4446 + (signed)byte. Cases 0x00-0x17 land\n'
 ' * in a shar r0 sled (ROM 0x4414-0x4440, byte pair 40 21 repeated, ending in\n'
 ' * rts at 0x4442; the sled lies outside this export\'s decoded instructions),\n'
 ' * giving an arithmetic right shift of r0 by r1 (0-23). Cases 0x18-0x1f land\n'
 ' * in byte/word manipulation stubs at 0x4446-0x44b8. Consistent with a\n'
 ' * variable-shift helper plus extension operations; stub semantics were not\n'
 ' * re-derived.\n */\n',
'000044e0':'/* [EXPORT CLEANUP]\n * Jump-table dispatch at 0x44f6 recovered from ROM data. Cases r1 = 0x00-0x1f\n'
 ' * (range checks at 0x44e2-0x44ea); index byte at ROM[0x44c0 + r1] (32 signed\n'
 ' * bytes at 0x44c0-0x44df), target = 0x450a + (signed)byte. All 32 targets\n'
 ' * (0x450a-0x4576) are decoded instructions forming shlr r0 sleds with periodic\n'
 ' * rts, giving a logical right shift of r0 by r1 (0-31). Out-of-range r1 >= 0x20\n'
 ' * is handled by the branch at 0x4504, not the table.\n */\n',
'00061092':'/* [EXPORT CLEANUP]\n * The two call sites formerly named thunk_FUN_00060c7a were resolved to\n'
 ' * distinct thunks from the disassembly: the jsr at 0x61132 loads\n'
 ' * ROM32[0x61254] = 0x64912 and the jsr at 0x61146 loads ROM32[0x61258] =\n'
 ' * 0x64004. Both tail-jump to FUN_00060c7a; the call-site names now carry the\n'
 ' * thunk addresses.\n */\n',
}
PARAM_RENAMES={'00000040':{'UNRECOVERED_JUMPTABLE':'indirect_target'},
               '00001090':{'UNRECOVERED_JUMPTABLE':'indirect_target'}}
def code_replace(text,mapping):
 """Whole-token replacements outside comments and strings of evidence text."""
 if not mapping:return text
 parts=re.split(r'(/\*.*?\*/|//[^\n]*)',text,flags=re.S)
 pat=re.compile(r'\b(?:'+'|'.join(re.escape(k) for k in sorted(mapping,key=len,reverse=True))+r')\b')
 for i in range(0,len(parts),2):parts[i]=pat.sub(lambda m:mapping[m[0]],parts[i])
 return ''.join(parts)
combined=combined_path.read_text();changed=[]
for r in index:
 a=r['address'];p=b/'decompiled'/r['file'];old=p.read_text();anchor='/* ROM address: 0x'+a+';'
 mapping={}
 for name,targets in caller_targets.get(a,{}).items():
  if len(targets)==1:mapping[name]=addr2new[next(iter(targets))]
 if a in addr2new:mapping[r['name']]=addr2new[a]
 new=code_replace(old,mapping)
 if a in ORDERED:  # rename same-named call sites in body order
  for name,seq in ORDERED[a].items():
   state={'i':0}
   def sub(m):
    i=state['i'];state['i']+=1;return seq[i] if i<len(seq) else m[0]
   parts=re.split(r'(/\*.*?\*/|//[^\n]*)',new,flags=re.S)
   for i in range(0,len(parts),2):parts[i]=re.sub(r'\b'+re.escape(name)+r'\b',sub,parts[i])
   new=''.join(parts)
 new=code_replace(new,PARAM_RENAMES.get(a,{}))
 if new==old and a not in NOTES:continue
 tail_old=old[old.index(anchor):];body_new=new[new.index(anchor):]
 assert combined.count(tail_old)==1,('body not unique in combined listing',a)
 combined=combined.replace(tail_old,(NOTES[a] if a in NOTES else '')+body_new,1)
 p.write_text(new[:new.index(anchor)]+(NOTES[a] if a in NOTES else '')+body_new)
 if a in addr2new:r['name']=addr2new[a]
 changed.append(a)
write('decompiled/function_index.tsv',index)
for r in calls:
 if r['callee'] in addr2new:r['callee_name']=addr2new[r['callee']]  # edges are address-keyed; always unambiguous
write('decompiled/callgraph.tsv',calls)
syms=rows('decompiled/symbols.tsv')
for r in syms:
 if r['address'] in addr2new and r['name'] in dups:r['name']=addr2new[r['address']]
write('decompiled/symbols.tsv',syms)
# --- 2. Specific warning categories replace the generic issue pointer text.
CATEGORIES=[('Removing unreachable block (ram','unreachable_ram_block_removed'),
 ('Could not recover jumptable','jumptable_not_recovered'),
 ('Treating indirect jump as call','indirect_jump_as_call'),
 ('overlap smaller symbols','overlapping_symbol_labels'),
 ('Do nothing block with infinite loop','infinite_loop_block'),
 ('Sanity check requires truncation','jumptable_truncated'),
 ('Could not find normalized switch variable','switch_variable_unmatched'),
 ('Type propagation algorithm not settling','type_propagation_unsettled'),
 ('Restarted to delay deadcode elimination','decompiler_restart_space'),
 ('Heritage AFTER dead removal','heritage_after_dead_removal'),
 ('Control flow encountered bad instruction data','bad_instruction_data'),
 ('Bad instruction - Truncating','control_flow_truncated'),
 ('Removing unreachable block','unreachable_block_removed')]
issues=rows('decompiled/decompiler_issues.tsv');cat_counts=Counter()
warn_re=re.compile(r'/\* WARNING[^*]*?\*/')
for r in issues:
 text=(b/'decompiled'/byaddr[r['address']]['file']).read_text()
 counts=Counter()
 for w in warn_re.findall(text):
  for needle,cat in CATEGORIES:
   if needle in w:counts[cat]+=1;break
 assert counts,('no decompiler warnings found for listed issue',r['address'])
 found=[]
 for needle,cat in CATEGORIES:
  n=counts.get(cat,0)
  if n:found.append(cat+(f' x{n}' if n>1 else ''))
 cat_counts.update(counts)
 suffix=''
 if r['address'] in ('000043c8','000044e0'):suffix='; case table recovered from ROM data (see [EXPORT CLEANUP] note)'
 elif r['address'] in NOTES:suffix='; jump mechanism annotated (see [EXPORT CLEANUP] note)'
 r['name']=byaddr[r['address']]['name'];r['issue']='; '.join(found)+suffix
write('decompiled/decompiler_issues.tsv',issues)
# --- 3. Named view stays a synchronized copy (house convention).
(b/'named/firmware_named.c').write_text(combined.replace('#include "rx8_analysis_types.h"','#include "../decompiled/rx8_analysis_types.h"',1))
combined_path.write_text(combined)
# --- 4. Invariant checks before recording the result.
assert len({r['name'] for r in index})==len(index),'duplicate names remain'
assert {r['file'] for r in index}=={'functions/'+p.name for p in (b/'decompiled/functions').glob('*.c')}
for r in index:
 t=(b/'decompiled'/r['file']).read_text();marker='/* ROM address: 0x'+r['address']+';'
 assert t[t.index(marker):].strip() in combined,('body missing from combined listing',r['address'])
name_by_addr={r['address']:r['name'] for r in index}
for e in calls:assert e['callee_name']==name_by_addr[e['callee']],('callgraph name mismatch',e['callee'])
code_only=re.sub(r'/\*.*?\*/','',combined,flags=re.S)
for old_name in dups:
 assert not re.search(r'\b'+re.escape(old_name)+r'\b',code_only),('old identifier still in code',old_name)
assert 'UNRECOVERED_JUMPTABLE' not in code_only
record={'date':'2026-10-29',
 'duplicate_names':{n:[{'address':a,'new_name':addr2new[a]} for a in aa] for n,aa in dups.items()},
 'call_sites_updated':{c:{n:addr2new[next(iter(ts))] for n,ts in m.items() if len(ts)==1} for c,m in caller_targets.items() if c not in ORDERED},
 'ordered_call_site_resolution':{c:{n:{'sequence':seq,'evidence':'jsr at 0x61132 loads ROM32[0x61254]=0x64912; jsr at 0x61146 loads ROM32[0x61258]=0x64004'} for n,seq in m.items()} for c,m in ORDERED.items()},
 'jump_site_annotations':sorted(NOTES),
 'recovered_jump_tables':{
  '000043c8':{'site':'0x43e6','cases':'r1 0x00-0x1f','index_bytes':'0x43a8-0x43c7','base':'0x4446','sled':'shar r0 at ROM 0x4414-0x4442, outside this export\'s decoded instructions'},
  '000044e0':{'site':'0x44f6','cases':'r1 0x00-0x1f','index_bytes':'0x44c0-0x44df','base':'0x450a','sled':'shlr r0; all 32 targets decoded (0x450a-0x4576)'}},
 'decompiler_issues':{'rows_reclassified':len(issues),'warning_counts':dict(cat_counts)},
 'parameter_renames':{'UNRECOVERED_JUMPTABLE':{'functions':['00000040','00001090'],'new_name':'indirect_target'}},
 'functions_changed':sorted(changed),'ghidra_database_updated':False,
 'validation':{'index_names_unique':True,'index_matches_files':True,'all_bodies_in_combined_listing':True,'callgraph_names_consistent':True,'old_duplicate_identifiers_absent_from_code':True}}
(b/'metadata/export_cleanup.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps({'duplicate_names_resolved':len(dups),'functions_renamed':len(addr2new),'callers_updated':len(caller_targets),'jump_sites_annotated':len(NOTES),'issues_reclassified':len(issues),'files_changed':len(changed)},indent=2))
