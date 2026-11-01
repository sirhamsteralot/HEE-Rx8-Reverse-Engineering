/* ROM address: 0x0003b9e8; body bytes: 92; decompiled */

uint FUN_0003b9e8(void)

{
  uint uVar1;
  
  if (DAT_ffffc5da == '\x01') {
    FUN_000604dc(7,1);
  }
  else if (DAT_ffffc5de == 1) {
    FUN_000604dc(7,2);
  }
  if (DAT_ffffc5db == '\x01') {
    uVar1 = FUN_000604dc(8,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc5de;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(8,2);
    }
  }
  return uVar1;
}


