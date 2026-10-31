/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ba0c: Load Limit A (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ba18: Load Limit B (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00044a9e; body bytes: 38; decompiled */

void FUN_00044a9e(void)

{
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffcb94 = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_load_limit_a_0006ba0c);
  DAT_ffffcb98 = lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_load_limit_b_0006ba18);
  return;
}


