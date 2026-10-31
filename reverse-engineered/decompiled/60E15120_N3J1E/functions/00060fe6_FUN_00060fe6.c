/* ROM address: 0x00060fe6; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f8d6 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00060fe6(ushort *param_1)

{
  uint uVar1;
  
  if ((byte)(&DAT_ffff8d54)[(uint)*param_1 * 2] == 0x10) {
    uVar1 = FUN_00063098(0);
    return uVar1;
  }
  return (uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2];
}


