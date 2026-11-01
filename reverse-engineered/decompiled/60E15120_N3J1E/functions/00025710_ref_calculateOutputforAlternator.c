/* ROM address: 0x00025710; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025f98 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateOutputforAlternator(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 100.0;
  fVar1 = rx8_clamp_float(inferred_ram_b5ac_ffffb5ac_ffffb5ac,0.0,100.0);
  DAT_ffff9f48 = rx8_mul_s32_shift16_saturate((int)((fVar1 / fVar2) * 65536.0),DAT_ffff9f44);
  return;
}


