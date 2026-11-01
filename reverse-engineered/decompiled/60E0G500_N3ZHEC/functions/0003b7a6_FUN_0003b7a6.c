/* ROM address: 0x0003b7a6; body bytes: 92; decompiled */

uint FUN_0003b7a6(void)

{
  uint uVar1;
  
  if (DAT_ffffc5cc == '\x01') {
    FUN_000604dc(0x6f,1);
  }
  else if (DAT_ffffc5ce == 1) {
    FUN_000604dc(0x6f,2);
  }
  if (DAT_ffffc5cd == '\x01') {
    uVar1 = FUN_000604dc(0x70,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc5ce;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x70,2);
    }
  }
  return uVar1;
}


