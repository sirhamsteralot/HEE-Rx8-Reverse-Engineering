/* ROM address: 0x00013ecc; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00013e30 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getCoolantBasedTimingDerate__(void)

{
  undefined4 uVar1;
  float fVar2;
  float arg1;
  float arg2;
  
  arg2 = 1.0;
  arg1 = 0.0;
  uVar1 = rx8_decode_u8_affine(0x3f800000,0,(int)DAT_ffffa758);
  DAT_ffffa76c = (float)ref_floatArrayToByteArrayLookup1(uVar1);
  DAT_ffffa770 = (float)ref_floatArrayToByteArrayLookup2(uVar1);
  fVar2 = (float)rx8_divide_with_zero_fallback(inferred_coolant_temperature_ffffa98c - 5.0,0x425c0000);
  fVar2 = rx8_clamp_float(fVar2,arg1,arg2);
  coolant_timing_derate_leading_ffffa750 = DAT_ffffa76c * fVar2;
  coolant_timing_derate_trailing_ffffa754 = DAT_ffffa770 * fVar2;
  return;
}


