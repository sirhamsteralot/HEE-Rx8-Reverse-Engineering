/* ROM address: 0x00025ce4; body bytes: 68; decompiled */

void FUN_00025ce4(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 100.0;
  fVar1 = rx8_clamp_float(DAT_ffffb360,0.0,100.0);
  DAT_ffff9f3c = FUN_0000231c((int)((fVar1 / fVar2) * 65536.0),DAT_ffff9f38);
  return;
}


