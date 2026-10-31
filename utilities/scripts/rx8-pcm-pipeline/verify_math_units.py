from pathlib import Path
import json,random,struct
b=Path(__file__).resolve().parents[1];asm=(b/'decompiled/firmware_disassembly.asm').read_text();section=asm[asm.index('0000231c '):asm.index('0000239c ')]
assert section.count('shar r4')==16 and section.count('rotcr r5')==16 and 'dmuls.l r4,r5' in section
rng=random.Random(231);cases=[(-2147483648,-2147483648),(2147483647,2147483647),(-1,1),(-1,65535),(-65536,65536),(65536,65536),(0,123)]
cases += [(rng.randrange(-2**31,2**31),rng.randrange(-2**31,2**31)) for _ in range(10000)]
def signed(x):return x-2**32 if x&2**31 else x
for a,c in cases:
 bits=(a*c)&(2**64-1);hi=bits>>32;lo=bits&0xffffffff
 for _ in range(16):
  carry=hi&1;hi=(signed(hi)>>1)&0xffffffff;lo=(lo>>1)|(carry<<31)
 result=signed(lo)
 if signed(hi)<0:
  if signed(hi)!=-1 or signed(lo)>=0:result=-2**31
 elif hi!=0 or signed(lo)<0:result=2**31-1
 expected=max(-2**31,min(2**31-1,(a*c)//65536));assert result==expected
conv=json.loads((b/'math_units/affine_conversions.json').read_text())
for c in conv:
 for k in ('step','offset'):
  literal=c[k+'_literal']
  actual=struct.unpack('>f',int(literal,16).to_bytes(4,'big'))[0] if literal.startswith('0x') else float(literal)
  assert actual==c[k]
assert 10000/0.25==40000 and (80-(-40))/1==120 and (10-(-64))/.5==148
print('Verified 16 shift pairs,',len(cases),'fixed-point boundary/random cases,',len(conv),'constant pairs, and known unit examples.')
