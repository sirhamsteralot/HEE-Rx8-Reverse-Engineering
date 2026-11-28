/* [ADDITIONAL SOURCE REVIEW]
 * misfire_deviation_delay_line [high]: DAT_ffffba58 = DAT_ffffba54; DAT_ffffba54 = DAT_ffffba50; DAT_ffffba4c = DAT_ffffb668 - DAT_ffffb664 (+ DAT_ffffb67c - DAT_ffffb680 when 0x3b < DAT_ffffba5c || 13.133 > DAT_ffffba6c); DAT_ffffba50 = max(0, DAT_ffffba4c). Delay line of the sector-speed deviation (ring copies 0xffffb664-0xffffb680 from 0xffffa390-0xffffa3ac via 0x26940). Called from 0x287aa.
 * RAM 0xffffba50 misfire_deviation_now (float): DAT_ffffba50 = max(0, DAT_ffffba4c): current sector-speed deviation (0x2842c); secondary arm threshold vs ba80 (0x28022) and sustained window bound (0x44436).
 * RAM 0xffffba54 misfire_deviation_d1 (float): One-tick-delayed copy of DAT_ffffba50 (0x2842c: ba54 = ba50, ba58 = ba54); load-threshold check operand in 0x4489c.
 * RAM 0xffffba58 misfire_deviation_d2 (float): Two-tick-delayed copy of DAT_ffffba50 (0x2842c); load-threshold check operand in 0x4489c (cb94*ba54 < ba58).
 */
/* ROM address: 0x0002842c; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00028d74 (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

void misfire_deviation_delay_line(void)

{
  misfire_deviation_d2_ffffba58 = misfire_deviation_d1_ffffba54;
  misfire_deviation_d1_ffffba54 = misfire_deviation_now_ffffba50;
  DAT_ffffba4c = DAT_ffffb668 - misfire_sector_ring_copy_ffffb664;
  if ((0x3b < DAT_ffffba5c) || (DAT_ffffba6c < 13.133)) {
    DAT_ffffba4c = (DAT_ffffba4c + DAT_ffffb67c) - DAT_ffffb680;
  }
  misfire_deviation_now_ffffba50 = rx8_max_float(0.0,DAT_ffffba4c);
  return;
}


