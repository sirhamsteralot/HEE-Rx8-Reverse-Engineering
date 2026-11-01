/* ROM address: 0x0001a182; body bytes: 76; decompiled */

void FUN_0001a182(void)

{
  float fVar1;
  float fVar2;
  float arg0;
  
  fVar1 = (float)FUN_0003eb72(0x412db22d,&DAT_ffff8090);
  fVar1 = DAT_ffffaa20 - fVar1;
  fVar2 = (float)FUN_0003eb72(0x412db22d,&DAT_ffff8098);
  arg0 = 0.0;
  fVar2 = DAT_ffffaa28 - fVar2;
  DAT_ffffaa30 = rx8_max_float(0.0,fVar1);
  DAT_ffffaa34 = rx8_max_float(arg0,fVar2);
  return;
}


