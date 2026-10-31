/* ROM address: 0x0003820e; body bytes: 76; decompiled */

uint FUN_0003820e(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = 0.0;
  fVar2 = DAT_ffffc4d8 - DAT_ffffc4dc;
  uVar1 = rx8_is_outside_tolerance_band(0x47aba980,0,0x3727c5ac);
  DAT_ffffc4d4 = fVar3;
  if ((uVar1 & 0xff) != 0) {
    DAT_ffffc4d4 = fVar2 / 87891.0;
  }
  DAT_ffffc4d0 = DAT_ffffc4d0 + DAT_ffffc4d4;
  return uVar1;
}


