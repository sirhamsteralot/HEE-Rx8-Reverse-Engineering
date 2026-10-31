/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a29c: Table 2D - 127 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00022294; body bytes: 224; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00022c00 (224 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * FUN_00022294(void)

{
  undefined4 *puVar1;
  float snapshot_inferred_battery_voltage_ffffb590;
  float snapshot_engine_load_ffffc0b4;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  
  snapshot_inferred_battery_voltage_ffffb590 = inferred_battery_voltage_ffffb590;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  DAT_ffffb34c = rx8_lookup_2d_raw_u16(inferred_coolant_temperature_catalyst_temp_model_ffffa998,&PTR_CAL_table_845_0006a290);
  DAT_ffffb344 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_127_0006a29c);
  if (snapshot_inferred_coolant_temperature_ffffa98c < 5.0) {
    if (snapshot_inferred_coolant_temperature_ffffa98c < 2.5) {
      DAT_ffffb350 = 0;
    }
  }
  else {
    DAT_ffffb350 = 1;
  }
  if (snapshot_engine_load_ffffc0b4 < DAT_ffffb344) {
    if (snapshot_engine_load_ffffc0b4 < DAT_ffffb344 + -0.04) {
      DAT_ffffb351 = '\0';
    }
  }
  else {
    DAT_ffffb351 = '\x01';
  }
  puVar1 = &DAT_000223a8;
  if (((((engine_injectors_off_ffffa42c != '\0') ||
        (puVar1 = (undefined4 *)(uint)engine_running_ffffa428, puVar1 != (undefined4 *)0x1)) ||
       (puVar1 = (undefined4 *)(int)DAT_ffffa422, puVar1 < (undefined4 *)(int)DAT_ffffb34c)) ||
      ((puVar1 = (undefined4 *)(uint)DAT_ffffb350, puVar1 != (undefined4 *)0x1 || (snapshot_inferred_battery_voltage_ffffb590 < 9.0))))
     || ((15.0 <= snapshot_inferred_battery_voltage_ffffb590 ||
         ((puVar1 = (undefined4 *)0x0, DAT_ffffb351 != '\0' &&
          (puVar1 = (undefined4 *)(uint)DAT_ffffb0ca, puVar1 != (undefined4 *)0x1)))))) {
    DAT_ffffb338 = 0;
  }
  else {
    DAT_ffffb338 = 1;
  }
  return puVar1;
}


