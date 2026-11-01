/* ROM address: 0x0003dece; body bytes: 92; decompiled */

uint FUN_0003dece(void)

{
  uint uVar1;
  
  if (DAT_ffffc66c == '\x01') {
    FUN_000604dc(0x15,1);
  }
  else if (DAT_ffffc66d == '\x01') {
    FUN_000604dc(0x15,2);
  }
  if (DAT_ffffc671 == '\x01') {
    uVar1 = FUN_000604dc(0x16,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc672;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x16,2);
    }
  }
  return uVar1;
}


