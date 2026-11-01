/* ROM address: 0x0002d9d6; body bytes: 54; decompiled */

void FUN_0002d9d6(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_00002068(DAT_ffffadc0,&DAT_0006ac78);
  fVar2 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006ac64);
  fVar2 = rx8_max_float(fVar2 - DAT_ffffbd24,0.0);
  DAT_ffffbd28 = fVar1 * fVar2;
  return;
}


