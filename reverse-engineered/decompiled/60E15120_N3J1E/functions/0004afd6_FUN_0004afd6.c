/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006bb3c: Table 2D - 285 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bb1c: Table 2D - 390 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bb50: Table 3D - 100 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bb6c: Table 3D - 101 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004afd6; body bytes: 282; decompiled */

uint FUN_0004afd6(void)

{
  char cVar1;
  byte snapshot_fuel_cut_flag_b_ffffa445;
  uint uVar3;
  undefined *puVar4;
  float fVar5;
  undefined4 uVar6;
  float extraout_fr0;
  
  snapshot_fuel_cut_flag_b_ffffa445 = fuel_cut_flag_b_ffffa445;
  cVar1 = fuel_cut_flag_a_ffffa444;
  if ((DAT_ffffcdf1 == '\0') && (fuel_cut_flag_a_ffffa444 == '\x01')) {
    DAT_ffffcdec = 0x3e;
    DAT_ffffcdf3 = 1;
  }
  else if (DAT_ffffcdec != 0) {
    DAT_ffffcdec = DAT_ffffcdec + -1;
  }
  if ((DAT_ffffcdf2 == '\0') && (fuel_cut_flag_b_ffffa445 == 1)) {
    DAT_ffffcdee = 0x3e;
    DAT_ffffcdf3 = 1;
  }
  else if (DAT_ffffcdee != 0) {
    DAT_ffffcdee = DAT_ffffcdee + -1;
  }
  uVar3 = (uint)engine_running_ffffa428;
  if ((((uVar3 == 1) && (fuel_cut_flag_a_ffffa444 == '\0')) && (uVar3 = (uint)fuel_cut_flag_b_ffffa445, uVar3 == 0)) &&
     ((uVar3 = (uint)DAT_ffffcdf3, uVar3 == 1 &&
      ((DAT_ffffcdec == 0 || (uVar3 = (uint)DAT_ffffcdee, uVar3 == 0)))))) {
    uVar6 = engine_speed_rpm_ffffb548;
    DAT_ffffcdf0 = rx8_lookup_2d_raw_u8(engine_speed_rpm_ffffb548,&tbl_table_2d_390_check_datatype_0006bb1c);
    uVar3 = (uint)DAT_ffffcdf0;
    if (DAT_ffffcde4 <= uVar3) {
      if (DAT_ffffaa62 == '\0') {
        puVar4 = &tbl_table_3d_100_0006bb50;
      }
      else {
        puVar4 = &tbl_table_3d_101_0006bb6c;
      }
      fVar5 = (float)lookup_3d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,uVar6,puVar4);
      uVar6 = rx8_decode_u16_affine(0x42800000,0,(int)DAT_ffffc168);
      uVar3 = lookup_2d_descriptor_scaled(uVar6,&tbl_table_2d_285_0006bb3c);
      DAT_ffffcde0 = fVar5 * extraout_fr0;
      DAT_ffffcde5 = 1;
    }
  }
  DAT_ffffcdf1 = cVar1;
  DAT_ffffcdf2 = snapshot_fuel_cut_flag_b_ffffa445;
  return uVar3;
}


