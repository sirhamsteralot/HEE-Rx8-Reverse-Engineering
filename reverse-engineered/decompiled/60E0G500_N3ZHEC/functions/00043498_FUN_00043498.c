/* ROM address: 0x00043498; body bytes: 48; decompiled */

uint FUN_00043498(void)

{
  uint uVar1;
  uint extraout_r0;
  
  uVar1 = (uint)DAT_ffffb3c8;
  if (uVar1 == 1) {
    DAT_ffffc9e4 = rx8_min_float(1e+06,DAT_ffffb3c4 + DAT_ffffc9e4);
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffc9e4 = 0.0;
  }
  return uVar1;
}


