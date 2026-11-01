/* ROM address: 0x000262d4; body bytes: 68; decompiled */

void FUN_000262d4(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 100.0;
  fVar1 = rx8_clamp_float(DAT_ffffb61c,0.0,100.0);
  DAT_ffff9f48 = FUN_0000231c((int)((fVar1 / fVar2) * 65536.0),DAT_ffff9f44);
  return;
}


