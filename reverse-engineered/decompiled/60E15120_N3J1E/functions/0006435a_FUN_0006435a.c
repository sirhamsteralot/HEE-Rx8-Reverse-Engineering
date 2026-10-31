/* ROM address: 0x0006435a; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062c4a (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0006435a(ushort *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2];
  if (uVar1 == 0x11) {
    uVar1 = FUN_00062fa0(0x50);
    return uVar1;
  }
  if (((uVar1 == 0x10) || (uVar1 == 0)) &&
     (uVar1 = (uint)(char)*(byte *)(param_1 + 5), *(byte *)(param_1 + 5) < 0x50)) {
    uVar1 = FUN_00062fa0(uVar1 + 1);
    return uVar1;
  }
  return uVar1;
}


