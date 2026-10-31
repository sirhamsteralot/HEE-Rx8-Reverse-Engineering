/* ROM address: 0x00063ada; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000623ca (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063ada(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8d4c._0_2_;
  (&DAT_ffff893a)[uVar1 * 0x34] =
       (&DAT_ffff893a)[uVar1 * 0x34] +
       (((char)(&DAT_ffff890c)[uVar1 * 0x1a] + (char)((ushort)(&DAT_ffff890c)[uVar1 * 0x1a] >> 8)) -
       ((char)((uint)param_1 >> 8) + (char)param_1));
  (&DAT_ffff890c)[uVar1 * 0x1a] = (short)param_1;
  return;
}


