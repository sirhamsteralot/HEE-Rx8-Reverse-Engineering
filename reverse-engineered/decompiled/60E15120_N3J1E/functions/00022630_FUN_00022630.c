/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a2cc: Table 2D - 128 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a2e0: Table 2D - 129 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a2f4: Table 2D - 130 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a308: Table 3D - 47 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a324: Table 3D - 48 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00022630; body bytes: 442; decompiled */

undefined4 FUN_00022630(void)

{
  float fVar1;
  undefined4 uVar2;
  float snapshot_DAT_ffffaa78;
  
  if (DAT_ffffaa78 < 44.0) {
    if (DAT_ffffaa78 < 39.0) {
      DAT_ffffb389 = '\0';
    }
  }
  else {
    DAT_ffffb389 = '\x01';
  }
  if (DAT_ffffaa78 < 45.0) {
    if (DAT_ffffaa78 < 40.0) {
      DAT_ffffb38a = '\0';
    }
  }
  else {
    DAT_ffffb38a = '\x01';
  }
  snapshot_DAT_ffffaa78 = DAT_ffffaa78;
  DAT_ffffb370 = (float)lookup_2d_descriptor_scaled(DAT_ffffaa78,&tbl_table_2d_130_0006a2f4);
  DAT_ffffb374 = (float)lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,maf_per_rotation_filtered_ffffaa38,&tbl_table_3d_48_0006a324);
  DAT_ffffb378 = (float)lookup_2d_descriptor_scaled(inferred_battery_voltage_ffffb590,&tbl_table_2d_129_0006a2e0);
  fVar1 = rx8_min_float(DAT_ffffb370,DAT_ffffb374);
  DAT_ffffb360 = DAT_ffffb378 * fVar1;
  if (DAT_ffffb389 == '\x01') {
    DAT_ffffb364 = DAT_ffffb354 - (snapshot_DAT_ffffaa78 - 30.0) * 4.5;
  }
  else if ((0.0 < DAT_ffffb354) && (DAT_ffffb354 < DAT_ffffb360)) {
    DAT_ffffb364 = DAT_ffffb364 + (snapshot_DAT_ffffaa78 - 30.0) * 0.1875;
  }
  if (DAT_ffffb358 == '\0') {
    DAT_ffffb368 = 0;
  }
  else {
    DAT_ffffb368 = rx8_add_u16_saturate((int)DAT_ffffb368,1);
  }
  fVar1 = 0.0;
  uVar2 = rx8_decode_u16_affine(0x43000000,0,(int)DAT_ffffb368);
  DAT_ffffb37c = (float)lookup_3d_descriptor_scaled(uVar2,DAT_ffffade0,&LAB_0006a308);
  DAT_ffffb380 = (float)lookup_2d_descriptor_scaled(snapshot_DAT_ffffaa78,&tbl_table_2d_128_0006a2cc);
  if (DAT_ffffb358 != '\0') {
    fVar1 = DAT_ffffb37c;
    if ((DAT_ffffb38a == '\x01') || (fVar1 = DAT_ffffb380, DAT_ffffb389 == '\x01')) {
      fVar1 = DAT_ffffb378 * fVar1;
    }
    else {
      fVar1 = (snapshot_DAT_ffffaa78 - 30.0) * 4.5;
      if (DAT_ffffb384 < 0xea) {
        fVar1 = fVar1 + (DAT_ffffb36c - snapshot_DAT_ffffaa78) * 0.75;
      }
      fVar1 = rx8_min_float(fVar1 + DAT_ffffb364,DAT_ffffb360);
    }
  }
  DAT_ffffb354 = fVar1;
  if (DAT_ffffb389 == '\x01') {
    DAT_ffffb384 = 0;
    uVar2 = 1;
  }
  else {
    uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffb384,1);
    DAT_ffffb384 = (ushort)uVar2;
  }
  DAT_ffffb36c = snapshot_DAT_ffffaa78;
  return uVar2;
}


