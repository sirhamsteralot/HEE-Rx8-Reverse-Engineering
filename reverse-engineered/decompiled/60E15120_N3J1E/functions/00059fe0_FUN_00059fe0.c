/* ROM address: 0x00059fe0; body bytes: 38; decompiled */

uint FUN_00059fe0(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (DAT_ffffd25d == 1) {
    if (DAT_ffffd268 == '\0') {
      uVar2 = 2;
    }
    else {
      uVar2 = 1;
    }
    uVar1 = FUN_0005fd38(0x3b,uVar2);
    return uVar1;
  }
  return (uint)DAT_ffffd25d;
}


