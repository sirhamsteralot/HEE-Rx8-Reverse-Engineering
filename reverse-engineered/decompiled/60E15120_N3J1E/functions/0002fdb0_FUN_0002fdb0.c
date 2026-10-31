/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006aa48: Estimated Manifold Pressure (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002fdb0; body bytes: 80; decompiled */

void FUN_0002fdb0(void)

{
  float snapshot_DAT_ffffbe00;
  
  DAT_ffffbe18 = (float)lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,engine_load_ffffc0b4,&tbl_estimated_manifold_pressure_0006aa48);
  snapshot_DAT_ffffbe00 = DAT_ffffbe00;
  DAT_ffffbe00 = (float)rx8_divide_with_zero_fallback
                                  ((intake_air_temperature_ffffaddc + 273.0) * DAT_ffffbe18 * DAT_ffffbe1c,0x43960000);
  DAT_ffffbdfc = DAT_ffffbe00 - snapshot_DAT_ffffbe00;
  return;
}


