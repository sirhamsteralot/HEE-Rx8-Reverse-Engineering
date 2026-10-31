/* ROM address: 0x00013ea0; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00013e04 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_debounceThrottleRate(void)

{
  if (DAT_ffffad50 < 2.5) {
    if (DAT_ffffa762 != 0) {
      DAT_ffffa762 = DAT_ffffa762 + -1;
    }
  }
  else {
    DAT_ffffa762 = 7;
  }
  return;
}


