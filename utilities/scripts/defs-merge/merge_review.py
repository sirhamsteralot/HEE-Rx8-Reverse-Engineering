#!/usr/bin/env python3
"""Reproducible upstream/local annotation merge and stock 60E15120 audit."""
from pathlib import Path
import xml.etree.ElementTree as E
import subprocess, json, copy, struct, hashlib, csv, re, collections
OUT=Path(__file__).resolve().parent; W=OUT.parents[1]; B=W/'reverse_engineered/60E15120_N3J1E'
U=W/'RX8Defs/RomRaider/rx8_defs.xml'; L=W/'RX8Defs_Copy/RomRaider/rx8_defs.xml'
def git(repo,*args):return subprocess.check_output(['git','-C',str(W/repo),*args]).decode('utf-8-sig')
def parse(s):return E.fromstring(s)
def blocks(r):return {x.findtext('romid/xmlid'):x for x in r.findall('rom')}
def tables(r):return {x.get('name'):x for x in r.findall('table')}
def sig(x):return (x.tag,dict(x.attrib),(x.text or '').strip(),[sig(c) for c in x])
def dump(name,obj):(OUT/name).write_text(json.dumps(obj,indent=2)+'\n')
def addr(t):return int(t.get('storageaddress','0'),16)
upraw=U.read_text(encoding='utf-8-sig'); up=parse(upraw); local=E.parse(L).getroot()
ancestor=parse(git('RX8Defs_Copy','show','HEAD:RomRaider/rx8_defs.xml'))
old10=parse(git('RX8Defs','show','HEAD~10:RomRaider/rx8_defs.xml'))
merged=copy.deepcopy(up); ub,lb,ab,mb=map(blocks,(up,local,ancestor,merged))
# Save all semantic upstream changes in the requested ten-commit window.
changes=[]
for rid,r in ub.items():
 old=tables(blocks(old10)[rid]) if rid in blocks(old10) else {}; new=tables(r)
 for name in sorted(old.keys()|new.keys()):
  if name not in old or name not in new or sig(old[name])!=sig(new[name]):
   changes.append({'rom':rid,'name':name,'before':E.tostring(old[name],encoding='unicode').strip() if name in old else None,'after':E.tostring(new[name],encoding='unicode').strip() if name in new else None})
dump('upstream_changes.json',changes)
# Local changes are expected to be annotations only. Fail on anything else.
merges=[]; conflicts=[]
def structural(x):
 return (x.tag,{k:v for k,v in x.attrib.items() if not (x.get('type') in ('X Axis','Y Axis') and k=='name')},(x.text or '').strip(),[structural(c) for c in x if c.tag!='description'])
for rid,lr in lb.items():
 ar=ab[rid]; assert structural(lr)==structural(ar),f'Unexpected local structural change in {rid}'
 at=tables(ar); mt=tables(mb[rid]); parent=tables(mb.get(mb[rid].get('base'),mb.get('RX8Base')))
 for lt,ot in zip(lr.findall('table'),ar.findall('table')):
  if sig(lt)==sig(ot):continue
  candidates=[t for t in mt.values() if addr(t)==addr(lt)] if addr(lt) else []
  nt=mt.get(lt.get('name'))
  if nt is None:
   assert len(candidates)==1,(rid,lt.get('name'),'ambiguous rename',sig(lt),sig(ot))
   nt=candidates[0]
  assert addr(nt)==addr(lt)
  row={'rom':rid,'old_name':lt.get('name'),'new_name':nt.get('name'),'data':hex(addr(nt)),'axes':[]}
  for ax in lt.findall('table'):
   typ=ax.get('type'); oa=next((x for x in ot.findall('table') if x.get('type')==typ),None)
   if oa is None or ax.get('name')==oa.get('name'):continue
   na=next(x for x in nt.findall('table') if x.get('type')==typ)
   assert addr(ax)==addr(na)
   base=parent.get(nt.get('name')); ba=next((x for x in base.findall('table') if x.get('type')==typ),None) if base is not None else None
   upstream_name=na.get('name',ba.get('name','Unknown') if ba is not None else 'Unknown')
   if upstream_name in ('Unknown','Value','') or upstream_name==oa.get('name'):
    na.set('name',ax.get('name'));row['axes'].append({'axis':typ,'name':ax.get('name'),'decision':'local inference retained'})
   else:
    row['axes'].append({'axis':typ,'local':ax.get('name'),'upstream':upstream_name,'decision':'explicit upstream label retained; local evidence recorded'})
    if ax.get('name','').replace(' (inferred)','').lower()!=upstream_name.lower():conflicts.append(row['axes'][-1]|{'table':nt.get('name')})
  desc=lt.findtext('description')
  if desc!=ot.findtext('description'):
   nd=nt.find('description')
   if nd is None:nd=E.SubElement(nt,'description')
   nd.text=((nd.text or '')+'\n'+desc).strip()
  merges.append(row)
