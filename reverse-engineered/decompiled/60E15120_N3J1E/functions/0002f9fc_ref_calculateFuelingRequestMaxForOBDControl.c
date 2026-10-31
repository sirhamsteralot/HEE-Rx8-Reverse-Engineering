/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a968: Table 2D - 166 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a97c: Table 2D - 167 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a990: Table 2D - 168 (RX8Defs data pointer, axes and dimensions match).
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
  DAT_ffffbdd0 = extraout_fr0;
  if (snapshot_intake_air_temperature_ffffaddc <= extraout_fr0 * 200.0 - DAT_ffffbdc8) {
    if (snapshot_intake_air_temperature_ffffaddc <= extraout_fr0 * 190.0 - DAT_ffffbdc8) {
      ppuVar2 = &tbl_table_2d_168_0006a990;
    }
    else {
      ppuVar2 = &tbl_table_2d_167_0006a97c;
    }
    uVar1 = lookup_2d_descriptor_scaled(snapshot_inferred_battery_voltage_ffffb590,ppuVar2);
    DAT_ffffbdcc = 0;
    DAT_ffffbdc4 = extraout_fr0_00;
  }
  else {
    DAT_ffffbdc4 = 0;
    DAT_ffffbdcc = 1;
  }
  DAT_ffffbdc8 = 0.0;
  return uVar1;
}


