/* ROM address: 0x0004a82c; body bytes: 92; decompiled */

uint FUN_0004a82c(void)

{
  uint uVar1;
  
  if (DAT_ffffcda5 == '\x01') {
    FUN_000604dc(0x23,1);
  }
  else if (DAT_ffffcda4 == '\x01') {
    FUN_000604dc(0x23,2);
  }
  if (DAT_ffffcda7 == '\x01') {
    uVar1 = FUN_000604dc(0x24,1);
  }
  else {
    uVar1 = (uint)DAT_ffffcda6;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x24,2);
    }
  }
  return uVar1;
}


