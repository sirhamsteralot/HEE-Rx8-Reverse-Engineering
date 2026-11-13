/* [ADDITIONAL SOURCE REVIEW]
 * knock_voltage_sample [high]: Called from 0x661e (task[6], before ref_engineControlTASK): a37a = knock_sensor_adc_raw_ffff9ef8 (knock ADC raw); in the 200-2000 RPM window filters into a378; sets a386 = (raw RPM >= 10000).
 * RAM 0xffffa37a knock_adc_raw (uint16): Raw knock sensor ADC 0xffff9ef8 read in 0xc3ce.
 * RAM 0xffffa374 knock_adc_filtered (float): First-order filtered knock ADC (coeff 0.004, snap 1.0) valid in the 200-2000 RPM window.
 * RAM 0xffff9f80 engine_speed_rpm_raw (float): Raw RPM = 120e6 / crank period sum (ISR 0x803e); window and 10k-flag checks in 0xc3ce.
 * RAM 0xffff9ef8 knock_sensor_adc_raw (uint16): Knock sensor ADC result read in 0xc3ce.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0000c3ce; body bytes: 114; decompiled */

undefined2 * knock_voltage_sample(void)

{
  undefined2 *puVar1;
  undefined2 *extraout_r0;
  float snapshot_engine_speed_rpm_raw_ffff9f80;
  
  puVar1 = &knock_adc_raw_ffffa37a;
  knock_adc_raw_ffffa37a = knock_sensor_adc_raw_ffff9ef8;
  snapshot_engine_speed_rpm_raw_ffff9f80 = engine_speed_rpm_raw_ffff9f80;
  if ((200.0 <= engine_speed_rpm_raw_ffff9f80) && (engine_speed_rpm_raw_ffff9f80 < 2000.0)) {
    knock_adc_filtered_ffffa374 = rx8_first_order_filter((float)knock_sensor_adc_raw_ffff9ef8,knock_adc_filtered_ffffa374,0.004,1.0);
    knock_voltage_sample_ffffa378 = (undefined2)(int)knock_adc_filtered_ffffa374;
    puVar1 = extraout_r0;
  }
  if (snapshot_engine_speed_rpm_raw_ffff9f80 < 10000.0) {
    if (snapshot_engine_speed_rpm_raw_ffff9f80 < 10000.0) {
      puVar1 = (undefined2 *)0x0;
      high_rpm_10k_flag_ffffa386 = 0;
    }
  }
  else {
    high_rpm_10k_flag_ffffa386 = 1;
  }
  return puVar1;
}


