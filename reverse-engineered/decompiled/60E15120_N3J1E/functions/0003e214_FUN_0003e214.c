/* ROM address: 0x0003e214; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003e7b0 (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0003e214(void)

{
  uint extraout_r0;
  uint uVar1;
  float fVar2;
  float arg1;
  
  arg1 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(coolant_temperature_ffff9f70,&DAT_ffff8060);
  fVar2 = rx8_absolute_difference(fVar2,arg1);
  uVar1 = extraout_r0;
  if (((20.0 < fVar2) || (uVar1 = 0x168, 0x168 < DAT_ffffc4c2)) ||
     ((uVar1 = (uint)DAT_ffffc6b4, uVar1 == 1 && (arg1 < 50.0)))) {
    DAT_ffffc64e = 1;
  }
  else {
    DAT_ffffc64e = 0;
  }
  return uVar1;
}


