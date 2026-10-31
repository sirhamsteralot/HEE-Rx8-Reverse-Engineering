/* ROM address: 0x0004681e; body bytes: 264; decompiled */

uint FUN_0004681e(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcc4a = 0;
    DAT_ffffcc4c = '\0';
    DAT_ffffcc44 = 0;
    DAT_ffffcc50 = 0;
    DAT_ffffcc52 = 0;
    uVar1 = 1;
  }
  else {
    if (DAT_ffffcc49 == '\x01') {
      if (DAT_ffffb550 - DAT_ffffa7ac < -100.0) {
        DAT_ffffcc50 = 0;
        uVar1 = (uint)DAT_ffffcc44;
        if (0x74 < DAT_ffffcc52) {
          uVar1 = rx8_add_u16_saturate(uVar1,1);
          DAT_ffffcc52 = 0;
        }
        DAT_ffffcc52 = rx8_add_u16_saturate((int)(short)DAT_ffffcc52,1);
        DAT_ffffcc44 = (short)uVar1;
        if ((uVar1 & 0xffff) != 0) {
          DAT_ffffcc44 = 0;
          DAT_ffffcc4c = '\x01';
          DAT_ffffcc4a = 0;
        }
      }
      else {
        DAT_ffffcc52 = 0;
        if (7 < DAT_ffffcc50) {
          DAT_ffffcc4a = 1;
          DAT_ffffcc4c = '\0';
          DAT_ffffcc44 = 0;
        }
        DAT_ffffcc50 = rx8_add_u16_saturate((int)(short)DAT_ffffcc50,1);
      }
    }
    else {
      DAT_ffffcc50 = 0;
      DAT_ffffcc52 = 0;
    }
    if (DAT_ffffcc4c == '\x01') {
      uVar1 = FUN_0005fd38(0x3c,1);
      return uVar1;
    }
    uVar1 = (uint)DAT_ffffcc4a;
    if (uVar1 == 1) {
      uVar1 = FUN_0005fd38(0x3c,2);
      return uVar1;
    }
  }
  return uVar1;
}


