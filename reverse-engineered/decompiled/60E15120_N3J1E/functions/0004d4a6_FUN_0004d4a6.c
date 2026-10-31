/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006bbe0: Table 2D - 391 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bbf8: Table 2D - 393 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc10: Table 2D - 395 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc28: Table 2D - 397 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004d4a6; body bytes: 448; decompiled */

void FUN_0004d4a6(void)

{
  float fVar1;
  float fVar2;
  float arg1;
  float arg1_00;
  float arg1_01;
  float arg1_02;
  float fVar3;
  float arg0;
  float arg0_00;
  float arg0_01;
  float arg0_02;
  undefined4 snapshot_vehicle_speed_ffffbbb4;
  float fVar5;
  
  fVar5 = 0.0;
  snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
  if (DAT_ffffcf34 == '\0') {
    DAT_ffffcef8 = 0.0;
    DAT_ffffcf00 = 0.0;
    DAT_ffffcf08 = 0.0;
    DAT_ffffcf10 = 0.0;
  }
  else {
    if (DAT_ffffcf50 != '\0') {
      if (DAT_ffffcf72 == '\0') {
        DAT_ffffcef8 = DAT_ffffcef4;
      }
      else {
        DAT_ffffcef8 = rx8_min_float(DAT_ffffcef4,DAT_ffffcef8);
      }
    }
    if (DAT_ffffcf53 != '\0') {
      if (DAT_ffffcf73 == '\0') {
        DAT_ffffcf00 = DAT_ffffcef4;
      }
      else {
        DAT_ffffcf00 = rx8_min_float(DAT_ffffcef4,DAT_ffffcf00);
      }
    }
    if (DAT_ffffcf56 != '\0') {
      if (DAT_ffffcf74 == '\0') {
        DAT_ffffcf08 = DAT_ffffcef4;
      }
      else {
        DAT_ffffcf08 = rx8_min_float(DAT_ffffcef4,DAT_ffffcf08);
      }
    }
    if (DAT_ffffcf59 != '\0') {
      if (DAT_ffffcf75 == '\0') {
        DAT_ffffcf10 = DAT_ffffcef4;
      }
      else {
        DAT_ffffcf10 = rx8_min_float(DAT_ffffcef4,DAT_ffffcf10);
      }
    }
  }
  arg0 = DAT_ffffcef8 - 1.5;
  arg1 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_391_check_datatype_0006bbe0);
  arg0_00 = DAT_ffffcf00 - 1.5;
  arg1_00 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_393_check_datatype_0006bbf8);
  arg0_01 = DAT_ffffcf08 - 1.5;
  arg1_01 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_395_check_datatype_0006bc10);
  arg0_02 = DAT_ffffcf10 - 1.5;
  arg1_02 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_397_check_datatype_0006bc28);
  fVar1 = fVar5;
  fVar2 = fVar5;
  fVar3 = fVar5;
  if (DAT_ffffcf34 != '\0') {
    if (DAT_ffffcf50 != '\0') {
      DAT_ffffcefc = rx8_max_float(arg0,arg1);
    }
    if (DAT_ffffcf53 != '\0') {
      DAT_ffffcf04 = rx8_max_float(arg0_00,arg1_00);
    }
    if (DAT_ffffcf56 != '\0') {
      DAT_ffffcf0c = rx8_max_float(arg0_01,arg1_01);
    }
    fVar5 = DAT_ffffcefc;
    fVar1 = DAT_ffffcf04;
    fVar2 = DAT_ffffcf0c;
    fVar3 = DAT_ffffcf14;
    if (DAT_ffffcf59 != '\0') {
      fVar3 = rx8_max_float(arg0_02,arg1_02);
      fVar5 = DAT_ffffcefc;
      fVar1 = DAT_ffffcf04;
      fVar2 = DAT_ffffcf0c;
    }
  }
  DAT_ffffcf14 = fVar3;
  DAT_ffffcf0c = fVar2;
  DAT_ffffcf04 = fVar1;
  DAT_ffffcefc = fVar5;
  DAT_ffffcf72 = DAT_ffffcf50;
  DAT_ffffcf73 = DAT_ffffcf53;
  DAT_ffffcf74 = DAT_ffffcf56;
  DAT_ffffcf75 = DAT_ffffcf59;
  return;
}


