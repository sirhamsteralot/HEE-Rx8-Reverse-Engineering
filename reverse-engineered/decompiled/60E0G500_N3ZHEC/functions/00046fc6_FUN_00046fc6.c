/* ROM address: 0x00046fc6; body bytes: 264; decompiled */

uint FUN_00046fc6(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcc8a = 0;
    DAT_ffffcc8c = '\0';
    DAT_ffffcc84 = 0;
    DAT_ffffcc90 = 0;
    DAT_ffffcc92 = 0;
    uVar1 = 1;
  }
  else {
    if (DAT_ffffcc89 == '\x01') {
      if (DAT_ffffb5c0 - DAT_ffffa7bc < -100.0) {
        DAT_ffffcc90 = 0;
        uVar1 = (uint)DAT_ffffcc84;
        if (0x74 < DAT_ffffcc92) {
          uVar1 = FUN_00002460(uVar1,1);
          DAT_ffffcc92 = 0;
        }
        DAT_ffffcc92 = FUN_00002460((int)(short)DAT_ffffcc92,1);
        DAT_ffffcc84 = (short)uVar1;
        if ((uVar1 & 0xffff) != 0) {
          DAT_ffffcc84 = 0;
          DAT_ffffcc8c = '\x01';
          DAT_ffffcc8a = 0;
        }
      }
      else {
        DAT_ffffcc92 = 0;
        if (7 < DAT_ffffcc90) {
          DAT_ffffcc8a = 1;
          DAT_ffffcc8c = '\0';
          DAT_ffffcc84 = 0;
        }
        DAT_ffffcc90 = FUN_00002460((int)(short)DAT_ffffcc90,1);
      }
    }
    else {
      DAT_ffffcc90 = 0;
      DAT_ffffcc92 = 0;
    }
    if (DAT_ffffcc8c == '\x01') {
      uVar1 = FUN_000604dc(0x3c,1);
      return uVar1;
    }
    uVar1 = (uint)DAT_ffffcc8a;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x3c,2);
      return uVar1;
    }
  }
  return uVar1;
}


