/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ab48: Primary Fuel Injector Cranking Pulse Width (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * candidate_cranking_pulse_width_lookup [high]: While 0xffffa428 == 0: 0xffffbe88 = scaled lookup of coolant against descriptor 0x6ab48 (pool 0x30330, scale f32 0x6ab54 = 5.0, data 0x780fc) and 0xffffbe8c from descriptor 0x6ab5c (pool 0x30338, data 0x7814c, all zero bytes).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00030274; body bytes: 46; decompiled */

void candidate_cranking_pulse_width_lookup(void)

{
  undefined4 snapshot_inferred_coolant_temperature_ffffa98c;
  
  if (engine_running_ffffa428 == '\0') {
    snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
    DAT_ffffbe88 = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_primary_fuel_injector_cranking_pulse_width_0006ab48);
    DAT_ffffbe8c = lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&DAT_0006ab5c);
  }
  return;
}


