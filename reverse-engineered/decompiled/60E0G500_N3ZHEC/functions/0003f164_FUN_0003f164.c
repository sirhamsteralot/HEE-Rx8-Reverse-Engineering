/* ROM address: 0x0003f164; body bytes: 92; decompiled */

uint FUN_0003f164(void)

{
  uint extraout_r0;
  uint uVar1;
  float fVar2;
  float arg1;
  
  arg1 = DAT_ffffaa1c;
  fVar2 = (float)FUN_0003eb72(DAT_ffff9f70,&DAT_ffff8088);
  fVar2 = rx8_absolute_difference(fVar2,arg1);
  uVar1 = extraout_r0;
  if (((20.0 < fVar2) || (uVar1 = 0x168, 0x168 < DAT_ffffc532)) ||
     ((uVar1 = (uint)DAT_ffffc724, uVar1 == 1 && (arg1 < 50.0)))) {
    DAT_ffffc6be = 1;
  }
  else {
    DAT_ffffc6be = 0;
  }
  return uVar1;
}


