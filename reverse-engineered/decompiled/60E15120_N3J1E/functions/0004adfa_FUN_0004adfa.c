/* ROM address: 0x0004adfa; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00049db6 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0004adfa(void)

{
  if (engine_injectors_off_ffffa42c == '\x01') {
    DAT_ffffcddb = '\0';
  }
  else if (DAT_ffffcddb != '\0') {
    DAT_ffffcddb = DAT_ffffcddb + -1;
  }
  return engine_injectors_off_ffffa42c;
}


