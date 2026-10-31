/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x000692d0: Table 2D - 17 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000692e4: Table 2D - 18 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000692f8: Table 2D - 19 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006930c: Table 2D - 20 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069320: Table 2D - 21 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069334: Table 2D - 22 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069348: Table 2D - 23 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00014d10; body bytes: 456; decompiled */

undefined4 FUN_00014d10(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined4 extraout_r0;
  undefined4 uVar4;
  undefined4 extraout_r0_00;
  undefined **ppuVar5;
  float extraout_fr0;
  float extraout_fr0_00;
  float fVar6;
  float snapshot_DAT_ffffa838;
  
  cVar3 = DAT_ffffbd69;
  cVar2 = DAT_ffffb53c;
  cVar1 = DAT_ffffa8a8;
  if (vehicle_speed_ffffbbb4 < 10.0) {
    if (vehicle_speed_ffffbbb4 < 9.0) {
      DAT_ffffa82b = '\0';
    }
  }
  else {
    DAT_ffffa82b = '\x01';
  }
  if ((engine_stopped_latch_ffffa41c == '\x01') ||
     ((DAT_ffffa7a8 < 0.0 &&
      (((DAT_ffffbd69 == '\0' && (DAT_ffffa828 == '\x01')) ||
       ((DAT_ffffb53c == '\0' && (DAT_ffffa829 == '\x01')))))))) {
    uVar4 = 1;
    DAT_ffffa7a8 = 0.0;
  }
  else if (DAT_ffffa7b4 == '\0') {
    if ((DAT_ffffa8a8 == '\x01') && (DAT_ffffa826 == '\0')) {
      uVar4 = 1;
      DAT_ffffa7a8 = DAT_ffffa8a4 + DAT_ffffa7a8;
    }
    else {
      DAT_ffffa7a8 = rx8_max_float(0.02,DAT_ffffa7c0 + 0.0);
      uVar4 = extraout_r0;
    }
  }
  else {
    snapshot_DAT_ffffa838 = DAT_ffffa838;
    if (((DAT_ffffa7b6 == '\0') && (DAT_ffffb53a == '\0')) && (DAT_ffffa82b == '\x01')) {
      uVar4 = inferred_coolant_temperature_ffffa990;
      DAT_ffffa7e4 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa990,&tbl_table_2d_19_000692f8);
      uVar4 = lookup_2d_descriptor_scaled(uVar4,&tbl_table_2d_20_0006930c);
      DAT_ffffa7e8 = extraout_fr0;
    }
    else {
      uVar4 = inferred_coolant_temperature_ffffa990;
      if (((DAT_ffffa6b7 == '\x01') || (DAT_ffffa6b8 == '\x01')) || (DAT_ffffa6b9 == '\x01')) {
        DAT_ffffa7e4 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa990,&tbl_table_2d_21_00069320);
        ppuVar5 = &tbl_table_2d_22_00069334;
      }
      else {
        DAT_ffffa7e4 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa990,&tbl_table_2d_17_000692d0);
        ppuVar5 = &tbl_table_2d_18_000692e4;
      }
      uVar4 = lookup_2d_descriptor_scaled(uVar4,ppuVar5);
      DAT_ffffa7e8 = extraout_fr0_00;
    }
    if (DAT_ffffa7b5 == '\0') {
      DAT_ffffa7c4 = DAT_ffffb550 - DAT_ffffa7ac;
      DAT_ffffa7f8 = (float)lookup_2d_descriptor_scaled(DAT_ffffa7c4,&tbl_table_2d_23_00069348);
      fVar6 = rx8_clamp_float(DAT_ffffa7a8 + DAT_ffffa7f8,DAT_ffffa7e4,DAT_ffffa7e8);
      uVar4 = extraout_r0_00;
      if (fVar6 <= DAT_ffffa7a8) {
        if (DAT_ffffa840 < snapshot_DAT_ffffa838) {
          DAT_ffffa7a8 = fVar6;
        }
      }
      else if (snapshot_DAT_ffffa838 < DAT_ffffa83c) {
        DAT_ffffa7a8 = fVar6;
      }
    }
  }
  DAT_ffffa826 = cVar1;
  DAT_ffffa828 = cVar3;
  DAT_ffffa829 = cVar2;
  return uVar4;
}


