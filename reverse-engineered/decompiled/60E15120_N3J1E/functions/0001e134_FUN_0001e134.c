/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069c40: Table 2D - 83 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069c60: Table 2D - 84 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069c74: Table 2D - 85 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069c54: Table 2D - 316 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001e134; body bytes: 604; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001e26c) */

uint FUN_0001e134(void)

{
  float snapshot_inferred_coolant_temperature_ffffa98c;
  byte snapshot_DAT_ffffaa62;
  float snapshot_lambda_target_ffffadfc;
  char cVar4;
  char cVar6;
  char cVar7;
  char cVar8;
  uint uVar5;
  float fVar9;
  float snapshot_engine_load_delta_ffffc150;
  float snapshot_mass_air_flow_ffffa9ec;
  float snapshot_engine_load_ffffc0b4;
  float snapshot_engine_speed_rpm_ffffb548;
  
  cVar4 = closed_loop_active_ffffae1f;
  snapshot_lambda_target_ffffadfc = lambda_target_ffffadfc;
  snapshot_DAT_ffffaa62 = cranking_active_ffffaa62_ffffaa62;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_engine_load_delta_ffffc150 = engine_load_delta_ffffc150;
  snapshot_mass_air_flow_ffffa9ec = mass_air_flow_ffffa9ec;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  cVar6 = rx8_is_outside_tolerance_band(warmup_enrichment_total_ffffc00c,0,0x3727c5ac);
  cVar7 = rx8_is_outside_tolerance_band(DAT_ffffc01c,0,0x3727c5ac);
  cVar8 = rx8_is_outside_tolerance_band(inferred_ram_b2f0_ffffb2f0_ffffb2f0,0,0x3727c5ac);
  DAT_ffffb0ec = rx8_lookup_2d_raw_u16(snapshot_engine_speed_rpm_ffffb548,&PTR_PTR_00069c54);
  fVar9 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_83_00069c40);
  DAT_ffffb0e4 = (float)lookup_2d_descriptor_scaled(snapshot_engine_load_ffffc0b4,&tbl_table_2d_84_00069c60);
  DAT_ffffb0e8 = (float)lookup_2d_descriptor_scaled(snapshot_engine_load_ffffc0b4,&tbl_table_2d_85_00069c74);
  if (snapshot_mass_air_flow_ffffa9ec < 0.8) {
    if (snapshot_mass_air_flow_ffffa9ec < 0.19999999) {
      DAT_ffffb100 = '\0';
    }
  }
  else {
    DAT_ffffb100 = '\x01';
  }
  if (snapshot_mass_air_flow_ffffa9ec < 200.0) {
    if (snapshot_mass_air_flow_ffffa9ec < 199.4) {
      DAT_ffffb104 = '\0';
    }
  }
  else {
    DAT_ffffb104 = '\x01';
  }
  if ((((((((cVar4 != '\x01') || (DAT_ffffb0ee < DAT_ffffb0ec)) || (60.0 <= intake_air_temperature_ffffaddc)) ||
         ((cVar6 != '\0' || (cVar7 != '\0')))) ||
        ((snapshot_inferred_coolant_temperature_ffffa98c < 82.0 || ((105.0 <= snapshot_inferred_coolant_temperature_ffffa98c || (DAT_ffffb100 != '\x01')))))) ||
       ((DAT_ffffb104 != '\0' ||
        (((snapshot_engine_speed_rpm_ffffb548 < DAT_ffffb0e4 || (DAT_ffffb0e8 <= snapshot_engine_speed_rpm_ffffb548)) || (0.4 < snapshot_engine_load_ffffc0b4)))))) ||
      ((((300.0 <= snapshot_engine_speed_rpm_ffffb548 && (snapshot_engine_load_ffffc0b4 < fVar9)) ||
        ((0.004 <= snapshot_engine_load_delta_ffffc150 || ((DAT_ffffb0f4 < 0x7d || (cVar8 != '\0')))))) || (snapshot_lambda_target_ffffadfc < 0.99)))) ||
     ((1.05 <= snapshot_lambda_target_ffffadfc || ((snapshot_DAT_ffffaa62 != 0 && ((snapshot_DAT_ffffaa62 != 1 || (DAT_ffffb0f2 < 0x9c)))))))) {
    DAT_ffffb0da = 0;
  }
  else {
    DAT_ffffb0da = 1;
  }
  if (cVar4 == '\x01') {
    DAT_ffffb0ee = rx8_add_u16_saturate((int)(short)DAT_ffffb0ee,1);
  }
  else {
    DAT_ffffb0ee = 0;
  }
  uVar5 = (uint)snapshot_DAT_ffffaa62;
  if (uVar5 == 1) {
    uVar5 = rx8_add_u16_saturate((int)(short)DAT_ffffb0f2,1);
    DAT_ffffb0f2 = (ushort)uVar5;
  }
  else {
    DAT_ffffb0f2 = 0;
  }
  if (0.004 <= snapshot_engine_load_delta_ffffc150) {
    DAT_ffffb0f4 = 0;
  }
  else {
    uVar5 = rx8_add_u16_saturate((int)(short)DAT_ffffb0f4,1);
    DAT_ffffb0f4 = (ushort)uVar5;
  }
  return uVar5;
}


