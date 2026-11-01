/* ROM address: 0x00029c56; body bytes: 110; decompiled */

byte FUN_00029c56(void)

{
  DAT_ffffbb54 = DAT_ffffbb4d >> 4;
  DAT_ffffbb55 = DAT_ffffbb4e >> 4;
  DAT_ffffbb50 = FUN_000024c0(0x3c23d70a,0x3dcccccc,(int)DAT_ffffbb5a);
  DAT_ffffbb56 = (DAT_ffffbb59 & 0x80) == 0x80;
  DAT_ffffbb57 = (DAT_ffffbb59 & 8) == 8;
  return DAT_ffffbb59 & 8;
}


