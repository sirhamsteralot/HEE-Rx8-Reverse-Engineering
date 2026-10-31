/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffa634 leading_timing_with_corrections (float): a640 + a648 clamped into leading_ignition_timing_ffffa630 (0x12300).
 * RAM 0xffffa63c trailing_timing_with_corrections (float): a650 + a658 clamped into trailing_ignition_timing_ffffa638.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00012300; body bytes: 186; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00012380) */

void FUN_00012300(void)

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
  cVar1 = rx8_is_outside_tolerance_band(DAT_ffffa784,0,0x3727c5ac);
  rx8_is_outside_tolerance_band(DAT_ffffbc78,uVar5,uVar3);
  if ((((DAT_ffffaa62 != '\x01') || (cVar1 != '\0')) || (2000.0 <= snapshot_engine_speed_rpm_ffffb548)) ||
     (DAT_ffffce1c != '\x01')) {
    arg0 = trailing_timing_with_corrections_ffffa63c;
    if ((DAT_ffffbbce != '\0') || (DAT_ffffa934 <= 0.0)) goto LAB_00012392;
    pfVar2 = (float *)&DAT_ffffa920;
  }
  else {
    pfVar2 = (float *)&DAT_0006d788;
  }
  arg0 = *pfVar2;
LAB_00012392:
  DAT_ffffa664 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&DAT_000691cc);
  trailing_ignition_timing_ffffa638 = rx8_clamp_float(arg0,DAT_ffffa65c,DAT_ffffa664);
  return;
}


