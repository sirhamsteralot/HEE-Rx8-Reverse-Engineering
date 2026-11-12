/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00068f34: Table 2D - 3 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a4dc: Table 2D - 145 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a4f0: Table 2D - 146 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00068fe0: Table 3D - 2 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00068ffc: Table 3D - 3 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0000e910; body bytes: 946; decompiled */

uint FUN_0000e910(void)

{
  undefined4 snapshot_inferred_coolant_temperature_ffffa98c;
  byte snapshot_cranking_active_ffffaa62_ffffaa62;
  float snapshot_DAT_ffffb41c;
  char cVar4;
  float snapshot_engine_load_ffffc0b4;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  undefined4 uVar9;
  float fVar10;
  float fVar11;
  float snapshot_DAT_ffffa448;
  float snapshot_inferred_predicted_engine_speed_ffffb55c;
  float snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  cVar4 = DAT_ffffb53a;
  snapshot_DAT_ffffb41c = DAT_ffffb41c;
  snapshot_cranking_active_ffffaa62_ffffaa62 = cranking_active_ffffaa62_ffffaa62;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_DAT_ffffa448 = DAT_ffffa448;
  snapshot_inferred_predicted_engine_speed_ffffb55c = inferred_predicted_engine_speed_ffffb55c;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffa470 = (float)lookup_2d_descriptor_scaled(inferred_predicted_engine_speed_ffffb55c,&tbl_table_2d_145_0006a4dc);
  DAT_ffffa474 = (float)lookup_2d_descriptor_scaled(intake_air_temperature_ffffaddc,&tbl_table_2d_146_0006a4f0);
  DAT_ffffa478 = DAT_ffffa470 * DAT_ffffa474;
  DAT_ffffa47c = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_3_00068f34);
  fVar10 = DAT_ffffa47c + 0.015;
  fVar11 = DAT_ffffa44c + snapshot_DAT_ffffa448;
  uVar9 = rx8_decode_u8_affine(0x3f800000,0,(int)DAT_ffffa461);
  DAT_ffffa484 = (float)lookup_3d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,uVar9,&tbl_table_3d_2_00068fe0);
  DAT_ffffa488 = (float)lookup_3d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,uVar9,&tbl_table_3d_3_00068ffc);
  if (DAT_ffffa47c <= snapshot_engine_load_ffffc0b4) {
    if (fVar10 <= snapshot_engine_load_ffffc0b4) {
      DAT_ffffa450 = '\0';
    }
  }
  else {
    DAT_ffffa450 = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < fVar11) {
    if (snapshot_engine_speed_rpm_ffffb548 < snapshot_DAT_ffffa448) {
      DAT_ffffa49a = '\0';
    }
  }
  else {
    DAT_ffffa49a = '\x01';
  }
  if (snapshot_inferred_predicted_engine_speed_ffffb55c < fVar11) {
    if (snapshot_inferred_predicted_engine_speed_ffffb55c < snapshot_DAT_ffffa448) {
      DAT_ffffa49b = '\0';
    }
  }
  else {
    DAT_ffffa49b = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < fVar11 - DAT_ffffa484) {
    if (snapshot_engine_speed_rpm_ffffb548 < snapshot_DAT_ffffa448 - DAT_ffffa484) {
      DAT_ffffa49c = '\0';
    }
  }
  else {
    DAT_ffffa49c = '\x01';
  }
  if (snapshot_inferred_predicted_engine_speed_ffffb55c < fVar11 - DAT_ffffa488) {
    if (snapshot_inferred_predicted_engine_speed_ffffb55c < snapshot_DAT_ffffa448 - DAT_ffffa488) {
      DAT_ffffa49d = '\0';
    }
  }
  else {
    DAT_ffffa49d = '\x01';
  }
  if (snapshot_DAT_ffffb41c <= DAT_ffffa478) {
    if (snapshot_DAT_ffffb41c <= DAT_ffffa478 - 0.5) {
      DAT_ffffa49e = '\0';
    }
  }
  else {
    DAT_ffffa49e = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 3000.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 2800.0) {
      DAT_ffffa49f = '\0';
    }
  }
  else {
    DAT_ffffa49f = '\x01';
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 3000.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 2800.0) {
      DAT_ffffa4a0 = '\0';
    }
  }
  else {
    DAT_ffffa4a0 = '\x01';
  }
  if (((engine_running_ffffa428 == '\x01') && (DAT_ffffd26a == '\0')) &&
     ((snapshot_cranking_active_ffffaa62_ffffaa62 == 1 || (DAT_ffffa450 == '\x01')))) {
    DAT_ffffa463 = '\x01';
  }
  else {
    DAT_ffffa463 = '\0';
  }
  iVar8 = 0;
  if ((DAT_ffffa463 == '\0') || (DAT_ffffa49b == '\0')) {
    iVar8 = 2;
  }
  else if (DAT_ffffa49a == '\x01') {
    iVar8 = 1;
  }
  if ((automatic_transmission_ffffb534 == '\0') && (DAT_ffffca4c == '\x01')) {
    if (DAT_ffffa49f != '\x01') {
      DAT_ffffa48e = 0;
      goto LAB_0000ebd0;
    }
    puVar7 = &DAT_0006c29a;
  }
  else {
    if (DAT_ffffa4a0 != '\x01') {
      DAT_ffffa48e = 0;
      goto LAB_0000ebd0;
    }
    puVar7 = &DAT_0006c29e;
  }
  DAT_ffffa48e = *puVar7;
