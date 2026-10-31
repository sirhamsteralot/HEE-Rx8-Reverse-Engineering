/* ROM address: 0x000474fc; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00046588 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000474fc(void)

{
  float fVar1;
  
  if (DAT_ffffccb8 < 0x32) {
    DAT_ffffcc88 = 1.0;
  }
  else if (DAT_ffffccb8 == 0x32) {
    fVar1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&DAT_ffff807c);
    DAT_ffffcc88 = DAT_ffffb4b0 - fVar1;
  }
  else {
    DAT_ffffcc88 = rx8_min_float(11.0,DAT_ffffcc88 + 0.05);
  }
  return;
}


