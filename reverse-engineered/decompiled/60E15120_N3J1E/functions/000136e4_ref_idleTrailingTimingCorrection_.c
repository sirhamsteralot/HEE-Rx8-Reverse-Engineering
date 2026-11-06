/* [ADDITIONAL SOURCE REVIEW]
 * idle_trailing_timing_error_correction [high]: was ref_idleTrailingTimingCorrection_. Trailing mirror -> a71c; feeds +a71c in 0x124d6.
 * RAM 0xffffa71c idle_trailing_timing_error_correction (float): 
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a088: Ignition Trailing - Idle Error Timing Correction - Unknown Bool False (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a09c: Ignition Trailing - Idle Error Timing Correction - Unknown Bool True (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000136e4; body bytes: 228; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00013544 (228 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint idle_trailing_timing_error_correction(void)

{
  uint uVar1;
  uint extraout_r0;
  undefined *puVar2;
  float fVar3;
  float snapshot_engine_load_ffffc0b4;
  
  DAT_ffffa72c = engine_speed_rpm_ffffb548 - DAT_ffffb554;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  fVar3 = engine_speed_rpm_ffffb548;
  if (automatic_transmission_ffffb534 == '\0') {
    if (DAT_ffffb53c == '\0') {
      puVar2 = &tbl_ignition_trailing_idle_error_timing_correction_unknown_bool_false_0006a088;
    }
    else {
      puVar2 = &tbl_ignition_trailing_idle_error_timing_correction_unknown_bool_true_0006a09c;
    }
    DAT_ffffa724 = (float)lookup_2d_descriptor_scaled(puVar2);
  }
  else {
    if (DAT_ffffb53a == '\x01') {
      puVar2 = &tbl_ignition_trailing_idle_error_timing_correction_unknown_bool_false_0006a088;
    }
    else {
      puVar2 = &tbl_ignition_trailing_idle_error_timing_correction_unknown_bool_true_0006a09c;
    }
    DAT_ffffa724 = (float)lookup_2d_descriptor_scaled(DAT_ffffa72c,puVar2);
  }
  if (((cranking_active_ffffaa62_ffffaa62 != '\x01') || (1500.0 <= fVar3)) ||
     ((fVar3 = DAT_ffffa724, 0.009765625 <= DAT_ffffc01c && (engine_running_timer_ffffa424 < 0x177)))) {
    fVar3 = 0.0;
  }
  if (snapshot_engine_load_ffffc0b4 < 0.6) {
    if (snapshot_engine_load_ffffc0b4 < 0.555) {
      DAT_ffffa731 = 0;
    }
  }
  else {
    DAT_ffffa731 = 1;
  }
  uVar1 = (uint)DAT_ffffa731;
  if (uVar1 == 1) {
    fVar3 = rx8_clamp_float(fVar3,-2.8,0.7);
    uVar1 = extraout_r0;
  }
  idle_trailing_timing_error_correction_ffffa71c = fVar3;
  return uVar1;
}


