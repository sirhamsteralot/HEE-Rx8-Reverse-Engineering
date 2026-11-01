/* ROM address: 0x0003d88e; body bytes: 92; decompiled */

uint FUN_0003d88e(void)

{
  uint uVar1;
  
  if (DAT_ffffc64e == '\x01') {
    FUN_000604dc(0xf,1);
  }
  else if (DAT_ffffc650 == 1) {
    FUN_000604dc(0xf,2);
  }
  if (DAT_ffffc64f == '\x01') {
    uVar1 = FUN_000604dc(0x10,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc650;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x10,2);
    }
  }
  return uVar1;
}


