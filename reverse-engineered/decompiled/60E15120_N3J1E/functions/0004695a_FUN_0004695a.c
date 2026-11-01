/* ROM address: 0x0004695a; body bytes: 264; decompiled */

uint FUN_0004695a(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcc4b = 0;
    DAT_ffffcc4d = '\0';
    DAT_ffffcc46 = 0;
    DAT_ffffcc54 = 0;
    DAT_ffffcc56 = 0;
    uVar1 = 1;
  }
  else {
    if (DAT_ffffcc49 == '\x01') {
      if (200.0 < DAT_ffffb550 - inferred_ram_a7ac_ffffa7ac_ffffa7ac) {
        DAT_ffffcc54 = 0;
        uVar1 = (uint)DAT_ffffcc46;
        if (0x74 < DAT_ffffcc56) {
          uVar1 = rx8_add_u16_saturate(uVar1,1);
          DAT_ffffcc56 = 0;
        }
        DAT_ffffcc56 = rx8_add_u16_saturate((int)(short)DAT_ffffcc56,1);
        DAT_ffffcc46 = (short)uVar1;
        if ((uVar1 & 0xffff) != 0) {
          DAT_ffffcc46 = 0;
          DAT_ffffcc4d = '\x01';
          DAT_ffffcc4b = 0;
        }
      }
      else {
        DAT_ffffcc56 = 0;
        if (7 < DAT_ffffcc54) {
          DAT_ffffcc4b = 1;
          DAT_ffffcc4d = '\0';
          DAT_ffffcc46 = 0;
        }
        DAT_ffffcc54 = rx8_add_u16_saturate((int)(short)DAT_ffffcc54,1);
      }
    }
    else {
      DAT_ffffcc54 = 0;
      DAT_ffffcc56 = 0;
    }
    if (DAT_ffffcc4d == '\x01') {
      uVar1 = FUN_0005fd38(0x3d,1);
      return uVar1;
    }
    uVar1 = (uint)DAT_ffffcc4b;
    if (uVar1 == 1) {
      uVar1 = FUN_0005fd38(0x3d,2);
      return uVar1;
    }
  }
  return uVar1;
}


