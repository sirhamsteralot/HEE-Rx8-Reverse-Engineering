#!/usr/bin/env python3
"""Apply bounded, evidence-backed readability changes to canonical analysis C."""
from pathlib import Path
import re,json,csv,zipfile
b=Path(__file__).resolve().parents[1]
if '[READABILITY RECONSTRUCTION]' in (b/'decompiled/firmware_decompiled.c').read_text():
 print('Readability pass already applied; rerun only after a fresh export.');raise SystemExit(0)
out=b/'readability';out.mkdir(exist_ok=True)
backup=b/'backups/pre_readability.zip'
if not backup.exists():
 with zipfile.ZipFile(backup,'w',zipfile.ZIP_DEFLATED) as z:
  for p in (b/'decompiled').rglob('*'):
   if p.is_file():z.write(p,str(p.relative_to(b)))
index=list(csv.DictReader((b/'decompiled/function_index.tsv').open(),delimiter='\t'))
# Scoped identifiers only, preserving original expressions and comparison ordering.
params={
'0000231c':['multiplicand','multiplier'],'0000239c':['delay_count'],
'000023b0':['current','previous','coefficient','snap_threshold'],
'000023dc':['left','right'],'000023e4':['left','right'],'000023f4':['left','right'],
'00002404':['value','lower','upper'],'00002420':['value'],'00002430':['value'],
'00002440':['value','center','tolerance'],'00002460':['left','right'],'00002478':['left','right'],
'00002490':['signal','units_per_count','offset'],'000024d0':['signal','units_per_count','offset'],
'000024c0':['units_per_count','offset','raw_value'],'00002500':['units_per_count','offset','raw_value'],
'00002510':['endpoint_a','endpoint_b','weight_256'],'0003db24':['numerator','denominator'],
'00057a0c':['service','value'],'00057a2e':['service','value'],'000071ea':['transmit_byte']}
local={
'00002490':{'iVar1':'encoded_value','iVar2':'rounded_counts'},'000024d0':{'iVar1':'encoded_value','iVar2':'rounded_counts'},
'00002460':{'uVar1':'sum'},'00002478':{'uVar1':'sum'},'00002440':{'uVar1':'outside_band'},
'000023b0':{'fVar1':'filtered'},'000071ea':{'bVar1':'serial_status','cVar2':'received_byte'},
'00057a0c':{'local_c':'high_byte','uStack_b':'low_byte'},'00057a2e':{'uVar1':'append_result','local_5':'response_byte_storage'},
'0005774c':{'bVar1':'identifier_found','bVar2':'record_index','unaff_r11':'unresolved_response_result'},
'000099b0':{'uVar1':'pending_bits','bVar2':'already_pending','uVar3':'saved_interrupt_mask','puVar4':'pending_register','uVar6':'mailbox_mask','puVar5':'control_register','uVar7':'request_mask'},
'00002068':{'extraout_r3':'unresolved_type_dispatch_result','in_fr2':'unresolved_interpolated_value'},
'000020dc':{'iVar1':'type_code','in_fr2':'unresolved_interpolated_value'}}
combined=b/'decompiled/firmware_decompiled.c';text=combined.read_text();changes=[]
for row in index:
 a=row['address'];p=b/'decompiled'/row['file'];old=p.read_text();anchor='/* ROM address: 0x'+a+';';original_tail=old[old.index(anchor):].strip()
 parts=re.split(r'(/\*.*?\*/)',old,flags=re.S);code=''.join(parts[::2]);mp=dict(local.get(a,{}));actions=[]
 for i,n in enumerate(params.get(a,[]),1):
  if re.search(r'\bparam_'+str(i)+r'\b',code):mp['param_'+str(i)]=n
  elif re.search(r'\barg'+str(i-1)+r'\b',code):mp['arg'+str(i-1)]=n
 # Single-assignment temporaries copied directly from a named global.
 for m in re.finditer(r'\b([ufib]Var\d+)\s*=\s*([A-Za-z_]\w*_ffff[0-9a-f]{4})\s*;',code):
  v,g=m.groups()
  if len(re.findall(r'\b'+v+r'\s*=(?!=)',code))==1 and v not in mp:
   mp[v]='snapshot_'+g
 for i in range(0,len(parts),2):
  for k,v in mp.items():parts[i]=re.sub(r'\b'+k+r'\b',v,parts[i])
 s=''.join(parts)
 if mp:actions.append({'local_names':mp})
 if a in ('00002068','000020dc'):
  dim=2 if a=='00002068' else 3;fn=row['name'];args='float axis_value' if dim==2 else 'float x_value, float y_value'
  s=s.replace(fn+'(int param_1)',fn+'('+args+', const Rx8Table'+str(dim)+'D *table)')
  for x,y in ({'*(byte *)(param_1 + 2)':'table->type_code','*(float *)(param_1 + 0x10)':'table->offset','*(float *)(param_1 + 0xc)':'table->multiplier'} if dim==2 else {'*(char *)(param_1 + 0x10)':'table->type_code','*(float *)(param_1 + 0x18)':'table->offset','*(float *)(param_1 + 0x14)':'table->multiplier'}).items():s=s.replace(x,y)
  actions.append({'signature':'FR4 axis/X; FR5 Y for 3D; R4 descriptor; FR0 result. Verified at 0x2068/0x2658. Internal interpolators still have implicit register ABI; explicit inputs are documented but their use remains hidden in raw helper bodies.'})
 if a=='000099b0':
  s=s.replace('ref_txCAN_EventBased(int param_1)','ref_txCAN_EventBased(const Rx8CanMessageDescriptor *message)')
  s=s.replace('*(char *)(param_1 + 5)','(int8_t)message->mailbox_selector').replace('*(char *)(param_1 + 6)','(int8_t)message->payload_length').replace('*(undefined4 *)(param_1 + 8)','message->payload_address')
  actions.append({'structure':'CAN descriptor; only observed offsets assigned roles.'})
 if a=='0005774c':
  s=s.replace('  bool identifier_found;','  const Rx8DiagnosticRecord *records = RX8_ROM_PTR(Rx8DiagnosticRecord, 0x0005f10c);\n  bool identifier_found;')
  repl={'*(short *)(&DAT_0005f10c + (uint)record_index * 0xc)':'records[record_index].identifier','*(ushort *)(&DAT_0005f110 + (uint)record_index * 0xc)':'records[record_index].availability_mask','(*(code *)(&PTR_FUN_0005f114)[(uint)record_index * 3])':'((Rx8DiagnosticHandler)(uintptr_t)records[record_index].handler_address)','(byte)(&DAT_0005f10e)[(uint)record_index * 0xc]':'records[record_index].response_length','record_index < 99':'record_index < RX8_DIAGNOSTIC_RECORD_COUNT',' + 3;':' + RX8_DIAG_READ_HEADER_SIZE;'}
  for x,y in repl.items():s=s.replace(x,y)
  actions.append({'structure':'12-byte diagnostic records; unknown state/result paths preserved.'})
 if a in ('0005774c','00057858','000567e8'):
  # Scope only code tokens, not evidence comments.
  bits=re.split(r'(/\*.*?\*/)',s,flags=re.S)
  for i in range(0,len(bits),2):bits[i]=re.sub(r'\b0x22\b','RX8_SERVICE_READ_DATA',bits[i]);bits[i]=re.sub(r'\b0x62\b','RX8_POSITIVE_READ_DATA_RESPONSE',bits[i]);bits[i]=re.sub(r'\b0x31\b','RX8_DIAG_IDENTIFIER_REJECTED',bits[i])
  s=''.join(bits);actions.append({'constants':'diagnostic service, response and identifier rejection codes'})
 if a=='000071ea':s=s.replace('(serial_status & 0x40)','(serial_status & RX8_SCI_RDRF)');actions.append({'bitfield':'SCI RDRF status mask'})
 if a in ('00002490','000024d0'):
  limit='RX8_U16_MAX' if a=='00002490' else 'RX8_U8_MAX';s=s.replace('encoded_value = '+('0xffff' if a=='00002490' else '0xff')+';','encoded_value = '+limit+';');actions.append({'constant':'encoded saturation limit'})
 if a=='00057a0c':s=s.replace('undefined4 service,undefined4 value','uint32_t service,uint32_t value');actions.append({'signature':'32-bit service/value containers; only low 16 value bits serialized'})
 if a=='00057a2e':s=s.replace('undefined4 service,undefined1 value','uint32_t service,uint8_t value');actions.append({'signature':'32-bit service container and byte value; return meaning unresolved'})
 if a=='000071ea':s=s.replace('undefined1 transmit_byte','uint8_t transmit_byte');actions.append({'signature':'byte transmit argument; signed receive return preserved'})
 if s!=old:
  note='/* [READABILITY RECONSTRUCTION]\n * Signatures, local names, observed fields and scoped constants refined.\n * See readability/changes.json for evidence and remaining ABI limitations.\n */\n'
  s=s.replace(anchor,note+anchor);newtail=s[s.index(anchor):].strip();assert text.count(original_tail)==1,a;text=text.replace(original_tail,note+newtail,1);p.write_text(s);changes.append({'address':a,'actions':actions})
if '#include "rx8_analysis_types.h"' not in text:text='#include "rx8_analysis_types.h"\n'+text
combined.write_text(text);(b/'named/firmware_named.c').write_text(text.replace('#include "rx8_analysis_types.h"','#include "../decompiled/rx8_analysis_types.h"',1))
(out/'changes.json').write_text(json.dumps(changes,indent=2)+'\n')
print('Changed functions:',len(changes),'local identifiers:',sum(len(ac.get('local_names',{})) for c in changes for ac in c['actions']))
