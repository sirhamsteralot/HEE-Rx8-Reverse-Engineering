/* ROM address: 0x00026062; body bytes: 72; decompiled */

void FUN_00026062(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 100.0;
  fVar1 = rx8_clamp_float(DAT_ffffb3a0,0.0,100.0);
  DAT_ffffb5f4 = (int)((fVar1 / fVar2) * 65536.0);
  DAT_ffff9f5a = FUN_0000231c(DAT_ffffb5f4,DAT_ffff9f56);
  return;
}


