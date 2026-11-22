/* ROM address: 0x00018f44; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00019b40 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00018f44(void)

{
  pedal_volts_clamp_latch();
  DAT_ffffa9a0 = pedal_1_volts_clamped25_ffffa99c;
  FUN_00018fa4();
  DAT_ffffa9a8 = DAT_ffffa9a4;
  return;
}


