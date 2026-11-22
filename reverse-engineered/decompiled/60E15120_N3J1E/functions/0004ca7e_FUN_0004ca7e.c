/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006bc40: Table 2D - 399 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc4c: Table 2D - 400 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc58: Table 2D - 401 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc64: Table 2D - 402 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc70: Table 2D - 403 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * cruise_speed_error_filter_stage [high]: Cruise stage in batch 0x2e692 (jsr via pool 0x2e7dc at 0x2e6c6; batch called from task[10] body 0x11744). Debounces cruise switch flags 0xffffcf47-0xffffcf4c (0x3e=62 counts -> 0xffffcf5c-0xffffcf63), clamps the 12-sample mean 0xffffcee4 (ring 0xffffceb4-0xffffcedc shifted by 0x4dce8) to +/-15.0, first-order filter factor 0.1 -> 0xffffcef0/0xffffceec, adds per-switch vehicle-speed offsets from 2-D tbl descriptors 0x6bc40-0x6bc70 (n=10, ax 0x7d368-0x7d4a8, data 0x7d390-0x7d4d0, type 0; ROM bytes verified) -> output 0xffffcef4; 3.2f tolerance (0x404ccccd @ROM 0x7d0c8/0x7d0cc via ptr pools 0x4ce14/0x4ce1c) vs 0xffffbfa0/0xffffbfac and readValue float 0xffff866c. Switch source: 0x4c828 decodes 0xffffbaed (1-6) into cf47-4c.
 * RAM 0xffffcee4 cruise_speed_error_mean12 (float): Mean of the 12-sample ring 0xffffceb4-0xffffcedc computed by 0x4dce8 (sum/12.0); clamped to +/-15.0 and filtered by 0x4ca7e.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004ca7e; body bytes: 2200; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0004d2f0) */

