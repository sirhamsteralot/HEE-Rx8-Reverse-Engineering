/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a340: Table 3D - 109 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00022574; body bytes: 188; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00022ee0 (188 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00022574(void)

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
     (((snapshot_inferred_battery_voltage_ffffb590 < 9.0 || (16.0 <= snapshot_inferred_battery_voltage_ffffb590)) || (uVar1 = (uint)DAT_ffffcd70, uVar1 != 0)))) {
    DAT_ffffb358 = 0;
  }
  else {
    DAT_ffffb358 = 1;
  }
  return uVar1;
}


