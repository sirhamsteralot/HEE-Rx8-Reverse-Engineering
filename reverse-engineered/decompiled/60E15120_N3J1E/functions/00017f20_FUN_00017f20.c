/* ROM address: 0x00017f20; body bytes: 166; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00018b1c (166 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00017f20(void)

{
  int extraout_r0;
  int iVar1;
  int extraout_r0_00;
  float fVar2;
  float arg1;
  float fVar3;
  float arg0;
  
  fVar3 = DAT_ffffbbd8;
  arg0 = DAT_ffffbca0;
  fVar2 = rx8_absolute_difference(DAT_ffffbca0,DAT_ffffbbd8);
  arg1 = 0.0;
  if ((((DAT_ffffbbc8 == -2) || (DAT_ffffbbcb != '\x01')) || (arg0 < fVar3)) || (fVar2 < 4.9)) {
    DAT_ffffa92c = 0.0;
  }
  else {
    DAT_ffffa92c = rx8_max_float(arg0 - fVar3,0.0);
  }
  fVar3 = DAT_ffffbac4;
  fVar2 = rx8_absolute_difference(arg0,DAT_ffffbac4);
  iVar1 = extraout_r0;
  if (((fVar3 < 400.0) && (fVar3 <= arg0)) &&
     ((4.9 <= fVar2 && (iVar1 = (int)DAT_ffffb534, iVar1 == 0)))) {
    arg1 = rx8_max_float(arg0 - fVar3,arg1);
    iVar1 = extraout_r0_00;
  }
  DAT_ffffa930 = arg1;
  return iVar1;
}


