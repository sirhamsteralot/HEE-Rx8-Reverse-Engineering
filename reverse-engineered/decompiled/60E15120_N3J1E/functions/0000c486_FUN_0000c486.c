/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b250: Knock Voltage To Magnitude (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b2a0: Knock Related (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b2ac: Knock Related 3 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * knock_magnitude_integrate [high]: Knock magnitude core: voltage = (a378 - a326)*5/65536; magnitude vs tbl 0x6b250 minus command-code term; noise filter, per-rotor integrators a33c/a350, baseline a348, combined level a34c; sets a324 = (a364 <= a330), knock detected.
 * RAM 0xffffc060 knock_filter_coeff_a (float): Noise-step scale 0.0625 (calm) / 0.1875 (transient); used in the 0xc486 integrator step.
 * RAM 0xffffc064 knock_filter_coeff_b (float): Noise-excess gain 0.1253 (calm and transient; 0x336c4 hardcodes 0x3e004ea5); used in the 0xc486 integrator step (x2 on decay).
 * RAM 0xffffc068 knock_filter_coeff_c (float): Baseline slow-filter coefficient 0.03125 (calm, ROM 0x7a248) / 0.09375 (transient, ROM 0x7a23c); switched by 0x336c4 on c05d.
 * RAM 0xffffa328 knock_level_threshold (float): Selected knock level threshold (from 0x336c4 3D tables); compared against per-rotor noise threshold a350 in 0xc486.
 * RAM 0xffffa378 knock_voltage_sample (uint16): Filtered knock ADC sample (u16) from 0xc3ce; converted to volts in 0xc486.
 * RAM 0xffffa326 knock_voltage_reference (uint16): Knock reference-channel ADC (0xc276); subtracted from a378 in 0xc486.
 * RAM 0xffffa370 knock_voltage (float): Knock voltage = (a378 - a326) * 5/65536 V.
 * RAM 0xffffa330 knock_magnitude (float): Knock magnitude vs tbl 0x6b250 minus command-code term a381[a384]<<5, clamped >= 0.
 * RAM 0xffffa32c knock_noise_filtered (float): Filtered (a330 - a348) noise term; coefficient is the hardcoded literal 0.0625 in 0xc486 (not c060: equals calm c060, ignores the transient 0.1875).
 * RAM 0xffffa344 knock_integrator_step (float): Per-event integrator step min(|a32c|, c060*|a330 - a334[a384]|), floor 1.0.
 * RAM 0xffffa348 knock_baseline_slow (float): Slow baseline of a330 (coeff c068); part of the combined level a34c.
 * RAM 0xffffa34c knock_level_combined (float): a33c[a384] + a348, clamped >= 0; stored to a334[a384].
 * RAM 0xffffa334 knock_level_running (float[2]): Per-rotor running knock level a334[0..1].
 * RAM 0xffffa33c knock_level_integrator (float[2]): Per-rotor level integrators a33c[0..1] (+/-= a344).
 * RAM 0xffffa350 knock_noise_threshold (float[2]): Per-rotor noise thresholds a350[0..1], clamped to [tbl 0x6b2a0 min, a358+8 max].
 * RAM 0xffffa358 knock_noise_floor (float): Lookup(raw RPM, tbl 0x6b2ac) noise floor; a35c = 2x the excess above it.
 * RAM 0xffffa360 knock_noise_excess (float): a350 - 2x excess, clamped >= 0; drives the threshold command term.
 * RAM 0xffffa364 knock_threshold_command_base (float): Base threshold command (a34c + a328*a360 clamped 64..255; a34c = combined knock level addend, 64 is the clamp floor).
 * RAM 0xffffa389 knock_reference_voltage_latched (uint8[2]): Latched a387 values; a change forces a32c = 40 (noise reset).
 * RAM 0xffffa381 knock_command_code (uint8[2]): Mapped command codes a381[0..1] from a368 (6/5/4/2/0 bands).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0000c486; body bytes: 674; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0000c5c4) */

undefined4 * knock_magnitude_integrate(void)

{
  uint uVar1;
  float fVar2;
  float arg0;
  float fVar3;
  undefined4 snapshot_engine_speed_rpm_raw_ffff9f80;
  float fVar5;
  float fVar6;
  float local_30;
  
  knock_voltage_ffffa370 = (float)(int)((uint)knock_voltage_sample_ffffa378 - (uint)knock_voltage_reference_ffffa326) * 7.6293945e-05;
  fVar6 = 0.0;
  if (knock_voltage_ffffa370 < 0.0) {
    knock_voltage_ffffa370 = 0.0;
  }
  fVar2 = (float)lookup_2d_descriptor_scaled(&tbl_knock_voltage_to_magnitude_0006b250);
  knock_magnitude_ffffa330 = fVar2 - (float)((uint)(byte)(&knock_command_code_ffffa381)[knock_rotor_index_ffffa384] << 5);
  if (knock_magnitude_ffffa330 < 0.0) {
    knock_magnitude_ffffa330 = fVar6;
  }
  knock_noise_filtered_ffffa32c = rx8_first_order_filter(knock_magnitude_ffffa330 - knock_baseline_slow_ffffa348,knock_noise_filtered_ffffa32c,0.0625,fVar6);
  DAT_ffffa38b = (&knock_reference_voltage_ffffa387)[knock_rotor_index_ffffa384] != (&knock_reference_voltage_latched_ffffa389)[knock_rotor_index_ffffa384];
  if ((bool)DAT_ffffa38b) {
    knock_noise_filtered_ffffa32c = 40.0;
  }
  (&knock_reference_voltage_latched_ffffa389)[knock_rotor_index_ffffa384] = (&knock_reference_voltage_ffffa387)[knock_rotor_index_ffffa384];
  fVar2 = knock_magnitude_ffffa330 - (float)(&knock_level_running_ffffa334)[knock_rotor_index_ffffa384];
  if (fVar2 < 0.0) {
    fVar2 = -fVar2;
  }
  fVar3 = knock_noise_filtered_ffffa32c;
  if (knock_noise_filtered_ffffa32c < 0.0) {
    fVar3 = -knock_noise_filtered_ffffa32c;
  }
  knock_integrator_step_ffffa344 = knock_filter_coeff_a_ffffc060 * fVar2;
  if (fVar3 < knock_filter_coeff_a_ffffc060 * fVar2) {
    knock_integrator_step_ffffa344 = fVar3;
  }
  if (knock_integrator_step_ffffa344 < 1.0) {
    knock_integrator_step_ffffa344 = 1.0;
  }
  local_30 = *(float *)(&knock_level_integrator_ffffa33c + (uint)knock_rotor_index_ffffa384 * 4);
  if (knock_magnitude_ffffa330 <= (float)(&knock_level_running_ffffa334)[knock_rotor_index_ffffa384]) {
    if (knock_magnitude_ffffa330 < (float)(&knock_level_running_ffffa334)[knock_rotor_index_ffffa384]) {
      local_30 = local_30 - knock_integrator_step_ffffa344;
    }
  }
  else {
    local_30 = local_30 + knock_integrator_step_ffffa344;
  }
  *(float *)(&knock_level_integrator_ffffa33c + (uint)knock_rotor_index_ffffa384 * 4) = local_30;
  snapshot_engine_speed_rpm_raw_ffff9f80 = engine_speed_rpm_raw_ffff9f80;
  knock_noise_floor_ffffa358 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_raw_ffff9f80,&tbl_knock_related_3_0006b2ac);
  fVar3 = knock_noise_floor_ffffa358 + 8.0;
  fVar2 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_raw_ffff9f80,&tbl_knock_related_0006b2a0);
  fVar5 = 2.0;
  if ((knock_magnitude_ffffa330 <= (float)(&knock_level_running_ffffa334)[knock_rotor_index_ffffa384] - (float)(&knock_noise_threshold_ffffa350)[knock_rotor_index_ffffa384])
     || ((float)(&knock_level_running_ffffa334)[knock_rotor_index_ffffa384] < knock_magnitude_ffffa330)) {
    arg0 = (float)(&knock_noise_threshold_ffffa350)[knock_rotor_index_ffffa384] + knock_integrator_step_ffffa344 * knock_filter_coeff_b_ffffc064;
  }
  else {
    arg0 = (float)(&knock_noise_threshold_ffffa350)[knock_rotor_index_ffffa384] - knock_integrator_step_ffffa344 * knock_filter_coeff_b_ffffc064 * 2.0;
  }
  uVar1 = (uint)knock_rotor_index_ffffa384;
  fVar2 = rx8_clamp_float(arg0,fVar2,fVar3);
  (&knock_noise_threshold_ffffa350)[uVar1] = fVar2;
  knock_baseline_slow_ffffa348 = rx8_first_order_filter(knock_magnitude_ffffa330,knock_baseline_slow_ffffa348,knock_filter_coeff_c_ffffc068,fVar6);
  knock_level_combined_ffffa34c = *(float *)(&knock_level_integrator_ffffa33c + (uint)knock_rotor_index_ffffa384 * 4) + knock_baseline_slow_ffffa348;
  if (*(float *)(&knock_level_integrator_ffffa33c + (uint)knock_rotor_index_ffffa384 * 4) + knock_baseline_slow_ffffa348 < 0.0) {
    knock_level_combined_ffffa34c = fVar6;
  }
  (&knock_level_running_ffffa334)[knock_rotor_index_ffffa384] = knock_level_combined_ffffa34c;
  DAT_ffffa35c = fVar6;
  if (0.0 <= (float)(&knock_noise_threshold_ffffa350)[knock_rotor_index_ffffa384] - knock_noise_floor_ffffa358) {
    DAT_ffffa35c = ((float)(&knock_noise_threshold_ffffa350)[knock_rotor_index_ffffa384] - knock_noise_floor_ffffa358) * fVar5;
  }
  knock_noise_excess_ffffa360 = (float)(&knock_noise_threshold_ffffa350)[knock_rotor_index_ffffa384] - DAT_ffffa35c;
  if ((float)(&knock_noise_threshold_ffffa350)[knock_rotor_index_ffffa384] - DAT_ffffa35c < 0.0) {
    knock_noise_excess_ffffa360 = fVar6;
  }
  knock_threshold_command_base_ffffa364 = 64.0;
  fVar6 = knock_level_combined_ffffa34c + knock_level_threshold_ffffa328 * knock_noise_excess_ffffa360;
  if ((64.0 <= fVar6) && (knock_threshold_command_base_ffffa364 = fVar6, 255.0 < fVar6)) {
    knock_threshold_command_base_ffffa364 = 255.0;
  }
  (&knock_threshold_command_ffffa368)[knock_rotor_index_ffffa384] = knock_threshold_command_base_ffffa364 + knock_noise_excess_ffffa360 * fVar5;
  knock_detected_ffffa324 = knock_threshold_command_base_ffffa364 <= knock_magnitude_ffffa330;
  return &knock_threshold_command_ffffa368;
}


