/* ROM address: 0x00018d68; body bytes: 166; decompiled */

int FUN_00018d68(void)

{
  int extraout_r0;
  int iVar1;
  int extraout_r0_00;
  float fVar2;
  float arg1;
  float fVar3;
  float arg0;
  
  fVar3 = DAT_ffffbc40;
  arg0 = DAT_ffffbd0c;
  fVar2 = rx8_absolute_difference(DAT_ffffbd0c,DAT_ffffbc40);
  arg1 = 0.0;
  if ((((DAT_ffffbc30 == -2) || (DAT_ffffbc33 != '\x01')) || (arg0 < fVar3)) || (fVar2 < 4.9)) {
    DAT_ffffa9b0 = 0.0;
  }
  else {
    DAT_ffffa9b0 = rx8_max_float(arg0 - fVar3,0.0);
  }
  fVar3 = DAT_ffffbb2c;
  fVar2 = rx8_absolute_difference(arg0,DAT_ffffbb2c);
  iVar1 = extraout_r0;
  if (((fVar3 < 400.0) && (fVar3 <= arg0)) &&
     ((4.9 <= fVar2 && (iVar1 = (int)DAT_ffffb5a4, iVar1 == 0)))) {
    arg1 = rx8_max_float(arg0 - fVar3,arg1);
    iVar1 = extraout_r0_00;
  }
  DAT_ffffa9b4 = arg1;
  return iVar1;
}


