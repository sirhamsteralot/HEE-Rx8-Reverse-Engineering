/* ROM address: 0x000631fc; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061aec (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000631fc(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8900._0_2_;
  (&DAT_ffff87be)[uVar1 * 0x10] =
       (&DAT_ffff87be)[uVar1 * 0x10] +
       (((char)(&DAT_ffff87b4)[uVar1 * 8] + (char)((ushort)(&DAT_ffff87b4)[uVar1 * 8] >> 8)) -
       ((char)((uint)param_1 >> 8) + (char)param_1));
  (&DAT_ffff87b4)[uVar1 * 8] = (short)param_1;
  return;
}


