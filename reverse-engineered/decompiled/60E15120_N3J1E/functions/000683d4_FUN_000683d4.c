/* ROM address: 0x000683d4; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066cc4 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000683d4(void)

{
  uint uVar1;
  
  uVar1 = (int)DAT_ffffddc8 & 0xf0;
  if (0x3f < uVar1) {
    uVar1 = 0x40;
  }
  return uVar1;
}


