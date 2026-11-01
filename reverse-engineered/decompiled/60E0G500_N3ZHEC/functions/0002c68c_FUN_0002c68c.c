/* ROM address: 0x0002c68c; body bytes: 98; decompiled */

void FUN_0002c68c(void)

{
  uint uVar1;
  
  uVar1 = FUN_000070ac(1);
  if ((uVar1 & 0x80) == 0) {
    if (0xf < DAT_ffffbc76) {
      DAT_ffffbc74 = 1;
    }
    DAT_ffffbc76 = FUN_00002460((int)(short)DAT_ffffbc76,1);
    DAT_ffffbc78 = 0;
  }
  else {
    if (0xf < DAT_ffffbc78) {
      DAT_ffffbc74 = 0;
    }
    DAT_ffffbc78 = FUN_00002460((int)(short)DAT_ffffbc78,1);
    DAT_ffffbc76 = 0;
  }
  return;
}


