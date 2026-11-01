/* ROM address: 0x00025d5c; body bytes: 40; decompiled */

void FUN_00025d5c(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 100.0;
  fVar1 = rx8_clamp_float(DAT_ffffb3c4,0.0,100.0);
  DAT_ffffb5e0 = fVar1 / fVar2;
  FUN_0000b2c0(0);
  return;
}


