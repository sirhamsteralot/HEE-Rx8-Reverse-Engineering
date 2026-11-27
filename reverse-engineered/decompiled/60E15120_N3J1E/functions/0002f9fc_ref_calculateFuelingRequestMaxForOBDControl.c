/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a968: Table 2D - 166 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a97c: Table 2D - 167 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a990: Table 2D - 168 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffbdc8 fuel_pump_demand_margin (float32): Margin subtracted from the 200/190 x 2D-166 product inside 0x2f9fc, then zeroed at the end of the function through the first branch of ROM byte 0x775bc (=0x00 here). Pool 0x2fb04=0xffffbdc8.
 * RAM 0xffffbdd0 fuel_pump_demand_reference (float32): Result of the barometric-pressure lookup 2D-166 (descriptor 0x6a968, axis 0xffffad14) in 0x2f9fc; scaled by 200.0 (ROM 0x775c4) and 190.0 (0x775c8) to form the intake-air margins. Pool 0x2fae8=0xffffbdd0.
 * RAM 0xffffbdcc fuel_pump_margin_high_flag (uint8): Set 1 by 0x2f9fc when intake air exceeds the 200 x reference margin (max demand forced to 0.0), cleared 0 on the lookup path. Pool 0x2fb00=0xffffbdcc.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002f9fc; body bytes: 204; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0002fa7a) */
/* WARNING: Removing unreachable block (ram,0x0002fa82) */
/* WARNING: Removing unreachable block (ram,0x0002fa92) */
/* WARNING: Removing unreachable block (ram,0x0002fa98) */
/* WARNING: Removing unreachable block (ram,0x0002faa2) */
/* WARNING: Removing unreachable block (ram,0x0002faae) */
/* Unique exact-byte match to related 60E0FC00 function at 0002feb4 (204 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_calculateFuelingRequestMaxForOBDControl(void)

{
  undefined4 uVar1;
  undefined **ppuVar2;
  float extraout_fr0;
  undefined4 extraout_fr0_00;
  undefined4 snapshot_inferred_battery_voltage_ffffb590;
  float snapshot_intake_air_temperature_ffffaddc;
  
  snapshot_inferred_battery_voltage_ffffb590 = inferred_battery_voltage_ffffb590;
  snapshot_intake_air_temperature_ffffaddc = intake_air_temperature_ffffaddc;
  uVar1 = lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_table_2d_166_0006a968);
  fuel_pump_demand_reference_ffffbdd0 = extraout_fr0;
  if (snapshot_intake_air_temperature_ffffaddc <= extraout_fr0 * 200.0 - fuel_pump_demand_margin_ffffbdc8) {
    if (snapshot_intake_air_temperature_ffffaddc <= extraout_fr0 * 190.0 - fuel_pump_demand_margin_ffffbdc8) {
      ppuVar2 = &tbl_table_2d_168_0006a990;
    }
    else {
      ppuVar2 = &tbl_table_2d_167_0006a97c;
    }
    uVar1 = lookup_2d_descriptor_scaled(snapshot_inferred_battery_voltage_ffffb590,ppuVar2);
    fuel_pump_margin_high_flag_ffffbdcc = 0;
    fuel_pump_max_demand_ffffbdc4 = extraout_fr0_00;
  }
  else {
    fuel_pump_max_demand_ffffbdc4 = 0;
    fuel_pump_margin_high_flag_ffffbdcc = 1;
  }
  fuel_pump_demand_margin_ffffbdc8 = 0.0;
  return uVar1;
}


