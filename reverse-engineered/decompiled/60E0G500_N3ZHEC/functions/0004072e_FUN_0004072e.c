/* ROM address: 0x0004072e; body bytes: 92; decompiled */

uint FUN_0004072e(void)

{
  uint uVar1;
  
  if (DAT_ffffc745 == '\x01') {
    FUN_000604dc(0x6e,1);
  }
  else if (DAT_ffffc744 == '\x01') {
    FUN_000604dc(0x6e,2);
  }
  if (DAT_ffffc747 == '\x01') {
    uVar1 = FUN_000604dc(0x6d,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc746;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x6d,2);
    }
  }
  return uVar1;
}


