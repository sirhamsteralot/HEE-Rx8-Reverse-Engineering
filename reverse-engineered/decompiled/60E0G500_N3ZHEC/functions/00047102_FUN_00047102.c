/* ROM address: 0x00047102; body bytes: 264; decompiled */

uint FUN_00047102(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcc8b = 0;
    DAT_ffffcc8d = '\0';
    DAT_ffffcc86 = 0;
    DAT_ffffcc94 = 0;
    DAT_ffffcc96 = 0;
    uVar1 = 1;
  }
  else {
    if (DAT_ffffcc89 == '\x01') {
      if (200.0 < DAT_ffffb5c0 - DAT_ffffa7bc) {
        DAT_ffffcc94 = 0;
        uVar1 = (uint)DAT_ffffcc86;
        if (0x74 < DAT_ffffcc96) {
          uVar1 = FUN_00002460(uVar1,1);
          DAT_ffffcc96 = 0;
        }
        DAT_ffffcc96 = FUN_00002460((int)(short)DAT_ffffcc96,1);
        DAT_ffffcc86 = (short)uVar1;
        if ((uVar1 & 0xffff) != 0) {
          DAT_ffffcc86 = 0;
          DAT_ffffcc8d = '\x01';
          DAT_ffffcc8b = 0;
        }
      }
      else {
        DAT_ffffcc96 = 0;
        if (7 < DAT_ffffcc94) {
          DAT_ffffcc8b = 1;
          DAT_ffffcc8d = '\0';
          DAT_ffffcc86 = 0;
        }
        DAT_ffffcc94 = FUN_00002460((int)(short)DAT_ffffcc94,1);
      }
    }
    else {
      DAT_ffffcc94 = 0;
      DAT_ffffcc96 = 0;
    }
    if (DAT_ffffcc8d == '\x01') {
      uVar1 = FUN_000604dc(0x3d,1);
      return uVar1;
    }
    uVar1 = (uint)DAT_ffffcc8b;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x3d,2);
      return uVar1;
    }
  }
  return uVar1;
}


