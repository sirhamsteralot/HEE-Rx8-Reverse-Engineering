/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006bb28: Table 2D - 284 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bb1c: Table 2D - 390 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004af14; body bytes: 194; decompiled */

uint FUN_0004af14(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  float arg1;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  cVar2 = fuel_cut_flag_b_ffffa445;
  cVar1 = fuel_cut_flag_a_ffffa444;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffcdf0 = rx8_lookup_2d_raw_u8(engine_speed_rpm_ffffb548,&tbl_table_2d_390_check_datatype_0006bb1c);
  arg1 = 0.0;
  if (((engine_running_ffffa428 == '\0') || (cVar1 == '\x01')) || (cVar2 == '\x01')) {
    DAT_ffffcde0 = 0.0;
    DAT_ffffcde5 = 0;
  }
  else if (((DAT_ffffcdf3 == '\0') || ((DAT_ffffcdec != 0 && (DAT_ffffcdee != 0)))) ||
          (DAT_ffffcdf0 < DAT_ffffcde4)) {
    DAT_ffffcde8 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_284_0006bb28);
    DAT_ffffcde0 = rx8_max_float(DAT_ffffcde0 - DAT_ffffcde8,arg1);
  }
  uVar3 = (uint)DAT_ffffcde5;
  if (uVar3 == 1) {
    uVar3 = rx8_add_u8_saturate((int)(char)DAT_ffffcde4,1);
    DAT_ffffcde4 = (byte)uVar3;
  }
  else {
    DAT_ffffcde4 = 0;
  }
  return uVar3;
}


