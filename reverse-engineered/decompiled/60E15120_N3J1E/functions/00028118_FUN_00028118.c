/* [ADDITIONAL SOURCE REVIEW]
 * misfire_sector_counter [high]: While engine_stopped_latch 0xffffa41c == 0: DAT_ffffba5c saturates up at 0x8000 (rx8_add_u16_saturate 0x2460) and DAT_ffffba6c = max(DAT_ffffb67c - DAT_ffffb680, 0.0) (rx8_max_float 0x23e4). Called from 0x287aa.
 */
/* ROM address: 0x00028118; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00028a60 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void misfire_sector_counter(void)

{
  if (engine_stopped_latch_ffffa41c == '\0') {
    if (DAT_ffffba5c < 0x8000) {
      DAT_ffffba5c = rx8_add_u16_saturate((int)(short)DAT_ffffba5c,1);
    }
    else {
      DAT_ffffba5c = 0x8000;
    }
    DAT_ffffba6c = rx8_max_float(DAT_ffffb67c - DAT_ffffb680,0.0);
  }
  return;
}