dump('merge_log.json',merges);dump('axis_conflicts.json',conflicts)
rompath=Path(json.loads((B/'metadata/input.json').read_text())['file']);rom=rompath.read_bytes()
assert hashlib.sha256(rom).hexdigest()==json.loads((B/'metadata/input.json').read_text())['sha256']
target=mb['60E15120']; base=tables(mb['RX8Base']); prior_bydata={addr(t):t for t in ab['60E15120'].findall('table')}
# ROM-specific corrections: only unique pointer/axis matches may override dimensions.
repairs=[]
for t in target.findall('table'):
 bt=base.get(t.get('name'))
 if bt is None:continue
 dim=bt.get('type');axes={x.get('type'):addr(x) for x in t.findall('table')}
 if dim not in ('2D','3D'):continue
 candidates=[];pos=0
 while True:
  pos=rom.find(struct.pack('>I',addr(t)),pos)
  if pos<0:break
  d=pos-(8 if dim=='2D' else 12);pos+=1
  if d<0 or d%4:continue
  if dim=='2D':
   n,ty,_,ax,dp=struct.unpack_from('>HBBII',rom,d);counts=[n];pointers=[ax];expected=list(axes.values())
  else:
   nx,ny,ax,ay,dp,ty=struct.unpack_from('>HHIIIB',rom,d);counts=[nx,ny];pointers=[ax,ay];expected=[axes.get('X Axis'),axes.get('Y Axis')]
  if pointers==expected and ty in (0,4,8,12,16) and all(0<n<1024 and p+4*n<=len(rom) for n,p in zip(counts,pointers)):
   candidates.append((d,counts))
 if len(candidates)==1:
  d,counts=candidates[0];keys=['sizey'] if dim=='2D' else ['sizex','sizey']
  for key,n in zip(keys,counts):
   old=t.get(key,bt.get(key))
   if old!=str(n):
    t.set(key,str(n));repairs.append({'table':t.get('name'),'field':key,'old':old,'new':str(n),'descriptor':hex(d),'basis':'unique ROM data and axis pointer match'})
# Missing target DTC templates can be expressed locally with the upstream byte format.
# Since 2026-11-03 DTC table names carry the standard 5-char OBD code
# ("DTC P0300 Enable/Disable #1"); this script supports ONLY that form — any
# DTC name that does not conform is stale and must be updated first
# (utilities/scripts/defs-merge/relabel_dtc_names.py), so fail loudly instead
# of silently processing legacy raw-hex names.
DTC_NAME_RE=re.compile(r'^DTC [PCBU][0-9A-F]{4} Enable/Disable #\d( \[additional site 0x[0-9A-Fa-f]+\])?$')
def _require_new_dtc_name(name,where):
 if not DTC_NAME_RE.match(name or ''):
  raise ValueError(f'{where}: non-conforming DTC table name {name!r}; expected '
                   f'"DTC <5-char OBD code> Enable/Disable #N" — update the def first '
                   f'(utilities/scripts/defs-merge/relabel_dtc_names.py)')
if 'DTC P0300 Enable/Disable #1' not in base:
 raise KeyError('base block has no "DTC P0300 Enable/Disable #1" template — '
                'base def predates the 2026-11-03 P-code labels; update it first')
_base_dtc_template=base['DTC P0300 Enable/Disable #1']
for t in target.findall('table'):
 if t.get('name','').startswith('DTC '):_require_new_dtc_name(t.get('name'),'target 60E15120')
