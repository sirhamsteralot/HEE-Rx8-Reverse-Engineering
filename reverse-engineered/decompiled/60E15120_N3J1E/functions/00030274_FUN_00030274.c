/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ab48: Primary Fuel Injector Cranking Pulse Width (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00030274; body bytes: 46; decompiled */

void FUN_00030274(void)

{
  undefined4 snapshot_inferred_coolant_temperature_ffffa98c;
  
  if (engine_running_ffffa428 == '\0') {
    snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
    DAT_ffffbe88 = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_primary_fuel_injector_cranking_pulse_width_0006ab48);
    DAT_ffffbe8c = lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&DAT_0006ab5c);
  }
  return;
}


