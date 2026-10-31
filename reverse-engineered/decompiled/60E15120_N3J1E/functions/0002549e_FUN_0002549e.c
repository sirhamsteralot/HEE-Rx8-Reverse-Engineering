/* ROM address: 0x0002549e; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025d26 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002549e(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 100.0;
  fVar1 = rx8_clamp_float(DAT_ffffb330,0.0,100.0);
  DAT_ffffb584 = (int)((fVar1 / fVar2) * 65536.0);
  DAT_ffff9f5a = rx8_mul_s32_shift16_saturate(DAT_ffffb584,DAT_ffff9f56);
  return;
}


