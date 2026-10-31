/* ROM address: 0x00028b50; body bytes: 70; decompiled */

uint FUN_00028b50(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffba9e = 0;
    DAT_ffffbaa0 = 1;
    uVar1 = 1;
  }
  else {
    if (1999 < DAT_ffffba9e) {
      DAT_ffffba9e = 0;
    }
    uVar1 = (uint)DAT_ffffb69c;
    if (uVar1 == 1) {
      uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffba9e,1);
      DAT_ffffba9e = (ushort)uVar1;
    }
  }
  return uVar1;
}


