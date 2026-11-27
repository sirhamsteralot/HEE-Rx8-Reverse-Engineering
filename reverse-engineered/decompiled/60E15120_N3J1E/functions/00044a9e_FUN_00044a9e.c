/* [ADDITIONAL SOURCE REVIEW]
 * misfire_threshold_load_lookup [high]: DAT_ffffcb94 = lookup(rpm, tbl_load_limit_a_0006ba0c); DAT_ffffcb98 = lookup(rpm, tbl_load_limit_b_0006ba18) (both 12 cells, axes 0x7c4fc/0x7c55c). Called from 0x287aa.
 * RAM 0xffffcb94 misfire_threshold_load_a (float): Load Limit A lookup (tbl 0x6ba0c) -> DAT_ffffcb94, Load Limit B (0x6ba18) -> DAT_ffffcb98 (0x44a9e); used by 0x4489c as cb94*ba54 < ba58 || cb98*ba54 < ba50.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00044a9e; body bytes: 38; decompiled */

void misfire_threshold_load_lookup(void)

{
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  misfire_threshold_load_a_ffffcb94 = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_load_limit_a_0006ba0c);
  DAT_ffffcb98 = lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_load_limit_b_0006ba18);
  return;
}


