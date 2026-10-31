/* ROM address: 0x000620e8; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000609d8 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000620e8(uint param_1,byte param_2,char param_3)

{
  uint uVar1;
  
  uVar1 = (uint)param_2;
  if ((uVar1 == 0x10) || (uVar1 == 0x11)) {
    uVar1 = FUN_00063ecc((int)(char)(&DAT_ffff8d55)[(param_1 & 0xffff) * 2] | 1);
    return uVar1;
  }
  if ((uVar1 == 0x20) && ((param_3 == -0x40 || (param_3 == -0x3f)))) {
    uVar1 = FUN_00063ecc((int)(char)(&DAT_ffff8d55)[(param_1 & 0xffff) * 2] | 2);
    return uVar1;
  }
  return uVar1;
}


