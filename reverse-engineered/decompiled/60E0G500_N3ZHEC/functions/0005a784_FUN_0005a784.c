/* ROM address: 0x0005a784; body bytes: 38; decompiled */

uint FUN_0005a784(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (DAT_ffffd299 == 1) {
    if (DAT_ffffd2a4 == '\0') {
      uVar2 = 2;
    }
    else {
      uVar2 = 1;
    }
    uVar1 = FUN_000604dc(0x3b,uVar2);
    return uVar1;
  }
  return (uint)DAT_ffffd299;
}


