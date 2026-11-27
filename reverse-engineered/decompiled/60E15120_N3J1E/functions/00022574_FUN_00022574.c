/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a340: Table 3D - 109 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * ch7d_pwm_enable_condition [high]: b358 = engine_running 0xffffa428==1 && engine_running_timer 0xffffa424 >= the u16 3D-table result (tbl 0x6a340 on coolant-derived b35c and IAT ade0) in 0xffffb386 && coolant valid (>= -50.0f @0x7353c) && 9.0f <= battery 0xffffb590 < 16.0f (@0x73540/0x73544) && 0xffffcd70==0; else b358=0. Called from 0x2253c.
 * RAM 0xffffb358 ch7d_pwm_enable (uint8): Enable flag from 0x22574 (engine running, timer, coolant valid, battery 9-16V, !cd70); gates b368 counter and forces b354=0 in 0x22630 when clear.
 * RAM 0xffffcd70 throttle_fault_latch (uint8): Stuck-duty latch: 0x4a11c ORs six flags c91d/c912/c914/c96d/c96f/c971, written by the stall monitor 0x416bc from b354 stuck <10% or >=90% (counters c911-c918); read by 0x22574 -> disables the PWM duty loop (b358=0 -> b354=0).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00022574; body bytes: 188; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00022ee0 (188 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ch7d_pwm_enable_condition(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float snapshot_inferred_battery_voltage_ffffb590;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  
  fVar3 = -52.5;
  snapshot_inferred_battery_voltage_ffffb590 = inferred_battery_voltage_ffffb590;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(coolant_temperature_ffff9f70,&DAT_ffff8060);
  DAT_ffffb35c = fVar2 - inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  DAT_ffffb386 = rx8_lookup_3d_raw_u16(DAT_ffffb35c,DAT_ffffade0,&tbl_table_3d_109_0006a340);
  if (snapshot_inferred_coolant_temperature_ffffa98c < -50.0) {
    if (snapshot_inferred_coolant_temperature_ffffa98c < fVar3) {
      DAT_ffffb388 = 0;
    }
  }
  else {
    DAT_ffffb388 = 1;
  }
  uVar1 = (uint)engine_running_ffffa428;
  if ((((uVar1 != 1) || (uVar1 = (uint)engine_running_timer_ffffa424, uVar1 < (uint)(int)DAT_ffffb386)) ||
      (uVar1 = (uint)DAT_ffffb388, uVar1 != 1)) ||
     (((snapshot_inferred_battery_voltage_ffffb590 < 9.0 || (16.0 <= snapshot_inferred_battery_voltage_ffffb590)) || (uVar1 = (uint)throttle_fault_latch_ffffcd70, uVar1 != 0)))) {
    ch7d_pwm_enable_ffffb358 = 0;
  }
  else {
    ch7d_pwm_enable_ffffb358 = 1;
  }
  return uVar1;
}


