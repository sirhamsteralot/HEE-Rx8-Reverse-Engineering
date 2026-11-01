/* ROM address: 0x0003db8a; body bytes: 92; decompiled */

uint FUN_0003db8a(void)

{
  uint uVar1;
  
  if (DAT_ffffc659 == '\x01') {
    FUN_000604dc(0x11,1);
  }
  else if (DAT_ffffc65b == 1) {
    FUN_000604dc(0x11,2);
  }
  if (DAT_ffffc65a == '\x01') {
    uVar1 = FUN_000604dc(0x12,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc65b;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x12,2);
    }
  }
  return uVar1;
}


