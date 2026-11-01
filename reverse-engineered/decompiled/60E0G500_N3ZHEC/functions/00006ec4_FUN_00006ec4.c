/* ROM address: 0x00006ec4; body bytes: 82; decompiled */

byte FUN_00006ec4(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_ffff9f31 == 8) {
    bVar1 = DAT_fffff859;
    DAT_fffff859 = bVar1 & 0xdf;
    uVar2 = 0x2b;
  }
  else {
    if (DAT_ffff9f31 == 4) {
      bVar1 = DAT_fffff859;
      DAT_fffff859 = bVar1 & 0xdf;
      DAT_fffff858 = 0x1b;
      goto LAB_00006f0a;
    }
    if (DAT_ffff9f31 != 1) {
      return DAT_ffff9f31;
    }
    bVar1 = DAT_fffff859;
    DAT_fffff859 = bVar1 & 0xdf;
    uVar2 = 0x18;
  }
  DAT_fffff858 = uVar2;
LAB_00006f0a:
  bVar1 = DAT_fffff859;
  bVar1 = bVar1 & 0x2f | 0x20;
  DAT_fffff859 = bVar1;
  return bVar1;
}


