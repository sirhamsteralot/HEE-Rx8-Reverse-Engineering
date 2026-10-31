/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a7f8: Table 3D - 62 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0002cdb2; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d456 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getRPMBasedTorqueAdder(void)

{
  DAT_ffffbcc0 = lookup_3d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,engine_speed_rpm_ffffb548,&tbl_table_3d_62_0006a7f8);
  return;
}


