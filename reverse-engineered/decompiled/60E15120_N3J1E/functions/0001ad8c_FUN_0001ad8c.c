/* ROM address: 0x0001ad8c; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001b83c (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

ushort FUN_0001ad8c(void)

{
  ushort uVar1;
  
  uVar1 = (ushort)DAT_ffffbd48;
  if (DAT_ffffbd48 == 1) {
    DAT_ffffad18 = (DAT_ffff9ec8 & 0x20) != 0;
    uVar1 = DAT_ffff9ec8;
    DAT_ffffad1a = DAT_ffffad18;
  }
  return uVar1;
}


