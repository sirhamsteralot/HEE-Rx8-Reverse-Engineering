/* ROM address: 0x0002d500; body bytes: 160; decompiled */

void FUN_0002d500(void)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (DAT_ffffbc35 == '\0') {
    uVar3 = 0;
    uVar4 = 0x3f800000;
    bVar1 = FUN_000024d0(0x40800000,0x3f800000,0);
    bVar2 = DAT_ffffbced;
    if (bVar1 < DAT_ffffbced) {
      bVar2 = bVar1;
    }
    bVar1 = FUN_000024d0(0x41980000,uVar4,uVar3);
    if (DAT_ffffbcee <= bVar1) {
      bVar1 = DAT_ffffbcee;
    }
    DAT_ffffbcef = (&DAT_00075d5c)[(short)(ushort)bVar1 * 5 + (uint)bVar2];
    if (4 < DAT_ffffbcef) {
      DAT_ffffbcef = 4;
    }
  }
  else {
    DAT_ffffbcef = 0;
  }
  return;
}


