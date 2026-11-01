/* ROM address: 0x0002d5be; body bytes: 70; decompiled */

void FUN_0002d5be(void)

{
  float fVar1;
  float arg1;
  float fVar2;
  float fVar3;
  
  arg1 = 0.0;
  fVar2 = 4.0;
  fVar3 = DAT_ffffbd14;
  fVar1 = (float)FUN_00002500(0x3f800000,0,(int)DAT_ffffbcef);
  DAT_ffffbce8 = fVar3 * ((-fVar1 + fVar2) / fVar2);
  DAT_ffffbce4 = rx8_max_float(fVar3 - DAT_ffffbce8,arg1);
  return;
}


