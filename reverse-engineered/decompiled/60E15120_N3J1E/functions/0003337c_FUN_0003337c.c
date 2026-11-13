/* [ADDITIONAL SOURCE REVIEW]
 * idle_ratio_calcs [medium]: 0xffffc04c = 0xffffbacc / 0xffffa7ac when engine running; tables 0x6af18(coolant) and 0x6af40(c04c) selected by b534/b53c; 0xffffc050 zeroed when engine stopped. Called from 0x167c0 via pool 0x168dc.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006af18: Table 2D - 204 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006af2c: Ignition Leading - Cranking Timing Advance (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006af40: Table 2D - 206 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003337c; body bytes: 392; decompiled */

undefined4 * candidate_idle_ratio_calcs(void)

{
  char cVar1;
  byte snapshot_DAT_ffffbaec;
  undefined4 *puVar3;
  undefined4 *extraout_r0;
  undefined4 *extraout_r0_00;
  float fVar4;
  float fVar5;
  float fVar6;
  float snapshot_inferred_coolant_temperature_ffffa990;
  float snapshot_vehicle_speed_ffffbbb4;
  float arg1;
  
  snapshot_DAT_ffffbaec = DAT_ffffbaec;
  cVar1 = at_drive_range_engaged_ffffb53c;
  puVar3 = (undefined4 *)&automatic_transmission_ffffb534;
  arg1 = 0.0;
  if (automatic_transmission_ffffb534 == '\0') {
    if (engine_running_ffffa428 == '\x01') {
      DAT_ffffc04c = DAT_ffffbacc / inferred_ram_a7ac_ffffa7ac_ffffa7ac;
    }
    snapshot_inferred_coolant_temperature_ffffa990 = inferred_coolant_temperature_ffffa990;
    snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
    if (engine_running_ffffa428 == '\0') {
      DAT_ffffc050 = 0.0;
      puVar3 = (undefined4 *)0x0;
    }
    else if (at_drive_range_engaged_ffffb53c == '\x01') {
      fVar6 = inferred_ram_a7ac_ffffa7ac_ffffa7ac;
      fVar4 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa990,&tbl_table_2d_204_0006af18);
      fVar5 = (float)lookup_2d_descriptor_scaled(DAT_ffffc04c,&tbl_table_2d_206_0006af40);
      puVar3 = &DAT_00033494;
      DAT_ffffc050 = (fVar6 / 1000.0) * (fVar6 / 1000.0) * fVar4 * fVar5;
    }
    else {
      fVar6 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa990,&tbl_ignition_leading_cranking_timing_advance_0006af2c);
      DAT_ffffc050 = rx8_max_float(DAT_ffffc050 - fVar6,arg1);
      puVar3 = extraout_r0;
    }
    if ((snapshot_DAT_ffffbaec < 2) && (1 < DAT_ffffc05a)) {
      DAT_ffffc058 = 0x32;
    }
    else if (DAT_ffffc058 != 0) {
      DAT_ffffc058 = DAT_ffffc058 + -1;
    }
    if ((cVar1 != '\0') && (0.0 < snapshot_vehicle_speed_ffffbbb4)) {
      if (((DAT_ffffc058 == 0) ||
          (((cranking_active_ffffaa62_ffffaa62 != '\x01' || (DAT_ffffbaee != '\x01')) || (snapshot_vehicle_speed_ffffbbb4 <= 3.0)))) ||
         ((10.0 <= snapshot_vehicle_speed_ffffbbb4 || (snapshot_inferred_coolant_temperature_ffffa990 <= 60.0)))) {
        arg1 = rx8_max_float(DAT_ffffc054 - 0.0008,arg1);
        puVar3 = extraout_r0_00;
      }
      else {
        DAT_ffffc054 = 0.03;
        puVar3 = (undefined4 *)0x1;
        arg1 = DAT_ffffc054;
      }
    }
    DAT_ffffc054 = arg1;
    if (DAT_ffffb53e == '\0') {
      DAT_ffffc044 = DAT_ffffc054 + DAT_ffffc050 * 0.0025;
    }
    else {
      DAT_ffffc044 = DAT_ffffc050 * 0.0027;
    }
  }
  else {
    DAT_ffffc044 = 0.0;
  }
  DAT_ffffc05a = snapshot_DAT_ffffbaec;
  return puVar3;
}