LAB_0000ebd0:
  if ((((iVar8 == 2) &&
       (((cVar4 == '\x01' || (DAT_ffffa49d == '\0')) ||
        ((DAT_ffffa49e == '\x01' && ((snapshot_cranking_active_ffffaa62_ffffaa62 == 0 || (DAT_ffffa49b == '\x01')))))))) ||
      (fuel_cut_allowed_ffffa964 == '\x01')) || ((DAT_ffffcc71 == '\x01' || (DAT_ffffb2cf == '\x01')))) {
    fuel_cut_request_b_ffffa465 = '\0';
  }
  else if (((iVar8 == 1) && (DAT_ffffa48e <= DAT_ffffa490)) ||
          ((cVar4 == '\0' &&
           ((((DAT_ffffa49e == '\0' && (DAT_ffffa48e <= DAT_ffffa492)) ||
             ((snapshot_cranking_active_ffffaa62_ffffaa62 == 1 && ((DAT_ffffa48e <= DAT_ffffa494 && (DAT_ffffa49a == '\0')))))) &&
            (DAT_ffffa49c == '\x01')))))) {
    fuel_cut_request_b_ffffa465 = '\x01';
  }
  if (iVar8 == 2) {
    fuel_cut_request_a_ffffa464 = 0;
  }
  else if (((iVar8 == 1) && (fuel_cut_request_b_ffffa465 == '\x01')) && (DAT_ffffa460 <= DAT_ffffa498)) {
    fuel_cut_request_a_ffffa464 = 1;
  }
  if (fuel_cut_request_b_ffffa465 == '\x01') {
    DAT_ffffa498 = rx8_add_u8_saturate((int)(char)DAT_ffffa498,1);
  }
  else {
    DAT_ffffa498 = 0;
  }
  if (iVar8 == 1) {
    DAT_ffffa490 = rx8_add_u16_saturate((int)(short)DAT_ffffa490,1);
  }
  else {
    DAT_ffffa490 = 0;
  }
  if (DAT_ffffa49e == '\0') {
    DAT_ffffa492 = rx8_add_u16_saturate((int)(short)DAT_ffffa492,1);
  }
  else {
    DAT_ffffa492 = 0;
  }
  uVar6 = (uint)snapshot_cranking_active_ffffaa62_ffffaa62;
  if (uVar6 == 1) {
    uVar6 = rx8_add_u16_saturate((int)(short)DAT_ffffa494,1);
    DAT_ffffa494 = (ushort)uVar6;
  }
  else {
    DAT_ffffa494 = 0;
  }
  return uVar6;
}


