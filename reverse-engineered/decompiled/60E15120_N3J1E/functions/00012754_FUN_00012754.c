/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00012754; body bytes: 206; decompiled */

uint FUN_00012754(void)

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
  cVar2 = rx8_is_outside_tolerance_band(coolant_timing_derate_trailing_ffffa754,0,0x3727c5ac);
  cVar3 = rx8_is_outside_tolerance_band(DAT_ffffa670,uVar5,uVar6);
  cVar4 = rx8_is_outside_tolerance_band(cold_start_timing_reduction_trailing_ffffc9a4,uVar5,uVar6);
  if (snapshot_engine_load_ffffc0b4 <= 0.5) {
    if (snapshot_engine_load_ffffc0b4 <= 0.45) {
      DAT_ffffa66b = '\0';
    }
  }
  else {
    DAT_ffffa66b = '\x01';
  }
  uVar1 = (uint)DAT_ffffaa62;
  if (uVar1 == 1) {
    if (cVar3 == '\0') {
      DAT_ffffa65c = 0xc1c80000;
      uVar1 = 0;
    }
    else {
      uVar1 = lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&DAT_000691e0);
      DAT_ffffa65c = extraout_fr0;
    }
  }
  else if ((cVar4 == '\0') && (cVar2 == '\0')) {
    DAT_ffffa65c = 0xc28a6666;
  }
  else if (DAT_ffffa66b == '\x01') {
    DAT_ffffa65c = 0xc28a6666;
    uVar1 = 1;
  }
  else {
    uVar1 = lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&DAT_000691f4);
    DAT_ffffa65c = extraout_fr0_00;
  }
  return uVar1;
}


