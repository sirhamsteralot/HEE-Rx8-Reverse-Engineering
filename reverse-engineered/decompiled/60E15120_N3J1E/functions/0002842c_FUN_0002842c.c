/* [ADDITIONAL SOURCE REVIEW]
 * misfire_deviation_delay_line [high]: DAT_ffffba58 = DAT_ffffba54; DAT_ffffba54 = DAT_ffffba50; DAT_ffffba4c = DAT_ffffb668 - DAT_ffffb664 (+ DAT_ffffb67c - DAT_ffffb680 when 0x3b < DAT_ffffba5c || 13.133 > DAT_ffffba6c); DAT_ffffba50 = max(0, DAT_ffffba4c). Delay line of the sector-speed deviation (ring copies 0xffffb664-0xffffb680 from 0xffffa390-0xffffa3ac via 0x26940). Called from 0x287aa.
 */
/* ROM address: 0x0002842c; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00028d74 (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

void misfire_deviation_delay_line(void)

{
  DAT_ffffba58 = DAT_ffffba54;
  DAT_ffffba54 = DAT_ffffba50;
  DAT_ffffba4c = DAT_ffffb668 - DAT_ffffb664;
  if ((0x3b < DAT_ffffba5c) || (DAT_ffffba6c < 13.133)) {
    DAT_ffffba4c = (DAT_ffffba4c + DAT_ffffb67c) - DAT_ffffb680;
  }
  DAT_ffffba50 = rx8_max_float(0.0,DAT_ffffba4c);
  return;
}


