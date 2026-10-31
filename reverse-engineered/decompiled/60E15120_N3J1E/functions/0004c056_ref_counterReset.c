/* ROM address: 0x0004c056; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004b20e (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_counterReset(void)

{
  if (DAT_ffffce98 == '\0') {
    DAT_ffffce93 = 0;
    DAT_ffffce90 = 0;
    DAT_ffffce91 = 0;
    DAT_ffffce92 = 0;
  }
  else {
    if (DAT_ffffce97 == '\0') {
      DAT_ffffce93 = 0;
    }
    if (DAT_ffffce94 == '\0') {
      DAT_ffffce90 = 0;
    }
    if (DAT_ffffce95 == '\0') {
      DAT_ffffce91 = 0;
    }
    if (DAT_ffffce96 == '\0') {
      DAT_ffffce92 = 0;
    }
  }
  return;
}


