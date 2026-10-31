/* ROM address: 0x0003c502; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003c936 (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0003c502(void)

{
  uint uVar1;
  
  if (DAT_ffffc5d4 == '\x01') {
    FUN_0005fd38(0xc,1);
  }
  else if (DAT_ffffc5d6 == 1) {
    FUN_0005fd38(0xc,2);
  }
  if (DAT_ffffc5d5 == '\x01') {
    uVar1 = FUN_0005fd38(0xd,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc5d6;
    if (uVar1 == 1) {
      uVar1 = FUN_0005fd38(0xd,2);
    }
  }
  return uVar1;
}


