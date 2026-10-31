/* ROM address: 0x0004b982; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004ab3a (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0004b982(void)

{
  if (engine_stopped_latch_ffffa41c == '\x01') {
    if (DAT_ffffce40 != -1) {
      DAT_ffffce40 = DAT_ffffce40 + 1;
    }
  }
  else {
    DAT_ffffce40 = 0;
  }
  return engine_stopped_latch_ffffa41c;
}


