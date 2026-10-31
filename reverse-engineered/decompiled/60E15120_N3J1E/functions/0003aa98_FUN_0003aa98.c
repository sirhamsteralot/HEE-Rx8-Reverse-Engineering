/* ROM address: 0x0003aa98; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003aecc (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0003aa98(void)

{
  uint uVar1;
  
  if (DAT_ffffc56a == '\x01') {
    FUN_0005fd38(7,1);
  }
  else if (DAT_ffffc56e == 1) {
    FUN_0005fd38(7,2);
  }
  if (DAT_ffffc56b == '\x01') {
    uVar1 = FUN_0005fd38(8,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc56e;
    if (uVar1 == 1) {
      uVar1 = FUN_0005fd38(8,2);
    }
  }
  return uVar1;
}


