/* ROM address: 0x00043f6e; body bytes: 142; decompiled */

void FUN_00043f6e(void)

{
  char cVar1;
  float arg1;
  float fVar2;
  float fVar3;
  
  fVar2 = DAT_ffffb5b8;
  fVar3 = DAT_ffffca94;
  DAT_ffffca80 = rx8_clamp_float(DAT_ffffb5c8,1.0,150.0);
  arg1 = 0.0;
  cVar1 = FUN_00002440(fVar3,0,0x3727c5ac);
  if (cVar1 != '\0') {
    DAT_ffffca7c = 1000.0 / (fVar3 * 4.0);
  }
  DAT_ffffca78 = DAT_ffffca7c / DAT_ffffca80 - 3.0;
  DAT_ffffca74 = (fVar2 - DAT_ffffcac0) / DAT_ffffca80;
  DAT_ffffca70 = rx8_max_float(DAT_ffffca74,arg1);
  DAT_ffffcac0 = fVar2;
  return;
}


