/* ROM address: 0x00028118; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00028a60 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00028118(void)

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


