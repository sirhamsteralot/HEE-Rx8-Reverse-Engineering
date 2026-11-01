/* ROM address: 0x0001b940; body bytes: 224; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001c3f0 (224 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateThrottlePedalPercentForSomethingElse_(void)

{
  float fVar1;
  float fVar2;
  float arg0;
  
  fVar1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&inferred_ram_807c_ffff807c_ffff807c);
  fVar1 = DAT_ffffad30 - fVar1;
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&DAT_ffff8084);
  arg0 = 0.0;
  fVar2 = DAT_ffffad34 - fVar2;
  DAT_ffffad38 = rx8_max_float(0.0,fVar1);
  DAT_ffffad3c = rx8_max_float(arg0,fVar2);
  if (DAT_ffffcc98 == '\x01') {
    inferred_throttle_position_ffffad44 = DAT_ffffad3c;
    if (DAT_ffffcc99 == '\x01') {
      inferred_throttle_position_ffffad44 = 20.0;
    }
  }
  else {
    inferred_throttle_position_ffffad44 = DAT_ffffad38;
  }
  DAT_ffffad40 = rx8_max_float(arg0,inferred_throttle_position_ffffad44 - DAT_ffffb2a4);
  fVar1 = (float)rx8_divide_with_zero_fallback(inferred_throttle_position_ffffad44,0x42a80000);
  inferred_ram_ad48_ffffad48_ffffad48 = fVar1 * 100.0;
  DAT_ffffad4c = DAT_ffffad40 - DAT_ffffadac;
  DAT_ffffadac = DAT_ffffada8;
  DAT_ffffada8 = DAT_ffffad40;
  DAT_ffffad50 = inferred_throttle_position_ffffad44 - DAT_ffffad94;
  DAT_ffffad94 = DAT_ffffad90;
  DAT_ffffad90 = inferred_throttle_position_ffffad44;
  return;
}


