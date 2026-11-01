/* [ADDITIONAL SOURCE REVIEW]
 * min_advance_clamp_select [high]: Selects leading min-advance clamp a64c: cranking && a66c in band -> -25.0 (0xc1c80000, ROM-verified); !cranking && a750,c9a0 in band, or load-high -> -58.5 (0xc26a0000, ROM-verified); else lookup_2d(a98c, tbl 0x691b8); cranking with a66c out of band -> lookup_2d(a98c, tbl 0x691a4). Also sets load-high flag a66a (c0b4 > 0.5, hysteresis clears <= 0.45).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00012630; body bytes: 206; decompiled */

uint min_advance_clamp_select(void)

{
  char cVar2;
  char cVar3;
  char cVar4;
  uint uVar1;
  undefined4 extraout_fr0;
  undefined4 extraout_fr0_00;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 snapshot_inferred_coolant_temperature_ffffa98c;
  float snapshot_engine_load_ffffc0b4;
  
  uVar5 = 0;
  uVar6 = 0x3727c5ac;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  cVar2 = rx8_is_outside_tolerance_band(coolant_timing_derate_leading_ffffa750,0,0x3727c5ac);
  cVar3 = rx8_is_outside_tolerance_band(DAT_ffffa66c,uVar5,uVar6);
  cVar4 = rx8_is_outside_tolerance_band(cold_start_timing_reduction_leading_ffffc9a0,uVar5,uVar6);
  if (snapshot_engine_load_ffffc0b4 <= 0.5) {
    if (snapshot_engine_load_ffffc0b4 <= 0.45) {
      DAT_ffffa66a = '\0';
    }
  }
  else {
    DAT_ffffa66a = '\x01';
  }
  uVar1 = (uint)cranking_active_ffffaa62_ffffaa62;
  if (uVar1 == 1) {
    if (cVar3 == '\0') {
      leading_min_advance_clamp_ffffa64c = 0xc1c80000;
      uVar1 = 0;
    }
    else {
      uVar1 = lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&candidate_tbl_min_advance_vs_coolant_a_000691a4);
      leading_min_advance_clamp_ffffa64c = extraout_fr0;
    }
  }
  else if ((cVar4 == '\0') && (cVar2 == '\0')) {
    leading_min_advance_clamp_ffffa64c = 0xc26a0000;
  }
  else if (DAT_ffffa66a == '\x01') {
    leading_min_advance_clamp_ffffa64c = 0xc26a0000;
    uVar1 = 1;
  }
  else {
    uVar1 = lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&candidate_tbl_min_advance_vs_coolant_b_000691b8);
    leading_min_advance_clamp_ffffa64c = extraout_fr0_00;
  }
  return uVar1;
}


