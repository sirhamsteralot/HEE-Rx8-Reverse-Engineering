/* ROM address: 0x000447b4; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00043fd0 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_000447b4(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffd1c5;
  if ((DAT_ffffd1c5 == '\x01') && (cVar1 = engine_stopped_latch_ffffa41c, engine_stopped_latch_ffffa41c == '\x01')) {
    misfire_rpm_counter_a_ffffcb78 = 0;
    misfire_rpm_counter_b_ffffcb7a = 0;
    misfire_load_counter_a_ffffcb7c = 0;
    misfire_load_counter_b_ffffcb7e = 0;
  }
  return cVar1;
}


