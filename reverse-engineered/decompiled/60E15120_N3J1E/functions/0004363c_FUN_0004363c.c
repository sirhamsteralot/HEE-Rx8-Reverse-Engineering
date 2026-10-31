/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b83c: Table 2D - 273 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0004363c; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042e70 (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004363c(void)

{
  uint uVar1;
  uint extraout_r0;
  float fVar2;
  float fVar3;
  
  uVar1 = (uint)DAT_ffffca44;
  if ((uVar1 == 1) && (uVar1 = 1, 1 < DAT_ffffca3f)) {
    fVar2 = rx8_clamp_float((inferred_coolant_temperature_ffffa98c - -30.0) * 0.01,0.0,1.0);
    fVar3 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_273_0006b83c);
    fVar3 = rx8_min_float(DAT_ffffc9a8,fVar3);
    cold_start_timing_reduction_leading_ffffc9a0 = fVar3 * fVar2;
    uVar1 = extraout_r0;
  }
  else {
    cold_start_timing_reduction_leading_ffffc9a0 = 0.0;
  }
  cold_start_timing_reduction_trailing_ffffc9a4 = cold_start_timing_reduction_leading_ffffc9a0;
  return uVar1;
}


