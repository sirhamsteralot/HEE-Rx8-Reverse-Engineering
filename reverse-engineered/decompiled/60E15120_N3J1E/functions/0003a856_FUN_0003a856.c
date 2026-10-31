/* ROM address: 0x0003a856; body bytes: 92; decompiled */

uint FUN_0003a856(void)

{
  uint uVar1;
  
  if (DAT_ffffc55c == '\x01') {
    FUN_0005fd38(0x6f,1);
  }
  else if (DAT_ffffc55e == 1) {
    FUN_0005fd38(0x6f,2);
  }
  if (DAT_ffffc55d == '\x01') {
    uVar1 = FUN_0005fd38(0x70,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc55e;
    if (uVar1 == 1) {
      uVar1 = FUN_0005fd38(0x70,2);
    }
  }
  return uVar1;
}


