/* ROM address: 0x0004b77c; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004a934 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0004b77c(void)

{
  float fVar1;
  
  fVar1 = rx8_max_float(intake_air_temperature_ffffaddc,5.0);
  ref_updateMemoryAtAddress_float_VAL_ADDR(fVar1,&DAT_ffff8774);
  return;
}


