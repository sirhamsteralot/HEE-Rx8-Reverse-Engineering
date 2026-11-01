/* ROM address: 0x0003c4f6; body bytes: 92; decompiled */

uint FUN_0003c4f6(void)

{
  uint uVar1;
  
  if (DAT_ffffc601 == '\x01') {
    FUN_000604dc(10,1);
  }
  else if (DAT_ffffc605 == 1) {
    FUN_000604dc(10,2);
  }
  if (DAT_ffffc602 == '\x01') {
    uVar1 = FUN_000604dc(0xb,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc605;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0xb,2);
    }
  }
  return uVar1;
}


