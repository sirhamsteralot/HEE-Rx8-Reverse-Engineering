from pathlib import Path
import re,csv,json,struct,zipfile
b=Path(__file__).resolve().parents[1];out=b/'lookup_family';out.mkdir(exist_ok=True)
index=list(csv.DictReader((b/'decompiled/function_index.tsv').open(),delimiter='\t'));by={r['address']:r for r in index}
combined=b/'decompiled/firmware_decompiled.c'
if '[LOOKUP FAMILY RECONSTRUCTION]' in combined.read_text():print('Already applied');raise SystemExit(0)
with zipfile.ZipFile(b/'backups/pre_lookup_family.zip','w',zipfile.ZIP_DEFLATED) as z:
 for p in (b/'decompiled').rglob('*'):
  if p.is_file():z.write(p,str(p.relative_to(b)))
rom=Path(json.loads((b/'metadata/input.json').read_text())['file']).read_bytes()
assert struct.unpack_from('>5I',rom,0x2098)==(0x2678,0x26b0,0x26d0,0x26f4,0x2690)
assert struct.unpack_from('>5I',rom,0x210c)==(0x253c,0x25c8,0x25f4,0x256c,0x2598)
bodies={};names={};reasons={}
def add(a,n,body,reason):names[a]=n;bodies[a]=body;reasons[a]=reason
add('00002624','rx8_find_axis_index_fraction', '''Rx8AxisPosition rx8_find_axis_index_fraction(uint32_t count, const float *axis, float value)
{
  uint32_t byte_offset = (count - 1u) * 4u;
  float lower = *(const float *)((uintptr_t)axis + byte_offset);
  /* BF after FCMP/GT includes unordered comparisons: do not replace with <=. */
  if (!(lower > value)) return (Rx8AxisPosition){byte_offset >> 2, 0.0f};
  for (;;) {
    if (byte_offset == 0) return (Rx8AxisPosition){0, 0.0f};
    byte_offset -= 4u;
    lower = *(const float *)((uintptr_t)axis + byte_offset);
    if (!(lower > value)) break;
  }
  float upper = *(const float *)((uintptr_t)axis + byte_offset + 4u);
  return (Rx8AxisPosition){byte_offset >> 2, (value - lower) / (upper - lower)};
}
''','0x2624-2656: R0 count/index, R1 axis, FR0 value/fraction. Endpoint paths set FR0=0; interior path divides breakpoint differences. No empty-axis guard is present. Struct return models two hardware outputs, not a native C ABI claim.')
add('00002658','rx8_find_xy_axis_positions','''Rx8MapPosition rx8_find_xy_axis_positions(float x_value, float y_value, const Rx8Table3D *table)
{
  Rx8MapPosition position;
  position.x = rx8_find_axis_index_fraction(table->x_count, RX8_ROM_PTR(float, table->x_axis_address), x_value);
  position.y = rx8_find_axis_index_fraction(table->y_count, RX8_ROM_PTR(float, table->y_axis_address), y_value);
  return position;
}
''','0x2658-2676: first search FR4/X/count+0/axis+4, second FR5/Y/count+2/axis+8; results R2/R3 and FR0/FR1. Both calls required.')
types=[('f32','float',4,'00002678','0000253c'),('u8','uint8_t',1,'000026b0','000025c8'),('u16','uint16_t',2,'000026d0','000025f4'),('s8','int8_t',1,'000026f4','0000256c'),('s16','int16_t',2,'00002690','00002598')]
for suffix,typ,size,a,aa in types:
 name='rx8_interpolate_1d_'+suffix
 add(a,name,f'''float {name}(uint32_t lower_index, const {typ} *values, float fraction)
{{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}}
''',f'{a}: integer extension distinguishes {typ}; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.')
 name3='rx8_interpolate_2axis_'+suffix
 add(aa,name3,f'''float {name3}(uint32_t column_count, const {typ} *values, Rx8MapPosition position)
{{
  /* MULS.W multiplies signed LOW 16-bit operands, not unrestricted size_t. */
  uint32_t row_bytes = column_count * {size}u;
  int32_t signed_row_offset = (int32_t)(int16_t)row_bytes * (int32_t)(int16_t)position.y.index;
  const {typ} *row = (const {typ} *)((uintptr_t)values + (uint32_t)signed_row_offset);
  float lower_row = {name}(position.x.index, row, position.x.fraction);
  if (position.y.fraction == 0.0f) return lower_row;
  const {typ} *next_row = (const {typ} *)((uintptr_t)row + row_bytes);
  float difference = {name}(position.x.index, next_row, position.x.fraction) - lower_row;
  return rx8_sh_fmac_model(position.y.fraction, difference, lower_row);
}}
''',f'{aa}: signed low-word row offset, two calls to {a}, second only if Y fraction nonzero; final FR2. No row-bound checks added.')
# Lookup entry points now explicitly connect search outputs to interpolation inputs.
for dim,a in [(2,'00002068'),(3,'000020dc')]:
 n=by[a]['name'];args='float axis_value' if dim==2 else 'float x_value, float y_value'
 code=f'float {n}({args}, const Rx8Table{dim}D *table)\n{{\n'
 code+=('  Rx8AxisPosition position = rx8_find_axis_index_fraction(table->axis_count, RX8_ROM_PTR(float, table->axis_address), axis_value);\n' if dim==2 else '  Rx8MapPosition position = rx8_find_xy_axis_positions(x_value, y_value, table);\n')
 code+='  float interpolated;\n  switch (table->type_code) {\n'
 for k,(suffix,typ,size,_,__) in enumerate(types):
  call=(f'rx8_interpolate_1d_{suffix}(position.index, RX8_ROM_PTR({typ}, table->data_address), position.fraction)' if dim==2 else f'rx8_interpolate_2axis_{suffix}(table->x_count, RX8_ROM_PTR({typ}, table->data_address), position)')
  code+=f'    case {k*4}: interpolated = {call}; break;\n'
 code+=f'    default: return rx8_unresolved_table_dispatch_{dim}d(table->type_code);\n  }}\n'
 code+='  if (table->type_code == 0) return interpolated;\n  return rx8_sh_fmac_model(table->multiplier, interpolated, table->offset);\n}\n'
 add(a,n,code,'Dispatch pointers verified directly at 0x2098/0x210c. Type values are byte offsets 0,4,8,12,16. Unknown dispatch values remain an unresolved operation, not an invented error/default value.')
