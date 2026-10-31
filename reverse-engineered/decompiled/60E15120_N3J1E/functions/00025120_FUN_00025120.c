/* ROM address: 0x00025120; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000259a8 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00025120(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 100.0;
  fVar1 = rx8_clamp_float(DAT_ffffb2f0,0.0,100.0);
  DAT_ffff9f3c = rx8_mul_s32_shift16_saturate((int)((fVar1 / fVar2) * 65536.0),DAT_ffff9f38);
  return;
}


