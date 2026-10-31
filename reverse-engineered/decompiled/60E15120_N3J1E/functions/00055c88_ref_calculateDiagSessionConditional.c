/* ROM address: 0x00055c88; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00053fa4 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_calculateDiagSessionConditional(void)

{
  if ((engine_stopped_latch_ffffa41c == '\x01') && (DAT_ffffd271 == '\0')) {
    DAT_ffffd1cc = 1;
  }
  else {
    DAT_ffffd1cc = 0;
  }
  return engine_stopped_latch_ffffa41c;
}


