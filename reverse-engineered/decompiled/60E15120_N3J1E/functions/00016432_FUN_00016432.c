/* [ADDITIONAL SOURCE REVIEW]
 * idle_ac_request_calc [medium]: 0xffffa8bd/a8be set when 0xffffa7ac + 3.0 <= rpm; 0xffffa8b8 = tbl 0x694cc(coolant) if 0xffffce32 else 0; decay steps from ROM 0x6e0ac/0x6e0b0 (secondary-air-pump-dependent); 90 C coolant / 40 C IAT gates. Called from 0x167c0 via pool 0x168b8.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x000694cc: Table 2D - 41 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069508: Table 2D - 44 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006951c: Table 2D - 45 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00016432; body bytes: 344; decompiled */

void candidate_idle_ac_request_calc(void)

{
  char cVar1;
  float *pfVar2;
  float fVar3;
  float snapshot_intake_air_temperature_ffffaddc;
  float snapshot_inferred_coolant_temperature_ffffa990;
  float fVar6;
  
  cVar1 = engine_running_ffffa428;
  fVar6 = 0.0;
  if (DAT_ffffa8a8 == '\x01') {
    DAT_ffffa8a4 = 0.0;
    DAT_ffffa8ac = 0.0;
    DAT_ffffa8b0 = 0.0;
    DAT_ffffa8bd = '\0';
    DAT_ffffa8be = '\0';
  }
  else {
    if (inferred_ram_a7ac_ffffa7ac_ffffa7ac + 3.0 <= engine_speed_rpm_ffffb548) {
      DAT_ffffa8bd = '\x01';
      DAT_ffffa8be = '\x01';
    }
    snapshot_intake_air_temperature_ffffaddc = intake_air_temperature_ffffaddc;
    snapshot_inferred_coolant_temperature_ffffa990 = inferred_coolant_temperature_ffffa990;
    if (inferred_ram_ce32_ffffce32_ffffce32 == '\x01') {
      DAT_ffffa8b8 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa990,&tbl_table_2d_41_000694cc);
    }
    else {
      DAT_ffffa8b8 = 0.0;
    }
    if (secondary_air_pump_request_ffffbf6c == '\x01') {
      pfVar2 = (float *)&DAT_0006e0b0;
    }
    else {
      pfVar2 = (float *)&DAT_0006e0ac;
    }
    if (cVar1 == '\0') {
      fVar3 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990);
      DAT_ffffa8ac = DAT_ffffa8b8 + fVar3;
      DAT_ffffa8bd = '\0';
    }
    else if ((DAT_ffffa8bd == '\x01') &&
            (DAT_ffffa8ac = rx8_max_float(DAT_ffffa8ac - *pfVar2,fVar6), DAT_ffffa8ac <= 0.0)) {
      DAT_ffffa8bd = '\0';
    }
    if (cVar1 == '\0') {
      if ((90.0 <= snapshot_inferred_coolant_temperature_ffffa990) && (40.0 <= snapshot_intake_air_temperature_ffffaddc)) {
        fVar6 = (float)lookup_2d_descriptor_scaled(snapshot_intake_air_temperature_ffffaddc,&tbl_table_2d_45_0006951c);
      }
      DAT_ffffa8b4 = fVar6;
      fVar6 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,&tbl_table_2d_44_00069508);
      DAT_ffffa8b0 = DAT_ffffa8b4 + fVar6;
      DAT_ffffa8be = '\0';
    }
    else if ((DAT_ffffa8be == '\x01') &&
            (DAT_ffffa8b0 = rx8_max_float(DAT_ffffa8b0 - 0.00023,fVar6), DAT_ffffa8b0 <= 0.0)) {
      DAT_ffffa8be = '\0';
    }
    DAT_ffffa8a4 = rx8_max_float(DAT_ffffa8ac,DAT_ffffa8b0);
  }
  return;
}


