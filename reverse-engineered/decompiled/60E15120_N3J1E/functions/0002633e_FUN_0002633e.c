/* ROM address: 0x0002633e; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00026c62 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002633e(void)

{
  electrical_load_filtered_ffffb5a4 = rx8_first_order_filter(electrical_load_raw_ffffb5e0,electrical_load_filtered_ffffb5a4,0.035335,1e-05);
  return;
}