seen=collections.Counter()
for t in target.findall('table'):
 name=t.get('name');seen[name]+=1
 if name.startswith('DTC ') and (name not in base or seen[name]>1):
  if seen[name]>1:t.set('name',name+' [additional site '+hex(addr(t))+']')
  for k,v in _base_dtc_template.attrib.items():
   if k!='name':t.set(k,v)
  note=E.SubElement(t,'description');note.text='DTC enable/disable byte; identity and enable/disable semantics verified at ROM-binary level (docs/investigations/60E15120_N3J1E/dtc_control_report.md sections 2/5). Additional sites have distinct names to avoid inheritance-key collisions.'
  repairs.append({'table':t.get('name'),'basis':'self-contained upstream DTC byte template; distinct name for duplicate site'})
# This pre-existing entry has no base template. Recover its unique scaled descriptor.
t=next(x for x in target.findall('table') if x.get('name')=='Alternator Diagnostic Voltage Delta to DC')
ax=addr(t.find('table'));hits=[]
for d in range(0,len(rom)-20,4):
 n,ty,_,ap,dp=struct.unpack_from('>HBBII',rom,d)
 if ap==ax and dp==addr(t) and 0<n<1024 and ty in (4,8,12,16):hits.append((d,n,ty))
assert len(hits)==1
addr_d,n,ty=hits[0];scale,offset=struct.unpack_from('>ff',rom,addr_d+12)
t.attrib.update(type='2D',category='Alternator Control',storagetype={4:'uint8',8:'uint16',12:'int8',16:'int16'}[ty],endian='big',sizey=str(n))
E.SubElement(t,'scaling',expression=f'x*{scale!r}+({offset!r})',to_byte=f'(x-({offset!r}))/{scale!r}',format='0.000')
t.find('table').attrib.update(name='Unknown',storagetype='float',endian='big',expression='x',to_byte='x')
E.SubElement(t,'description').text=f'[2026-09-30 review] Layout and affine conversion recovered from unique descriptor {addr_d:#x}; purpose remains the upstream interpretation.'
repairs.append({'table':t.get('name'),'basis':'missing base template recovered from unique ROM descriptor','descriptor':hex(addr_d),'count':n,'scale':scale,'offset':offset})
repaired_structure=structural(target)
dump('definition_repairs.json',repairs)
fnrows=list(csv.DictReader((B/'decompiled/function_index.tsv').open(),delimiter='\t'))
fntexts={r['address']:(B/'decompiled'/r['file']).read_text() for r in fnrows}
refindex=collections.defaultdict(list)
for f,source in fntexts.items():
 for token in set(re.findall(r'\b\w*([0-9a-f]{8})\b',source)):refindex[token].append(f)
