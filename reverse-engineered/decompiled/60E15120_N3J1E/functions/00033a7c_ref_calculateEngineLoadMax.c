/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b1ec: RPM Based Max Engine Load (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00033a7c; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000341f4 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateEngineLoadMax(void)

{
  float fVar1;
  
  if (load_filter_fast_flag_ffffc0c4 != '\0') {
    load_filter_fast_flag_ffffc0c4 = load_filter_fast_flag_ffffc0c4 + -1;
  }
  fVar1 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_rpm_based_max_engine_load_0006b1ec);
  engine_load_max_ffffc0b8 = DAT_ffffc0bc * DAT_ffffc0c0 * fVar1;
  return;
}