void cruise_speed_error_filter_stage(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined4 snapshot_vehicle_speed_ffffbbb4;
  
  cVar6 = DAT_ffffcf40;
  cVar5 = DAT_ffffcf3e;
  cVar4 = DAT_ffffcf3c;
  cVar3 = DAT_ffffcf3a;
  fVar16 = 0.0;
  fVar12 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&cruise_set_speed_kmh_ffff866c);
  cVar11 = DAT_ffffcf4c;
  cVar10 = DAT_ffffcf4b;
  cVar9 = DAT_ffffcf4a;
  cVar8 = DAT_ffffcf49;
  cVar7 = DAT_ffffcf48;
  cVar2 = DAT_ffffbfb9;
  cVar1 = DAT_ffffbfb5;
  if (DAT_ffffbfb9 == '\0') {
    DAT_ffffcf5c = '>';
    DAT_ffffcf5d = '>';
    DAT_ffffcf5e = '>';
    DAT_ffffcf5f = '>';
  }
  else {
    if (DAT_ffffcf49 == '\0') {
      DAT_ffffcf5c = '>';
    }
    else if (DAT_ffffcf5c != '\0') {
      DAT_ffffcf5c = DAT_ffffcf5c + -1;
    }
    if (DAT_ffffcf4a == '\0') {
      DAT_ffffcf5d = '>';
    }
    else if (DAT_ffffcf5d != '\0') {
      DAT_ffffcf5d = DAT_ffffcf5d + -1;
    }
    if (DAT_ffffcf4b == '\0') {
      DAT_ffffcf5e = '>';
    }
    else if (DAT_ffffcf5e != '\0') {
      DAT_ffffcf5e = DAT_ffffcf5e + -1;
    }
    if (DAT_ffffcf4c == '\0') {
      DAT_ffffcf5f = '>';
    }
    else if (DAT_ffffcf5f != '\0') {
      DAT_ffffcf5f = DAT_ffffcf5f + -1;
    }
  }
  if (DAT_ffffbfb5 == '\0') {
    DAT_ffffcf60 = '>';
    DAT_ffffcf61 = '>';
    DAT_ffffcf62 = '>';
    DAT_ffffcf63 = '>';
  }
  else {
    if (DAT_ffffcf49 == '\0') {
      DAT_ffffcf60 = '>';
    }
    else if (DAT_ffffcf60 != '\0') {
      DAT_ffffcf60 = DAT_ffffcf60 + -1;
    }
    if (DAT_ffffcf4a == '\0') {
      DAT_ffffcf61 = '>';
    }
    else if (DAT_ffffcf61 != '\0') {
      DAT_ffffcf61 = DAT_ffffcf61 + -1;
    }
    if (DAT_ffffcf4b == '\0') {
      DAT_ffffcf62 = '>';
    }
    else if (DAT_ffffcf62 != '\0') {
      DAT_ffffcf62 = DAT_ffffcf62 + -1;
    }
    if (DAT_ffffcf4c == '\0') {
      DAT_ffffcf63 = '>';
    }
    else if (DAT_ffffcf63 != '\0') {
      DAT_ffffcf63 = DAT_ffffcf63 + -1;
    }
  }
  if (DAT_ffffcf50 != '\0') {
    DAT_ffffcf50 = DAT_ffffcf50 + -1;
  }
  if (DAT_ffffcf53 != '\0') {
    DAT_ffffcf53 = DAT_ffffcf53 + -1;
  }
  if (DAT_ffffcf56 != '\0') {
    DAT_ffffcf56 = DAT_ffffcf56 + -1;
  }
  if (DAT_ffffcf59 != '\0') {
    DAT_ffffcf59 = DAT_ffffcf59 + -1;
  }
  if ((DAT_ffffcf4f == '\x01') || (cruise_enable_flag_ffffcf34 == '\0')) {
    DAT_ffffcf39 = 0;
    DAT_ffffcf3a = '\0';
    DAT_ffffcf3b = 0;
    DAT_ffffcf3c = '\0';
    DAT_ffffcf3d = 0;
    DAT_ffffcf3e = '\0';
    DAT_ffffcf3f = 0;
    DAT_ffffcf40 = '\0';
LAB_0004d1b6:
    if ((DAT_ffffcf6e != '\x01') || (DAT_ffffcf4c != '\0')) goto LAB_0004d1ca;
LAB_0004d214:
    DAT_ffffcf64 = '>';
  }
  else {
    if ((((((DAT_ffffbfb5 == '\0') && (DAT_ffffcf68 == '\x01')) && (DAT_ffffbfb9 == '\0')) ||
         ((DAT_ffffbfb5 == '\x01' && (fVar12 - DAT_ffffbfa0 <= 3.2)))) ||
        ((DAT_ffffcf6f == '\x01' && ((DAT_ffffbfb5 == '\0' && (DAT_ffffbfb9 == '\0')))))) ||
       ((DAT_ffffbfb9 == '\x01' && (DAT_ffffbfac - 3.2 < DAT_ffffbfa0)))) {
      DAT_ffffcf39 = 0;
      DAT_ffffcf3b = 0;
      DAT_ffffcf3d = 0;
      DAT_ffffcf3f = 0;
    }
    else {
      if ((((DAT_ffffcf5c == '\0') && (DAT_ffffcf30 == 0)) ||
          ((DAT_ffffcf60 == '\0' && (DAT_ffffcf32 == 0)))) ||
         ((((DAT_ffffbfb9 == '\x01' || (DAT_ffffbfb5 == '\x01')) &&
           ((DAT_ffffcf6e == '\x01' ||
            (((DAT_ffffcf6d == '\x01' || (DAT_ffffcf6c == '\x01')) || (DAT_ffffcf6b == '\x01'))))))
          && ((DAT_ffffcf48 == '\x01' || (DAT_ffffcf47 == '\x01')))))) {
        DAT_ffffcf39 = 1;
      }
      if ((((DAT_ffffcf5d == '\0') && (DAT_ffffcf30 == 0)) ||
          ((DAT_ffffcf61 == '\0' && (DAT_ffffcf32 == 0)))) ||
         ((((DAT_ffffbfb9 == '\x01' || (DAT_ffffbfb5 == '\x01')) &&
           ((DAT_ffffcf6e == '\x01' || ((DAT_ffffcf6d == '\x01' || (DAT_ffffcf6c == '\x01')))))) &&
          ((DAT_ffffcf49 == '\x01' || ((DAT_ffffcf48 == '\x01' || (DAT_ffffcf47 == '\x01')))))))) {
        DAT_ffffcf3b = 1;
      }
      if ((((DAT_ffffcf5e == '\0') && (DAT_ffffcf30 == 0)) ||
          ((DAT_ffffcf62 == '\0' && (DAT_ffffcf32 == 0)))) ||
         (((DAT_ffffbfb9 == '\x01' || (DAT_ffffbfb5 == '\x01')) &&
          (((DAT_ffffcf6e == '\x01' || (DAT_ffffcf6d == '\x01')) &&
           ((((DAT_ffffcf4a == '\x01' || (DAT_ffffcf49 == '\x01')) || (DAT_ffffcf48 == '\x01')) ||
            (DAT_ffffcf47 == '\x01')))))))) {
        DAT_ffffcf3d = 1;
      }
      if ((((DAT_ffffcf5f == '\0') && (DAT_ffffcf30 == 0)) ||
          ((DAT_ffffcf63 == '\0' && (DAT_ffffcf32 == 0)))) ||
         (((DAT_ffffbfb9 == '\x01' || (DAT_ffffbfb5 == '\x01')) &&
          ((DAT_ffffcf6e == '\x01' &&
           ((((DAT_ffffcf4b == '\x01' || (DAT_ffffcf4a == '\x01')) || (DAT_ffffcf49 == '\x01')) ||
            ((DAT_ffffcf48 == '\x01' || (DAT_ffffcf47 == '\x01')))))))))) {
        DAT_ffffcf3f = 1;
      }
    }
    if (DAT_ffffcf44 != '\x01') goto LAB_0004d1b6;
    if ((((DAT_ffffcf6e == '\x01') || (DAT_ffffcf6d == '\x01')) ||
        ((DAT_ffffcf6c == '\x01' || (DAT_ffffcf6b == '\x01')))) &&
       (((DAT_ffffcf48 == '\x01' || (DAT_ffffcf47 == '\x01')) &&
        (DAT_ffffcf3a = '\x01', cVar3 == '\0')))) {
      DAT_ffffcf50 = '\x1f';
    }
    if ((((DAT_ffffcf6e == '\x01') || (DAT_ffffcf6d == '\x01')) || (DAT_ffffcf6c == '\x01')) &&
       ((((DAT_ffffcf49 == '\x01' || (DAT_ffffcf48 == '\x01')) || (DAT_ffffcf47 == '\x01')) &&
        (DAT_ffffcf3c = '\x01', cVar4 == '\0')))) {
      DAT_ffffcf53 = '\x1f';
    }
    if (((DAT_ffffcf6e == '\x01') || (DAT_ffffcf6d == '\x01')) &&
       (((DAT_ffffcf4a == '\x01' ||
         (((DAT_ffffcf49 == '\x01' || (DAT_ffffcf48 == '\x01')) || (DAT_ffffcf47 == '\x01')))) &&
        (DAT_ffffcf3e = '\x01', cVar5 == '\0')))) {
      DAT_ffffcf56 = '\x1f';
    }
    if (DAT_ffffcf6e == '\x01') {
      if ((((DAT_ffffcf4b == '\x01') || (DAT_ffffcf4a == '\x01')) ||
          ((DAT_ffffcf49 == '\x01' || ((DAT_ffffcf48 == '\x01' || (DAT_ffffcf47 == '\x01')))))) &&
         (DAT_ffffcf40 = '\x01', cVar6 == '\0')) {
        DAT_ffffcf59 = '\x1f';
      }
      goto LAB_0004d1b6;
    }
LAB_0004d1ca:
    if ((((DAT_ffffcf6d == '\x01') && (DAT_ffffcf4b == '\0')) ||
        (((DAT_ffffcf6c == '\x01' && (DAT_ffffcf4a == '\0')) ||
         ((DAT_ffffcf6b == '\x01' && (DAT_ffffcf49 == '\0')))))) ||
       ((DAT_ffffcf6a == '\x01' && (DAT_ffffcf48 == '\0')))) goto LAB_0004d214;
    if (DAT_ffffcf64 != '\0') {
      DAT_ffffcf64 = DAT_ffffcf64 + -1;
    }
  }
  if (DAT_ffffcf65 != '\0') {
    DAT_ffffcf65 = DAT_ffffcf65 + -1;
  }
  snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
  DAT_ffffcf20 = fVar16;
  DAT_ffffcf24 = fVar16;
  DAT_ffffcf28 = fVar16;
  if ((DAT_ffffcf4d != '\x01') || (fVar12 = fVar16, fVar13 = fVar16, DAT_ffffcf4e != '\0')) {
    if (DAT_ffffcf65 != '\0') goto LAB_0004d356;
    DAT_ffffcee8 = rx8_clamp_float(cruise_speed_error_mean12_ffffcee4,-15.0,15.0);
    if (DAT_ffffcf64 == '\0') {
      if (DAT_ffffcee8 <= DAT_ffffceec) {
        DAT_ffffceec = rx8_max_float(DAT_ffffceec - 1.0,DAT_ffffcee8);
      }
      else {
        DAT_ffffceec = rx8_min_float(DAT_ffffceec + 1.0,DAT_ffffcee8);
      }
    }
    fVar13 = rx8_first_order_filter(DAT_ffffceec,DAT_ffffcef0,0.100000024,1e-05);
    fVar16 = DAT_ffffcee8;
    fVar12 = DAT_ffffceec;
  }
  DAT_ffffcef0 = fVar13;
  DAT_ffffceec = fVar12;
  DAT_ffffcee8 = fVar16;
  if (DAT_ffffcf65 == '\0') {
    DAT_ffffcf65 = '\f';
  }