audit=[]; renamed=[]; sizes={0:4,4:1,8:2,12:1,16:2}; types={0:'float',4:'uint8',8:'uint16',12:'int8',16:'int16'}
for t in target.findall('table'):
 bt=base.get(t.get('name')); attrs=(dict(bt.attrib) if bt is not None else {})|t.attrib
 row={'name':t.get('name'),'data':hex(addr(t)),'status':'scalar_or_switch'}
 if attrs.get('type') in ('2D','3D'):
  dim=int(attrs['type'][0]); axes={x.get('type'):addr(x) for x in t.findall('table')}; matches=[]
  needle=struct.pack('>I',addr(t));pos=0
  while True:
   pos=rom.find(needle,pos)
   if pos<0:break
   d=pos-(8 if dim==2 else 12);pos+=1
   if d<0 or d%4:continue
   if dim==2:
    n,ty,_,ax,dp=struct.unpack_from('>HBBII',rom,d); counts=[n];pointers=[ax]
    expected=[int(attrs.get('sizey',attrs.get('sizex','0')))]; expected_axes=list(axes.values())
   else:
    nx,ny,ax,ay,dp,ty=struct.unpack_from('>HHIIIB',rom,d);counts=[nx,ny];pointers=[ax,ay]
    expected=[int(attrs.get('sizex','0')),int(attrs.get('sizey','0'))];expected_axes=[axes.get('X Axis'),axes.get('Y Axis')]
   if counts!=expected or pointers!=expected_axes:continue
   if not all(0<n<1024 and 0<p and p+4*n<=len(rom) for n,p in zip(counts,pointers)):continue
   scale,offset=struct.unpack_from('>ff',rom,d+(12 if dim==2 else 20))
   refs=refindex.get(f'{d:08x}',[])
   modes=set()
   for f in refs:
    for line in fntexts[f].splitlines():
     if f'{d:08x}' in line:
      modes.update(re.findall(r'(rx8_lookup_[23]d_raw_u(?:8|16)|lookup_[23]d_descriptor_scaled)\(',line))
   rawtypes={('uint8' if mode.endswith('u8') else 'uint16') for mode in modes if '_raw_' in mode}
   effective_type=next(iter(rawtypes)) if len(rawtypes)==1 and not any('scaled' in mode for mode in modes) else types.get(ty) if any('scaled' in mode for mode in modes) or ty!=0 else None
   matches.append({'descriptor':f'{d:08x}','counts':counts,'axes':[hex(a) for a in pointers],'type_code':ty,'lookup_modes':sorted(modes),'rom_type':effective_type,'xml_type':attrs.get('storagetype'),'type_matches':effective_type==attrs.get('storagetype'),'rom_scale':scale if ty else None,'rom_offset':offset if ty else None,'data_in_bounds':addr(t)+__import__('math').prod(counts)*sizes.get(ty,4)<=len(rom),'referencing_functions':refs})
  row['matches']=matches;row['status']='descriptor_verified' if len(matches)==1 and matches[0]['type_matches'] and matches[0]['data_in_bounds'] else 'needs_review'
  # Record discrepancies without silently changing global base definitions.
  for m in matches:
   sc=t.find('scaling')
   if sc is None and bt is not None:sc=bt.find('scaling')
   expr=sc.get('expression') if sc is not None else None
   if expr and m['type_code']:
    try:
     vals=[eval(expr,{'__builtins__':{}},{'x':x}) for x in (0,1)]
     m['xml_offset']=vals[0];m['xml_scale']=vals[1]-vals[0]
     m['scale_matches_within_0_01_percent']=abs(m['xml_scale']-m['rom_scale'])<=max(1e-10,abs(m['rom_scale'])*0.0001) and abs(vals[0]-m['rom_offset'])<=1e-6
    except (ValueError,SyntaxError,NameError,TypeError):m['scaling_check']='expression not evaluated'
  old=prior_bydata.get(addr(t))
  if old is not None and old.get('name')!=t.get('name'):
   renamed.append(row|{'old_name':old.get('name')})
 audit.append(row)
# Direct call paths establish storage even when raw descriptors do not carry a type.
for t,row in zip(target.findall('table'),audit):
 matches=row.get('matches',[])
 if len(matches)==1 and matches[0]['rom_type'] and not matches[0]['type_matches']:
  m=matches[0];newtype=m['rom_type'];width={'float':4,'uint8':1,'uint16':2,'int8':1,'int16':2}[newtype]
  end=addr(t)+__import__('math').prod(m['counts'])*width
  assert end<=len(rom)
  if newtype=='float':
   import math
   assert all(math.isfinite(struct.unpack_from('>f',rom,a)[0]) for a in range(addr(t),end,4))
  repairs.append({'table':t.get('name'),'field':'storagetype','old':m['xml_type'],'new':newtype,'descriptor':m['descriptor'],'basis':'direct lookup wrapper and ROM descriptor','lookup_modes':m['lookup_modes'],'functions':m['referencing_functions']})
  t.set('storagetype',newtype);m['previous_xml_type']=m['xml_type'];m['xml_type']=newtype;m['type_matches']=True;row['status']='descriptor_verified'
repaired_structure=structural(target)
dump('definition_repairs.json',repairs)
dump('target_table_audit.json',audit);dump('renamed_table_evidence.json',renamed)
# Correct earlier annotations which incorrectly treated padding in raw descriptors as float dispatch.
annotation_corrections=[]
for t,row in zip(target.findall('table'),audit):
 desc=t.find('description')
 if desc is not None and 'matches' in row and len(row['matches'])==1:
  m=row['matches'][0]
  if m['type_code']==0:
   old=desc.text or ''
   mode=', '.join(m['lookup_modes']) or 'no direct call recovered; storage remains unresolved'
   desc.text=re.sub(r'dispatch type 0 \(float32\)', 'type/reserved byte 0 (float only for scaled dispatch; raw wrappers determine their own storage)',old)
   desc.text+=' [2026-09-30 review] Lookup path: '+mode+'. Effective storage: '+str(m['rom_type'] or 'unresolved')+'.'
   annotation_corrections.append({'table':row['name'],'descriptor':m['descriptor'],'lookup_modes':m['lookup_modes'],'effective_storage':m['rom_type']})
