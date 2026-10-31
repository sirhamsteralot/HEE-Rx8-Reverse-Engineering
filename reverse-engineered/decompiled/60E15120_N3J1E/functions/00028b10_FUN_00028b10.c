/* ROM address: 0x00028b10; body bytes: 64; decompiled */

uint FUN_00028b10(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffba9c = 0;
    uVar1 = 1;
  }
  else {
    if (399 < DAT_ffffba9c) {
      DAT_ffffba9c = 0;
    }
    uVar1 = (uint)DAT_ffffb69c;
    if (uVar1 == 1) {
      uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffba9c,1);
      DAT_ffffba9c = (ushort)uVar1;
    }
  }
  return uVar1;
}


