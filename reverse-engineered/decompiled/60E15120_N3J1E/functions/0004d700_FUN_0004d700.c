/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006bbec: Table 2D - 392 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc04: Table 2D - 394 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc1c: Table 2D - 396 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc34: Table 2D - 398 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004d700; body bytes: 896; decompiled */

undefined1 * FUN_0004d700(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte snapshot_DAT_ffffcf5b;
  undefined1 *puVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined4 snapshot_vehicle_speed_ffffbbb4;
  
  snapshot_DAT_ffffcf5b = DAT_ffffcf5b;
  cVar7 = DAT_ffffcf5a;
  cVar6 = DAT_ffffcf58;
  cVar5 = DAT_ffffcf57;
  cVar4 = DAT_ffffcf55;
  cVar3 = DAT_ffffcf54;
  cVar2 = DAT_ffffcf52;
  cVar1 = DAT_ffffcf51;
  fVar14 = DAT_ffffcefc + 1.5;
  snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
  fVar10 = (float)lookup_2d_descriptor_scaled(vehicle_speed_ffffbbb4,&tbl_table_2d_392_check_datatype_0006bbec);
  fVar15 = DAT_ffffcf04 + 1.5;
  fVar11 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_394_check_datatype_0006bc04);
  fVar16 = DAT_ffffcf0c + 1.5;
  fVar12 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_396_check_datatype_0006bc1c);
  fVar17 = DAT_ffffcf14 + 1.5;
  fVar13 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_398_check_datatype_0006bc34);
  if (DAT_ffffcf34 == '\0') {
    DAT_ffffcf51 = '\0';
    DAT_ffffcf52 = '\0';
    DAT_ffffcf54 = '\0';
    DAT_ffffcf55 = '\0';
    DAT_ffffcf57 = '\0';
    DAT_ffffcf58 = '\0';
    DAT_ffffcf5a = '\0';
    DAT_ffffcf5b = 0;
  }
  else {
    if ((DAT_ffffcf50 != '\0') ||
       (((DAT_ffffcf51 != '\0' && (DAT_ffffcf52 != '\0')) && (fVar14 <= DAT_ffffcef4)))) {
      DAT_ffffcf51 = '>';
      DAT_ffffcf52 = '>';
    }
    else {
      if ((DAT_ffffcef4 <= DAT_ffffcefc) && (DAT_ffffcf51 != '\0')) {
        DAT_ffffcf51 = DAT_ffffcf51 + -1;
      }
      if ((DAT_ffffcef4 <= fVar10) && (DAT_ffffcf52 != '\0')) {
        DAT_ffffcf52 = DAT_ffffcf52 + -1;
      }
    }
    if ((DAT_ffffcf53 != '\0') ||
       (((DAT_ffffcf54 != '\0' && (DAT_ffffcf55 != '\0')) && (fVar15 <= DAT_ffffcef4)))) {
      DAT_ffffcf54 = '>';
      DAT_ffffcf55 = '>';
    }
    else {
      if ((DAT_ffffcef4 <= DAT_ffffcf04) && (DAT_ffffcf54 != '\0')) {
        DAT_ffffcf54 = DAT_ffffcf54 + -1;
      }
      if ((DAT_ffffcef4 <= fVar11) && (DAT_ffffcf55 != '\0')) {
        DAT_ffffcf55 = DAT_ffffcf55 + -1;
      }
    }
    if ((DAT_ffffcf56 != '\0') ||
       (((DAT_ffffcf57 != '\0' && (DAT_ffffcf58 != '\0')) && (fVar16 <= DAT_ffffcef4)))) {
      DAT_ffffcf57 = '>';
      DAT_ffffcf58 = '>';
    }
    else {
      if ((DAT_ffffcef4 <= DAT_ffffcf0c) && (DAT_ffffcf57 != '\0')) {
        DAT_ffffcf57 = DAT_ffffcf57 + -1;
      }
      if ((DAT_ffffcef4 <= fVar12) && (DAT_ffffcf58 != '\0')) {
        DAT_ffffcf58 = DAT_ffffcf58 + -1;
      }
    }
    if ((DAT_ffffcf59 != '\0') ||
       (((DAT_ffffcf5a != '\0' && (DAT_ffffcf5b != 0)) && (fVar17 <= DAT_ffffcef4)))) {
      DAT_ffffcf5a = '>';
      DAT_ffffcf5b = 0x3e;
    }
    else {
      if ((DAT_ffffcef4 <= DAT_ffffcf14) && (DAT_ffffcf5a != '\0')) {
        DAT_ffffcf5a = DAT_ffffcf5a + -1;
      }
      if ((DAT_ffffcef4 <= fVar13) && (DAT_ffffcf5b != 0)) {
        DAT_ffffcf5b = DAT_ffffcf5b - 1;
      }
    }
  }
  if (((cVar1 != '\0') && (DAT_ffffcf51 == '\0')) || ((cVar2 != '\0' && (DAT_ffffcf52 == '\0')))) {
    DAT_ffffcf3a = 0;
  }
  if (((cVar3 != '\0') && (DAT_ffffcf54 == '\0')) || ((cVar4 != '\0' && (DAT_ffffcf55 == '\0')))) {
    DAT_ffffcf3c = 0;
  }
  if (((cVar5 != '\0') && (DAT_ffffcf57 == '\0')) || ((cVar6 != '\0' && (DAT_ffffcf58 == '\0')))) {
    DAT_ffffcf3e = 0;
  }
  if (((cVar7 != '\0') && (DAT_ffffcf5a == '\0')) ||
     ((puVar9 = (undefined1 *)(uint)snapshot_DAT_ffffcf5b, puVar9 != (undefined1 *)0x0 && (DAT_ffffcf5b == 0)))) {
    puVar9 = &DAT_ffffcf40;
    DAT_ffffcf40 = 0;
  }
  return puVar9;
}