dump('annotation_corrections.json',annotation_corrections)

# Keep new interpretations visible in the editor, alongside historical evidence.
findings_path=OUT/'function_findings.json'
findings=json.loads(findings_path.read_text()) if findings_path.exists() else []
for t,row in zip(target.findall('table'),audit):
 notes=[]
 for change in repairs:
  if change['table']==t.get('name'):
   notes.append('Correction: '+json.dumps(change,sort_keys=True))
 for renamed_row in renamed:
  if renamed_row['name']==t.get('name'):
   notes.append('Upstream rename from '+renamed_row['old_name']+'.')
   funcs={f for m in row.get('matches',[]) for f in m['referencing_functions']}
   notes.extend(f['evidence'] for f in findings if f['address'] in funcs)
 if row['status']=='needs_review':notes.append('Review remains open: storage or descriptor correspondence has not been fully established; consult target_table_audit.json.')
 if notes:
  desc=t.find('description')
  if desc is None:desc=E.SubElement(t,'description')
  desc.text=(desc.text or '')+'\n[2026-09-30 review] '+' '.join(notes)
# Check every ROM's inheritance keys and duplicate names; preserve known upstream defects as findings.
issues=[]
for rid,r in mb.items():
 names=[t.get('name') for t in r.findall('table')]
 for n,count in collections.Counter(names).items():
  if count>1:issues.append({'rom':rid,'issue':'duplicate table name','name':n,'count':count})
 parentid=r.get('base')
 if parentid:
  pr=next((p for k,p in mb.items() if k.lower()==parentid.lower()),None)
  if pr is None:issues.append({'rom':rid,'issue':'missing base','base':parentid});continue
  pt=tables(pr)
  for t in r.findall('table'):
   if t.get('name') not in pt and not t.get('type'):issues.append({'rom':rid,'issue':'unresolved inherited table','name':t.get('name')})
dump('inheritance_issues.json',issues)
# Preserve upstream bytes outside the target block, including XML comments.
match=next(m for m in re.finditer(r'<rom\b[^>]*>.*?</rom>',upraw,re.S) if '<xmlid>60E15120</xmlid>' in m[0])
E.indent(target,space='    ');result=upraw[:match.start()]+E.tostring(target,encoding='unicode')+upraw[match.end():]
(OUT/'rx8defs.xml').write_text('\ufeff'+result,encoding='utf-8');E.parse(OUT/'rx8defs.xml')
assert repaired_structure==structural(target)
assert all(r['rom']=='60E15120' for r in merges)
summary={'upstream_commit':git('RX8Defs','rev-parse','HEAD').strip(),'copy_base_commit':git('RX8Defs_Copy','rev-parse','HEAD').strip(),'commits_reviewed':git('RX8Defs','log','-10','--format=%h %s').splitlines(),'source_sha256':{str(p.relative_to(W)):hashlib.sha256(p.read_bytes()).hexdigest() for p in [U,L,rompath]},'prior_storage_annotations_corrected':len(annotation_corrections),'local_tables_merged':len(merges),'local_axes_retained':sum(a['decision'].startswith('local') for r in merges for a in r['axes']),'axis_conflicts':len(conflicts),'target_tables':len(audit),'descriptor_verified':sum(r['status']=='descriptor_verified' for r in audit),'lookup_tables_needing_review':sum(r['status']=='needs_review' for r in audit),'renamed_tables':len(renamed),'inheritance_issues':len(issues),'xml_parse_passed':True,'calibration_changes_limited_to_recorded_target_repairs':True,'target_repairs':len(repairs),'other_rom_blocks_byte_identical_to_upstream':True,'live_RomRaider_tested':False}
dump('validation.json',summary);print(json.dumps(summary,indent=2))
