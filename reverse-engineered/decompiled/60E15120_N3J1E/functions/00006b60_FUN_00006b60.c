/* ROM address: 0x00006b60; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006b60 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00006b60(void)

{
  uint uVar1;
  
  if (DAT_ffff9f27 == '\0') {
    uVar1 = (uint)DAT_ffff9f25;
    if (uVar1 == 1) {
      uVar1 = FUN_0000b0a6();
      return uVar1;
    }
  }
  else {
    uVar1 = FUN_0000b1da();
    DAT_ffff9f27 = '\0';
  }
  return uVar1;
}


