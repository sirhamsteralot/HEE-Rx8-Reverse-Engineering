/* ROM address: 0x0003b5a6; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003b9da (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0003b5a6(void)

{
  uint uVar1;
  
  if (DAT_ffffc591 == '\x01') {
    FUN_0005fd38(10,1);
  }
  else if (DAT_ffffc595 == 1) {
    FUN_0005fd38(10,2);
  }
  if (DAT_ffffc592 == '\x01') {
    uVar1 = FUN_0005fd38(0xb,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc595;
    if (uVar1 == 1) {
      uVar1 = FUN_0005fd38(0xb,2);
    }
  }
  return uVar1;
}


