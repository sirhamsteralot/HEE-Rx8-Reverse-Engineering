/* [ADDITIONAL SOURCE REVIEW]
 * knock_retard_clamp [high]: Clamps param to [tbl 0x6af68 (alt 0x6af7c when DAT_ffffb534==1 && 4<DAT_ffffbc3d), tbl 0x6af90](RPM) via rx8_clamp_float and returns it (SH fr0). Export bug fixed by review_knock_loop_labels_apply.py: was void with discarded clamp result.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00013bd2; body bytes: 86; decompiled */

float knock_retard_clamp(float param_1)

{
  undefined **ppuVar1;
  float arg1;
  float arg2;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  if ((DAT_ffffb534 == '\x01') && (4 < DAT_ffffbc3d)) {
    ppuVar1 = &tbl_knock_retard_clamp_min_alt_0006af7c;
  }
  else {
    ppuVar1 = &tbl_knock_retard_clamp_min_0006af68;
  }
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  arg1 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,ppuVar1);
  arg2 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_knock_retard_clamp_max_0006af90);
  return rx8_clamp_float(param_1,arg1,arg2);
}


