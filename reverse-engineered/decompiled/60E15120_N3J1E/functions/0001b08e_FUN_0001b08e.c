/* ROM address: 0x0001b08e; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001bb3e (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001b08e(void)

{
  DAT_ffffad5c = DAT_ffff9f08;
  DAT_ffffad84 = DAT_ffffa222;
  DAT_ffffad30 = DAT_ffffa218;
  if (DAT_ffffadd2 == '\0') {
    DAT_ffffad54 = DAT_ffffa218;
    DAT_ffffadd2 = '\x01';
  }
  else {
    DAT_ffffad54 = rx8_first_order_filter(DAT_ffffa218,DAT_ffffad54,0.25,1e-05);
  }
  return;
}


