/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a060: Ignition Leading - Idle Error Timing Correction - Unknown Bool False (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a074: Ignition Leading - Idle Error Timing Correction - Unknown Bool True (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000135b4; body bytes: 228; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00013414 (228 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_idleLeadingTimingCorrection_(void)

{
  uint uVar1;
  uint extraout_r0;
  undefined *puVar2;
  float fVar3;
  float snapshot_engine_load_ffffc0b4;
  
  DAT_ffffa728 = engine_speed_rpm_ffffb548 - DAT_ffffb554;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  fVar3 = engine_speed_rpm_ffffb548;
  if (DAT_ffffb534 == '\0') {
    if (DAT_ffffb53c == '\0') {
      puVar2 = &tbl_ignition_leading_idle_error_timing_correction_unknown_bool_false_0006a060;
    }
    else {
      puVar2 = &tbl_ignition_leading_idle_error_timing_correction_unknown_bool_true_0006a074;
    }
    DAT_ffffa720 = (float)lookup_2d_descriptor_scaled(puVar2);
  }
  else {
    if (DAT_ffffb53a == '\x01') {
      puVar2 = &tbl_ignition_leading_idle_error_timing_correction_unknown_bool_false_0006a060;
    }
    else {
      puVar2 = &tbl_ignition_leading_idle_error_timing_correction_unknown_bool_true_0006a074;
    }
    DAT_ffffa720 = (float)lookup_2d_descriptor_scaled(DAT_ffffa728,puVar2);
  }
  if (((DAT_ffffaa62 != '\x01') || (1500.0 <= fVar3)) ||
     ((fVar3 = DAT_ffffa720, 0.009765625 <= DAT_ffffc01c && (engine_running_timer_ffffa424 < 0x177)))) {
    fVar3 = 0.0;
  }
  if (snapshot_engine_load_ffffc0b4 < 0.6) {
    if (snapshot_engine_load_ffffc0b4 < 0.555) {
      DAT_ffffa730 = 0;
    }
  }
  else {
    DAT_ffffa730 = 1;
  }
  uVar1 = (uint)DAT_ffffa730;
  if (uVar1 == 1) {
    fVar3 = rx8_clamp_float(fVar3,-2.8,0.7);
    uVar1 = extraout_r0;
  }
  DAT_ffffa718 = fVar3;
  return uVar1;
}


