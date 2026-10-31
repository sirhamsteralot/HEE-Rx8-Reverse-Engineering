/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006aca4: Table 2D - 184 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006acb8: Table 2D - 185 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006accc: Table 2D - 186 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ace0: Table 2D - 187 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006acf4: Table 2D - 188 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ad08: Table 2D - 189 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ad1c: Table 2D - 190 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003133c; body bytes: 310; decompiled */

char FUN_0003133c(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 snapshot_inferred_coolant_temperature_ffffa98c;
  float arg1;
  undefined4 snapshot_inferred_barometric_pressure_ffffad14;
  
  uVar1 = (uint)DAT_ffffa6b4 << 3;
  arg1 = 0.0;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_inferred_barometric_pressure_ffffad14 = inferred_barometric_pressure_ffffad14;
  if (uVar1 < 0x233) {
    fVar2 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_table_2d_184_0006aca4);
    fVar3 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_barometric_pressure_ffffad14,&tbl_table_2d_185_0006acb8);
    DAT_ffffbf58 = fVar2 * fVar3;
  }
  else if (uVar1 < 0x3a9) {
    DAT_ffffbf58 = rx8_max_float(DAT_ffffbf58 - 0.0008,0.0);
  }
  if (uVar1 < 0x1406) {
    if (0x3a8 < uVar1) {
      fVar2 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_table_2d_186_0006accc);
      fVar3 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_barometric_pressure_ffffad14,&tbl_table_2d_187_0006ace0);
      DAT_ffffbf5c = fVar2 * fVar3;
    }
  }
  else {
    DAT_ffffbf5c = rx8_max_float(DAT_ffffbf5c - 50.0,arg1);
  }
  if (uVar1 < 0x1406) {
    fVar2 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_table_2d_188_0006acf4);
    fVar3 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_barometric_pressure_ffffad14,&tbl_table_2d_189_0006ad08);
    fVar4 = (float)lookup_2d_descriptor_scaled(engine_load_ffffc0b4,&tbl_table_2d_190_0006ad1c);
    DAT_ffffbf60 = fVar2 * fVar3 * fVar4;
  }
  else {
    DAT_ffffbf60 = rx8_max_float(DAT_ffffbf60 - 50.0,arg1);
  }
  DAT_ffffbf48 = DAT_ffffbf60;
  if (((DAT_ffffa6b9 != '\x01') && (DAT_ffffbf48 = DAT_ffffbf58, DAT_ffffa6b7 != '\x01')) &&
     (DAT_ffffbf48 = DAT_ffffbf5c, DAT_ffffa6b8 != '\x01')) {
    DAT_ffffbf48 = arg1;
    return DAT_ffffa6b8;
  }
  return '\x01';
}