LAB_0004d356:
  fVar12 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_399_check_datatype_0006bc40);
  fVar13 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_400_check_datatype_0006bc4c);
  fVar14 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_401_check_datatype_0006bc58);
  fVar16 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_402_check_datatype_0006bc64);
  fVar15 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_403_check_datatype_0006bc70);
  if ((cVar11 == '\x01') || (DAT_ffffcf59 != '\0')) {
    cruise_filtered_speed_error_ffffcef4 = DAT_ffffcef0 + fVar12;
  }
  else if ((cVar10 == '\x01') || (DAT_ffffcf56 != '\0')) {
    cruise_filtered_speed_error_ffffcef4 = DAT_ffffcef0 + fVar13;
  }
  else if ((cVar9 == '\x01') || (DAT_ffffcf53 != '\0')) {
    cruise_filtered_speed_error_ffffcef4 = DAT_ffffcef0 + fVar14;
  }
  else {
    if ((cVar8 != '\x01') && (DAT_ffffcf50 == '\0')) {
      fVar16 = fVar15;
    }
    cruise_filtered_speed_error_ffffcef4 = DAT_ffffcef0 + fVar16;
  }
  DAT_ffffcf6a = cVar7;
  DAT_ffffcf6b = cVar8;
  DAT_ffffcf6c = cVar9;
  DAT_ffffcf6d = cVar10;
  DAT_ffffcf6e = cVar11;
  DAT_ffffcf6f = cVar1;
  DAT_ffffcf68 = cVar2;
  return;
}


