/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00026c3c; body bytes: 64; decompiled */

void FUN_00026c3c(void)

{
  float snapshot_engine_speed_rpm_ffffb548;
  
  if (DAT_ffffb6ba != 0) {
    snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
    DAT_ffffb6a0 = rx8_absolute_difference(engine_speed_rpm_ffffb548,DAT_ffffb6b4);
    DAT_ffffb6ba = 0;
    DAT_ffffb6b4 = snapshot_engine_speed_rpm_ffffb548;
  }
  DAT_ffffb6ba = rx8_add_u16_saturate((int)DAT_ffffb6ba,1);
  return;
}


