/* ROM address: 0x0003ebe4; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003f180 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_0003ebe4(void)

{
  uint uVar1;
  
  uVar1 = ref_getFromGPIO_(0);
  DAT_ffffc6b0 = (uVar1 & 1) == 0;
  uVar1 = ref_getFromGPIO_(0);
  DAT_ffffc6b1 = (uVar1 & 2) == 0;
  return (bool)DAT_ffffc6b1;
}


