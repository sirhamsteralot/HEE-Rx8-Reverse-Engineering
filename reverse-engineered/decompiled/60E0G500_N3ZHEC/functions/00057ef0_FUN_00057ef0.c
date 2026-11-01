/* ROM address: 0x00057ef0; body bytes: 232; decompiled */

int FUN_00057ef0(void)

{
  bool bVar1;
  int unaff_r11;
  byte bVar2;
  
  bVar2 = 0;
  bVar1 = false;
  while ((bVar2 < 99 && (!bVar1))) {
    if (*(short *)(&DAT_0005f8b0 + (uint)bVar2 * 0xc) == DAT_ffffd226) {
      bVar1 = true;
      if ((*(ushort *)(&DAT_0005f8b4 + (uint)bVar2 * 0xc) & DAT_ffffd3f0) == 0) {
        unaff_r11 = FUN_00055112(0x22,0x31);
      }
      else {
        if (DAT_ffffd224 != -0x80) {
          FUN_00057ffc();
        }
        (*(code *)(&PTR_LAB_0005f8b8)[(uint)bVar2 * 3])(0x22);
        if (DAT_ffffd224 == '\0') {
          unaff_r11 = (byte)(&DAT_0005f8b2)[(uint)bVar2 * 0xc] + 3;
        }
        else if (DAT_ffffd224 == -1) {
          FUN_0006895e(0x22);
          unaff_r11 = FUN_00055112(0x22);
        }
      }
    }
    bVar2 = bVar2 + 1;
  }
  if (!bVar1) {
    unaff_r11 = FUN_00055112(0x22,0x31);
  }
  return unaff_r11;
}


