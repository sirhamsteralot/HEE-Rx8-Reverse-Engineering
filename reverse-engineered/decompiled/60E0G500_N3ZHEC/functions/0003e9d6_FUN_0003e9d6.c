/* ROM address: 0x0003e9d6; body bytes: 92; decompiled */

uint FUN_0003e9d6(void)

{
  uint uVar1;
  
  if (DAT_ffffc6a0 == '\x01') {
    FUN_000604dc(0x48,1);
  }
  else if (DAT_ffffc6a4 == 1) {
    FUN_000604dc(0x48,2);
  }
  if (DAT_ffffc6a1 == '\x01') {
    uVar1 = FUN_000604dc(0x49,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc6a4;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x49,2);
    }
  }
  return uVar1;
}


