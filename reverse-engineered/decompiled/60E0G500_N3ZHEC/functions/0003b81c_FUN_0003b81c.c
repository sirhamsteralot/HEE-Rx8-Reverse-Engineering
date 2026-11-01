/* ROM address: 0x0003b81c; body bytes: 92; decompiled */

uint FUN_0003b81c(void)

{
  uint uVar1;
  
  if (DAT_ffffc5d1 == '\x01') {
    FUN_000604dc(0x71,1);
  }
  else if (DAT_ffffc5d3 == 1) {
    FUN_000604dc(0x71,2);
  }
  if (DAT_ffffc5d2 == '\x01') {
    uVar1 = FUN_000604dc(0x72,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc5d3;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x72,2);
    }
  }
  return uVar1;
}


