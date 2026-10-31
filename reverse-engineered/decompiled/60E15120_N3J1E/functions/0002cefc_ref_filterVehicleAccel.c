/* ROM address: 0x0002cefc; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d5a0 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_filterVehicleAccel(void)

{
  DAT_ffffbccc = rx8_first_order_filter(DAT_ffffbcd0,DAT_ffffbccc,0.5,1e-05);
  return;
}


