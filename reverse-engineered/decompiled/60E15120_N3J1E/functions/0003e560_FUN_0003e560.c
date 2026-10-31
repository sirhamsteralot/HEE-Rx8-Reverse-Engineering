/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b744: Table 2D - 262 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b780: Table 2D - 265 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b794: Table 2D - 266 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b7a8: Table 2D - 267 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003e560; body bytes: 358; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003e6e4) */

void FUN_0003e560(void)

{
  char cVar1;
  float *pfVar2;
  undefined *puVar3;
  float fVar4;
  float snapshot_DAT_ffffc538;
  float snapshot_diag_afr_word_a_ffffaa6c;
  
  if (DAT_ffffb0ca == '\x01') {
    DAT_ffffc69c = '\0';
  }
  else if (DAT_ffffc69c != '\0') {
    DAT_ffffc69c = DAT_ffffc69c + -1;
  }
  if (DAT_ffffc640 <= DAT_ffffc644) {
    puVar3 = &tbl_table_2d_266_0006b794;
  }
  else {
    puVar3 = &tbl_table_2d_265_0006b780;
  }
  snapshot_DAT_ffffc538 = DAT_ffffc538;
  snapshot_diag_afr_word_a_ffffaa6c = diag_afr_word_a_ffffaa6c;
  fVar4 = open_loop_fuel_target_ffffb120;
  DAT_ffffc678 = lookup_2d_descriptor_scaled(mass_air_flow_ffffa9ec,puVar3);
  if (DAT_ffffc64f == '\x01') {
    DAT_ffffc67c = 0x3f800000;
  }
  else {
    DAT_ffffc67c = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_table_2d_267_0006b7a8);
  }
  DAT_ffffc680 = (rough_knock_correction_leading_ffffa6ac + coolant_timing_derate_leading_ffffa750 + DAT_ffffa66c + DAT_ffffc654) * 2.25;
  cVar1 = rx8_is_outside_tolerance_band(fVar4,0,0x3727c5ac);
  if ((cVar1 == '\0') || (0.0 < fVar4)) {
    if (cVar1 == '\0') {
      fVar4 = 8.5;
    }
    else {
      fVar4 = 6.5;
    }
    DAT_ffffc684 = DAT_ffffc680 + snapshot_diag_afr_word_a_ffffaa6c * fVar4 * 14.7 + DAT_ffffc66c;
  }
  if ((engine_running_ffffa428 == '\0') && (engine_stopped_latch_ffffa41c == '\0')) {
    ref_updateMemoryAtAddress_float_VAL_ADDR(DAT_ffffc644,&DAT_ffff8710);
  }
  if (secondary_air_pump_request_ffffbf6c == '\x01') {
    DAT_ffffc688 = (float)lookup_2d_descriptor_scaled(snapshot_diag_afr_word_a_ffffaa6c,&tbl_table_2d_262_0006b744);
    if (DAT_ffffc64f == '\x01') {
      pfVar2 = (float *)&DAT_0007b12c;
    }
    else {
      pfVar2 = (float *)&DAT_0007b130;
    }
    DAT_ffffc68c = *pfVar2 * DAT_ffffc688 * snapshot_DAT_ffffc538;
  }
  else {
    DAT_ffffc688 = 1.0;
    DAT_ffffc68c = 1.0;
  }
  FUN_0003e980();
  return;
}


