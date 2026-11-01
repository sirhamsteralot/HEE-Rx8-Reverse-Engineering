/* ROM address: 0x0004fb66; body bytes: 74; decompiled */

uint FUN_0004fb66(void)

{
  uint uVar1;
  undefined4 uVar2;
  byte bVar3;
  
  uVar1 = (uint)DAT_ffffcff1;
  bVar3 = -(((uVar1 & 0x80) == 0) + -1);
  if ((DAT_ffffd041 == '\0') && (uVar1 = (uint)bVar3, uVar1 == 1)) {
    uVar2 = FUN_00003920(0x10);
    DAT_ffffd028 = 0;
    DAT_ffffd02c = 0x3d1ba5e3;
    uVar1 = FUN_00003934(uVar2);
  }
  DAT_ffffd041 = bVar3;
  return uVar1;
}


