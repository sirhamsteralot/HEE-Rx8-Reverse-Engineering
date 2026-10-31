/* ROM address: 0x0004178c; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00040fc0 (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004178c(void)

{
  uint uVar1;
  
  if (DAT_ffffc912 == '\x01') {
    FUN_0005fd38(3,1);
  }
  else if (DAT_ffffc911 == '\x01') {
    FUN_0005fd38(3,2);
  }
  if (DAT_ffffc914 == '\x01') {
    uVar1 = FUN_0005fd38(4,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc913;
    if (uVar1 == 1) {
      uVar1 = FUN_0005fd38(4,2);
    }
  }
  return uVar1;
}


