/* ROM address: 0x00042ef6; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004272a (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_engineLoad2ndOrderLowPass(void)

{
  DAT_ffffc9d8 = ((DAT_ffffc9ec * DAT_ffffc9dc - DAT_ffffca54 * DAT_ffffc9dc) -
                 DAT_ffffc9e0 * DAT_ffffca58) - DAT_ffffc9e4 * DAT_ffffca5c;
  DAT_ffffca54 = DAT_ffffc9ec;
  DAT_ffffca5c = DAT_ffffca58;
  DAT_ffffca58 = DAT_ffffc9d8;
  return;
}


