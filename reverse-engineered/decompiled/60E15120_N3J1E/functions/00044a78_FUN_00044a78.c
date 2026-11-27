/* [ADDITIONAL SOURCE REVIEW]
 * misfire_threshold_rpm_lookup [high]: DAT_ffffcb8c = lookup_2d_scaled(rpm, tbl 0x6b9f4 [12 cells, RPM axis 0x7c43c = 780..8500]); DAT_ffffcb90 = lookup(rpm, tbl 0x6ba00 [12 cells, axis 0x7c49c]). Called from 0x287aa.
 * RAM 0xffffcb8c misfire_threshold_rpm_a (float): RPM-dependent misfire threshold from tbl 0x6b9f4 (12 cells, axis 0x7c43c = 780..8500 rpm); used by 0x447e2 as cb8c*ba44 < ba48. Second threshold DAT_ffffcb90 from tbl 0x6ba00.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00044a78; body bytes: 38; decompiled */

void misfire_threshold_rpm_lookup(void)

{
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  misfire_threshold_rpm_a_ffffcb8c = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&DAT_0006b9f4);
  DAT_ffffcb90 = lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&DAT_0006ba00);
  return;
}


