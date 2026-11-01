/* ROM address: 0x00006d7c; body bytes: 102; decompiled */

byte FUN_00006d7c(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_ffff9f2b == 0xc) {
    bVar1 = DAT_fffff819;
    DAT_fffff819 = bVar1 & 0xdf;
    uVar2 = 0x33;
  }
  else {
    if (DAT_ffff9f2b == 8) {
      bVar1 = DAT_fffff819;
      DAT_fffff819 = bVar1 & 0xdf;
      DAT_fffff818 = 0x23;
      goto LAB_00006dd6;
    }
    if (DAT_ffff9f2b != 4) {
      if (DAT_ffff9f2b != 1) {
        return DAT_ffff9f2b;
      }
      bVar1 = DAT_fffff819;
      DAT_fffff819 = bVar1 & 0xdf;
      DAT_fffff818 = 0x10;
      goto LAB_00006dd6;
    }
    bVar1 = DAT_fffff819;
    DAT_fffff819 = bVar1 & 0xdf;
    uVar2 = 0x13;
  }
  DAT_fffff818 = uVar2;
LAB_00006dd6:
  bVar1 = DAT_fffff819;
  bVar1 = bVar1 & 0x2f | 0x20;
  DAT_fffff819 = bVar1;
  return bVar1;
}


