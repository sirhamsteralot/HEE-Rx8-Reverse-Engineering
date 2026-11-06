/* [ADDITIONAL SOURCE REVIEW]
 * cmi10b_tick_isr [high]: IVT 0x7fc50+0x2c8 -> trampoline 0x2ec0 -> handler (ROM bytes verified); clears TSR10=0xb then calls 0x75f4/0xd716/0xcf96. Emulator trace on cpu.interrupt(0x2c8): 0x3238->0x5b3c->0x75f4->0x7b58->0xd716->0xcf96->0x3280->rte->idle 0x3dac.
 */
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


