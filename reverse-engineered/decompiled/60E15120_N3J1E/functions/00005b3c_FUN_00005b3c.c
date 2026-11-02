/* ROM address: 0x00005b3c; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005b3c (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void cmi10b_tick_isr(void)

{
  ATUII_TSR10_W = 0xb;
  cmi10b_tick_service();
  crank_tick_flag_set();
  crank_edge_period_update();
  return;
}


