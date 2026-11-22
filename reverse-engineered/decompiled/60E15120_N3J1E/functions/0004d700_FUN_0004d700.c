/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006bbec: Table 2D - 392 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc04: Table 2D - 394 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc1c: Table 2D - 396 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc34: Table 2D - 398 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * cruise_switch_plausibility_timers [high]: Per-switch countdown timers 0xffffcf51/52/54/55/57/58/5a/5b armed at 0x3e when filtered error 0xffffcef4 exceeds channel max + 1.5 or vss tables 0x6bbec/0x6bc04/0x6bc1c/0x6bc34, decremented while error high, cleared when 0xffffcf34==0; expiry clears latches 0xffffcf3a/3c/3e/40. Pool scan: cf51-cf5b referenced only inside the cruise cluster (0x4ca7e/0x4d4a6/0x4d700) - no external consumer. Called from batch 0x2e692 (jsr 0x2e6d4, pool 0x2e7e4).
 * RAM 0xffffcef4 cruise_filtered_speed_error (float): Filtered error + per-switch vehicle-speed offset computed by 0x4ca7e (from mean 0xffffcee4); min/max tracked per channel by 0x4d4a6, thresholds compared in 0x4d700.
 * RAM 0xffffcf34 cruise_enable_flag (uint8): Set by 0x4c896 = (0xffffbced && 0xffffbcf8 >= 0xffffa9b4): cruise enabled while cruise output percent >= TP1 percent (pedal override). Emulator: bcf8=50 < a9b4=80 -> 0; bcf8=90 -> 1.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004d700; body bytes: 896; decompiled */

undefined1 * cruise_switch_plausibility_timers(void)

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
  if (cruise_enable_flag_ffffcf34 == '\0') {
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
       (((DAT_ffffcf51 != '\0' && (DAT_ffffcf52 != '\0')) && (fVar14 <= cruise_filtered_speed_error_ffffcef4)))) {
      DAT_ffffcf51 = '>';
      DAT_ffffcf52 = '>';
    }
    else {
      if ((cruise_filtered_speed_error_ffffcef4 <= DAT_ffffcefc) && (DAT_ffffcf51 != '\0')) {
        DAT_ffffcf51 = DAT_ffffcf51 + -1;
      }
      if ((cruise_filtered_speed_error_ffffcef4 <= fVar10) && (DAT_ffffcf52 != '\0')) {
        DAT_ffffcf52 = DAT_ffffcf52 + -1;
      }
    }
    if ((DAT_ffffcf53 != '\0') ||
       (((DAT_ffffcf54 != '\0' && (DAT_ffffcf55 != '\0')) && (fVar15 <= cruise_filtered_speed_error_ffffcef4)))) {
      DAT_ffffcf54 = '>';
      DAT_ffffcf55 = '>';
    }
    else {
      if ((cruise_filtered_speed_error_ffffcef4 <= DAT_ffffcf04) && (DAT_ffffcf54 != '\0')) {
        DAT_ffffcf54 = DAT_ffffcf54 + -1;
      }
      if ((cruise_filtered_speed_error_ffffcef4 <= fVar11) && (DAT_ffffcf55 != '\0')) {
        DAT_ffffcf55 = DAT_ffffcf55 + -1;
      }
    }
    if ((DAT_ffffcf56 != '\0') ||
       (((DAT_ffffcf57 != '\0' && (DAT_ffffcf58 != '\0')) && (fVar16 <= cruise_filtered_speed_error_ffffcef4)))) {
      DAT_ffffcf57 = '>';
      DAT_ffffcf58 = '>';
    }
    else {
      if ((cruise_filtered_speed_error_ffffcef4 <= DAT_ffffcf0c) && (DAT_ffffcf57 != '\0')) {
        DAT_ffffcf57 = DAT_ffffcf57 + -1;
      }
      if ((cruise_filtered_speed_error_ffffcef4 <= fVar12) && (DAT_ffffcf58 != '\0')) {
        DAT_ffffcf58 = DAT_ffffcf58 + -1;
      }
    }
    if ((DAT_ffffcf59 != '\0') ||
       (((DAT_ffffcf5a != '\0' && (DAT_ffffcf5b != 0)) && (fVar17 <= cruise_filtered_speed_error_ffffcef4)))) {
      DAT_ffffcf5a = '>';
      DAT_ffffcf5b = 0x3e;
    }
    else {
      if ((cruise_filtered_speed_error_ffffcef4 <= DAT_ffffcf14) && (DAT_ffffcf5a != '\0')) {
        DAT_ffffcf5a = DAT_ffffcf5a + -1;
      }
      if ((cruise_filtered_speed_error_ffffcef4 <= fVar13) && (DAT_ffffcf5b != 0)) {
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


