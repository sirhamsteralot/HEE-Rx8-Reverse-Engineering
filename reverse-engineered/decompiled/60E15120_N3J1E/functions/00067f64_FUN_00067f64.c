/* ROM address: 0x00067f64; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066854 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00067f64(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffddf7;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffddf5, (DAT_ffffddf5 & 0x10) == 0)) {
    DAT_ffffddf7 = 0;
    DAT_ffffddda = 0xff;
    uVar1 = FUN_00067faa();
  }
  return uVar1;
}


