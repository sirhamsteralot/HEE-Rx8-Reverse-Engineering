/* [ADDITIONAL SOURCE REVIEW]
 * trailing_final_timing_clamp_output [high]: Trailing mirror: a638 = rx8_clamp_float(a63c, a65c, a664); a664 = lookup_2d(rpm, tbl 0x691cc). Output RAM trailing_ignition_timing_ffffa638.
 * RAM 0xffffa634 leading_timing_with_corrections (float): a640 + a648 clamped into leading_ignition_timing_ffffa630 (0x12300).
 * RAM 0xffffa63c trailing_timing_with_corrections (float): a650 + a658 clamped into trailing_ignition_timing_ffffa638.
 * RAM 0xffffa664 trailing_max_advance (float): 
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00012300; body bytes: 186; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00012380) */

void trailing_final_timing_clamp_output(void)

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
  cVar1 = rx8_is_outside_tolerance_band(idle_base_timing_trailing_ffffa784,0,0x3727c5ac);
  rx8_is_outside_tolerance_band(DAT_ffffbc78,uVar5,uVar3);
  if ((((cranking_active_ffffaa62_ffffaa62 != '\x01') || (cVar1 != '\0')) || (2000.0 <= snapshot_engine_speed_rpm_ffffb548)) ||
     (inferred_ram_ce1c_ffffce1c_ffffce1c != '\x01')) {
    arg0 = trailing_timing_with_corrections_ffffa63c;
    if ((DAT_ffffbbce != '\0') || (DAT_ffffa934 <= 0.0)) goto LAB_00012392;
    pfVar2 = (float *)&DAT_ffffa920;
  }
  else {
    pfVar2 = (float *)&DAT_0006d788;
  }
  arg0 = *pfVar2;
LAB_00012392:
  trailing_max_advance_ffffa664 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&candidate_tbl_max_advance_vs_rpm_trailing_000691cc);
  trailing_ignition_timing_ffffa638 = rx8_clamp_float(arg0,trailing_min_advance_clamp_ffffa65c,trailing_max_advance_ffffa664);
  return;
}


