/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a6d8: Rotor 1 Ignition Dwell (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a6ec: Rotor 2 Ignition Dwell (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002bc34; body bytes: 38; decompiled */

void FUN_0002bc34(void)

{
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffbc1c = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_rotor_1_ignition_dwell_0006a6d8);
  DAT_ffffbc20 = lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_rotor_2_ignition_dwell_0006a6ec);
  return;
}


