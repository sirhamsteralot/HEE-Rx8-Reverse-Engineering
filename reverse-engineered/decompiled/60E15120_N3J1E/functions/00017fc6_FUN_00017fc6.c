/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069608: Counter Lookup Unknown (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00017fc6; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00018bc2 (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00017fc6(void)

{
  DAT_ffffa94c = DAT_ffffa938;
  if (((DAT_ffffa938 != 0) || (DAT_ffffa93a != 0)) ||
     ((DAT_ffffa92c <= 0.0 && (DAT_ffffa930 <= 0.0)))) {
    if (DAT_ffffa938 != 0) {
      DAT_ffffa938 = DAT_ffffa938 + -1;
    }
  }
  else {
    DAT_ffffa938 = rx8_lookup_3d_raw_u16(engine_speed_rpm_ffffb548,engine_load_ffffc0b4,&tbl_counter_lookup_unknown_00069608);
  }
  return;
}


