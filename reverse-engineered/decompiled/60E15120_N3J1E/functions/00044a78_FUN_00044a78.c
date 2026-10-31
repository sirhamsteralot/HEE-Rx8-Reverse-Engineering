/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00044a78; body bytes: 38; decompiled */

void FUN_00044a78(void)

{
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffcb8c = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&DAT_0006b9f4);
  DAT_ffffcb90 = lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&DAT_0006ba00);
  return;
}


