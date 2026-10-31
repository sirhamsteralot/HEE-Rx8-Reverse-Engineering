/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069440: Table 2D - 34 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069454: Table 2D - 35 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006947c: Table 2D - 37 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069490: Table 2D - 38 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000694a4: Table 2D - 39 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000694b8: Table 2D - 40 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00015a9a; body bytes: 938; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00015ad4) */
/* WARNING: Removing unreachable block (ram,0x00015af2) */
/* WARNING: Removing unreachable block (ram,0x00015afc) */
/* WARNING: Removing unreachable block (ram,0x00015b08) */
/* WARNING: Removing unreachable block (ram,0x00015b0c) */
/* WARNING: Removing unreachable block (ram,0x00015b1c) */
/* WARNING: Removing unreachable block (ram,0x00015b16) */
/* WARNING: Removing unreachable block (ram,0x00015b3e) */

undefined4 FUN_00015a9a(void)

{
  char cVar1;
  undefined4 extraout_r0;
  float fVar2;
  float fVar3;
  float arg1;
  float snapshot_DAT_ffffa7ac;
  undefined4 snapshot_inferred_coolant_temperature_ffffa990;
  float snapshot_engine_speed_rpm_ffffb548;
  char local_3c;
  
  cVar1 = DAT_ffffb53a;
  local_3c = DAT_ffffb53a;
  if (DAT_ffffa884 == '\0') {
    DAT_ffffa86c = 0;
    DAT_ffffa884 = '\x04';
  }
  DAT_ffffa834 = ((DAT_ffffa7a0 + DAT_ffffa8c4 + DAT_ffffa8a4 + DAT_ffffa888 + DAT_ffffa7a8 +
                   DAT_ffffa88c + DAT_ffffa830) - DAT_ffffa89c) + DAT_ffffc044 + DAT_ffffc19c;
  if (engine_speed_rpm_ffffb548 < DAT_ffffa7ac + 0.0) {
    if (engine_speed_rpm_ffffb548 < 312.0) {
      DAT_ffffa844 = '\0';
    }
  }
  else {
    DAT_ffffa844 = '\x01';
  }
  DAT_ffffa858 = DAT_ffffa850;
  DAT_ffffa85c = DAT_ffffa854;
  arg1 = 0.0;
  snapshot_DAT_ffffa7ac = DAT_ffffa7ac;
  snapshot_inferred_coolant_temperature_ffffa990 = inferred_coolant_temperature_ffffa990;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  fVar2 = DAT_ffffa834;
  if ((DAT_ffffa844 == '\x01') &&
     (local_3c = rx8_is_outside_tolerance_band(engine_speed_rpm_ffffb548,0,0x3727c5ac),
     fVar2 = DAT_ffffa850, local_3c != '\0')) {
    fVar2 = (DAT_ffffa834 * snapshot_DAT_ffffa7ac) / snapshot_engine_speed_rpm_ffffb548;
    if (cVar1 == '\x01') {
      fVar3 = 0.0;
    }
    else {
      fVar3 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_37_0006947c);
      DAT_ffffa878 = fVar3;
    }
    fVar2 = rx8_max_float(fVar2,fVar3);
  }
  DAT_ffffa850 = fVar2;
  if (DAT_ffffa844 == '\x01') {
    DAT_ffffa87c = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_38_00069490);
    DAT_ffffa854 = rx8_first_order_filter(DAT_ffffa850,DAT_ffffa85c,1.0 - DAT_ffffa87c,1e-05);
  }
  else {
    DAT_ffffa854 = DAT_ffffa834;
  }
  fVar2 = arg1;
  if ((((DAT_ffffa885 != '\0') || (DAT_ffffa844 != '\x01')) && (DAT_ffffa844 != '\0')) &&
     (fVar2 = DAT_ffffa864, DAT_ffffa844 == '\x01')) {
    fVar2 = rx8_max_float(DAT_ffffa850 - DAT_ffffa854,arg1);
    fVar2 = (snapshot_engine_speed_rpm_ffffb548 * fVar2) / 38.07;
  }
  DAT_ffffa864 = fVar2;
  if ((DAT_ffffaa62 != '\0') && (DAT_ffffa844 != '\0')) {
    if (cVar1 == '\0') {
      DAT_ffffa880 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,&tbl_table_2d_39_000694a4);
      fVar2 = (DAT_ffffa864 - DAT_ffffa880) * 0.5;
      fVar3 = 0.446;
    }
    else {
      DAT_ffffa880 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,&tbl_table_2d_39_000694a4);
      fVar2 = DAT_ffffa864 - DAT_ffffa880;
      fVar3 = 0.892;
    }
    arg1 = rx8_clamp_float((fVar2 * 0.892) / 0.15,arg1,fVar3);
  }
  DAT_ffffa868 = arg1;
  if (DAT_ffffa844 == '\0') {
    DAT_ffffa860 = DAT_ffffa834;
  }
  else if (local_3c != '\0') {
    fVar2 = (DAT_ffffc048 * snapshot_DAT_ffffa7ac) / snapshot_engine_speed_rpm_ffffb548 +
            (DAT_ffffa850 - DAT_ffffa858 * DAT_ffffa868) / (1.0 - DAT_ffffa868);
    DAT_ffffa870 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,&tbl_table_2d_34_00069440);
    DAT_ffffa874 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,&tbl_table_2d_35_00069454);
    DAT_ffffa860 = rx8_clamp_float(fVar2,DAT_ffffa870,DAT_ffffa874);
  }
  if (engine_running_ffffa428 == '\x01') {
    fVar2 = (DAT_ffffa834 * snapshot_DAT_ffffa7ac) / 38.07;
    if (DAT_ffffa844 != '\0') {
      DAT_ffffa84c = fVar2;
      fVar2 = rx8_clamp_float((DAT_ffffa860 * snapshot_engine_speed_rpm_ffffb548) / 38.07,fVar2,fVar2 + 29.1969);
    }
  }
  else {
    fVar2 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,&DAT_00069468);
  }
  DAT_ffffa848 = fVar2;
  if (cVar1 == '\x01') {
    DAT_ffffa83c = 29.1969;
  }
  else {
    DAT_ffffa83c = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548 - snapshot_DAT_ffffa7ac,&tbl_table_2d_40_000694b8);
  }
  DAT_ffffa840 = 0x402e147b;
  DAT_ffffa838 = rx8_min_float(DAT_ffffa898 * DAT_ffffa8c0 * DAT_ffffa848 - 0.0,DAT_ffffa83c);
  if (DAT_ffffa884 != '\0') {
    DAT_ffffa884 = DAT_ffffa884 + -1;
  }
  DAT_ffffa885 = DAT_ffffa844;
  return extraout_r0;
}


