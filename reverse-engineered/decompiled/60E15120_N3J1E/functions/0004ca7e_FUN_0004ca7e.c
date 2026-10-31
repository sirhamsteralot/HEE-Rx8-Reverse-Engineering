/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006bc40: Table 2D - 399 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc4c: Table 2D - 400 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc58: Table 2D - 401 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc64: Table 2D - 402 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bc70: Table 2D - 403 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004ca7e; body bytes: 2200; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0004d2f0) */

void FUN_0004ca7e(void)

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
  fVar12 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff866c);
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
  if ((DAT_ffffcf4f == '\x01') || (DAT_ffffcf34 == '\0')) {
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
    DAT_ffffcee8 = rx8_clamp_float(DAT_ffffcee4,-15.0,15.0);
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
    DAT_ffffcef4 = DAT_ffffcef0 + fVar12;
  }
  else if ((cVar10 == '\x01') || (DAT_ffffcf56 != '\0')) {
    DAT_ffffcef4 = DAT_ffffcef0 + fVar13;
  }
  else if ((cVar9 == '\x01') || (DAT_ffffcf53 != '\0')) {
    DAT_ffffcef4 = DAT_ffffcef0 + fVar14;
  }
  else {
    if ((cVar8 != '\x01') && (DAT_ffffcf50 == '\0')) {
      fVar16 = fVar15;
    }
    DAT_ffffcef4 = DAT_ffffcef0 + fVar16;
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


