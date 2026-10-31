/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b200: Table 2D - 223 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b214: Max Load - Barometric Pressure Compensation (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00033ab0; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00034228 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getMaxLoadCompensations(void)

{
  DAT_ffffc0bc = lookup_2d_descriptor_scaled(intake_air_temperature_ffffaddc,&tbl_table_2d_223_0006b200);
  DAT_ffffc0c0 = lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_max_load_barometric_pressure_compensation_0006b214);
  return;
}