# Direct unsigned wrappers use dedicated interpolation and truncation, not scaling.
for dim,a,suffix,bits in [(2,'000020ac','u8',8),(2,'000020c4','u16',16),(3,'00002120','u8',8),(3,'0000213c','u16',16)]:
 n=f'rx8_lookup_{dim}d_raw_{suffix}';args='float axis_value' if dim==2 else 'float x_value, float y_value'
 setup=('Rx8AxisPosition position = rx8_find_axis_index_fraction(table->axis_count, RX8_ROM_PTR(float, table->axis_address), axis_value);' if dim==2 else 'Rx8MapPosition position = rx8_find_xy_axis_positions(x_value, y_value, table);')
 call=(f'rx8_interpolate_1d_{suffix}(position.index, RX8_ROM_PTR(uint{bits}_t, table->data_address), position.fraction)' if dim==2 else f'rx8_interpolate_2axis_{suffix}(table->x_count, RX8_ROM_PTR(uint{bits}_t, table->data_address), position)')
 add(a,n,f'uint32_t {n}({args}, const Rx8Table{dim}D *table)\n{{\n  {setup}\n  float interpolated = {call};\n  return (uint{bits}_t)rx8_sh_ftrc_model(interpolated);\n}}\n','Wrapper uses FTRC then EXTU.B/W. Exceptional conversion left to explicitly unresolved SH operation; no C undefined float-to-int replacement.')
# Unique old names can be replaced globally; ambiguous duplicate names require caller-aware mapping.
oldgroups={}
for r in index:oldgroups.setdefault(r['name'],[]).append(r['address'])
unique={by[a]['name']:n for a,n in names.items() if len(oldgroups[by[a]['name']])==1}
records=[];text=combined.read_text()
for r in index:
 a=r['address'];p=b/'decompiled'/r['file'];old=p.read_text();anchor='/* ROM address: 0x'+a+';';oldtail=old[old.index(anchor):].strip();s=old
 if a in bodies:
  name=by[a]['name'];match=re.search(r'\b(?:float|uint|uint32_t|undefined[1248]|int|ulonglong|ushort|byte)\s+'+re.escape(name)+r'\(',s);assert match,a
  s=s[:match.start()]+'/* [LOOKUP FAMILY RECONSTRUCTION]\n * '+reasons[a]+'\n * Explicit register-result structs are an analysis representation.\n */\n'+bodies[a]+'\n'
  records.append({'address':a,'Old name':name,'New name':names[a],'Confidence':'High: ordinary valid table behavior and register roles','Reason':reasons[a],'Evidence':'firmware_disassembly.asm at '+a+'; callgraph.tsv; ROM dispatch pointers','Remaining uncertainty':'Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.'})
 parts=re.split(r'(/\*.*?\*/)',s,flags=re.S)
 for i in range(0,len(parts),2):
  for oldname,newname in unique.items():parts[i]=re.sub(r'\b'+re.escape(oldname)+r'\b',newname,parts[i])
 s=''.join(parts)
 if s!=old:
  assert text.count(oldtail)==1,a;text=text.replace(oldtail,s[s.index(anchor):].strip(),1);p.write_text(s)
# Non-code labels referring to ambiguous interpolation names retain address-based evidence.
combined.write_text(text);(b/'named/firmware_named.c').write_text(text.replace('#include "rx8_analysis_types.h"','#include "../decompiled/rx8_analysis_types.h"',1))
for r in index:
 if r['address'] in names:r['name']=names[r['address']]
def write(path,rows):
 with path.open('w') as f:w=csv.DictWriter(f,fieldnames=list(rows[0]),delimiter='\t');w.writeheader();w.writerows(rows)
write(b/'decompiled/function_index.tsv',index)
for file in ['callgraph.tsv','symbols.tsv']:
 rows=list(csv.DictReader((b/'decompiled'/file).open(),delimiter='\t'))
 for r in rows:
  a=r.get('callee',r.get('address'));col='callee_name' if file=='callgraph.tsv' else 'name'
  if a in names and (file=='callgraph.tsv' or r[col] in oldgroups):r[col]=names[a]
 write(b/'decompiled'/file,rows)
(out/'analysis_record.json').write_text(json.dumps(records,indent=2)+'\n')
print('Reconstructed functions:',len(records))
