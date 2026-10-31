/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000121fc; body bytes: 186; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001227c) */

void FUN_000121fc(void)

{
  char cVar1;
  float *pfVar2;
  undefined4 uVar3;
  float snapshot_engine_speed_rpm_ffffb548;
  undefined4 uVar5;
  float arg0;
  
  uVar5 = 0;
  uVar3 = 0x3727c5ac;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  cVar1 = rx8_is_outside_tolerance_band(DAT_ffffa780,0,0x3727c5ac);
  rx8_is_outside_tolerance_band(DAT_ffffbc78,uVar5,uVar3);
  if ((((DAT_ffffaa62 != '\x01') || (cVar1 != '\0')) || (2000.0 <= snapshot_engine_speed_rpm_ffffb548)) ||
     (DAT_ffffce1c != '\x01')) {
    arg0 = leading_timing_with_corrections_ffffa634;
    if ((DAT_ffffbbce != '\0') || (DAT_ffffa934 <= 0.0)) goto LAB_0001228e;
    pfVar2 = (float *)&DAT_ffffa924;
  }
  else {
    pfVar2 = (float *)&DAT_0006d760;
  }
  arg0 = *pfVar2;
LAB_0001228e:
  DAT_ffffa660 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&DAT_00069190);
  leading_ignition_timing_ffffa630 = rx8_clamp_float(arg0,DAT_ffffa64c,DAT_ffffa660);
  return;
}


