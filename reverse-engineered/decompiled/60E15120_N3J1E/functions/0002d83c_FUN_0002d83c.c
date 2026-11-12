/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a880: Table 2D - 340 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a88c: Table 2D - 341 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a898: Table 2D - 342 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a8a4: Table 2D - 343 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a8b0: Table 2D - 344 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a8d0: Table 3D - 112 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a8e4: Table 3D - 113 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a8f8: Table 3D - 114 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a90c: Table 3D - 115 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a920: Table 3D - 116 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * cruise_set_speed_adjust_integrator [high]: Integrates cruise set-speed adjustment 0xffffbd08 clamped [0,100]: +/- steps from 3-D tbl descriptors 0x6a8e4/0x6a8f8 (nx=2 ny=5) and 0x6a8d0/0x6a90c/0x6a920 (nx=10/9/5 ny=5; ax 0x77198-0x77410 ay 0x771c0-0x77424 data 0x771d4-0x77438 type 0; ROM bytes verified) on (0xffffbfa4/0xffffbfa0, 0xffffcf1c); band-selected 2-D ramps tbl 0x6a880-0x6a8b0 (n=31, data 0x76c50-0x77030) by 0xffffcf1c bands 2.0/3.0/4.0/5.0/6.0; gates on cruise flags 0xffffbfb0-0xffffbfba, delta 8.0 on 0xffffbd1c = 0xffffbfa0-0xffffbfa4, 0xffffbccc, 0xffffbbc8/bbc9 (0xfd/0xfe); sets accel/decel flags 0xffffbcfc/0xffffbcfd. Consumer 0x2df62: 0xffffbcf8 = clamp(0xffffbd00 + 0xffffbd08, 0, 100). Called from 0x2e5c6 (jsr via pool 0x2e790 at 0x2e63c), itself called from slow task 0x11534 (task[18] entry 0x64e8).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002d83c; body bytes: 1444; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0002db04) */
/* WARNING: Removing unreachable block (ram,0x0002db10) */

void cruise_set_speed_adjust_integrator(void)

{
  short sVar1;
  byte snapshot_can212_torque_signal_ffffbbc8;
  byte snapshot_DAT_ffffbbc9;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  float *pfVar17;
  undefined *puVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float arg2;
  float snapshot_throttle_position_1_percent_ffffa9b4;
  float snapshot_DAT_ffffbfa0;
  float snapshot_cruise_output_percent_ffffbcf8;
  undefined4 snapshot_current_gear_float_ffffcf1c;
  
  cVar11 = DAT_ffffbfba;
  cVar10 = DAT_ffffbfb9;
  cVar9 = DAT_ffffbfb8;
  cVar8 = DAT_ffffbfb6;
  cVar7 = DAT_ffffbfb5;
  cVar6 = DAT_ffffbfb2;
  cVar5 = DAT_ffffbfb1;
  cVar4 = DAT_ffffbfb0;
  fVar20 = cruise_target_speed_kmh_ffffbfa4;
  cVar15 = DAT_ffffbced;
  cVar14 = DAT_ffffbceb;
  cVar13 = DAT_ffffbbcb;
  snapshot_DAT_ffffbbc9 = DAT_ffffbbc9;
  snapshot_can212_torque_signal_ffffbbc8 = can212_torque_signal_ffffbbc8;
  DAT_ffffbd1c = DAT_ffffbfa0 - cruise_target_speed_kmh_ffffbfa4;
  fVar21 = cruise_target_speed_kmh_ffffbfa4 - DAT_ffffbfa0;
  snapshot_throttle_position_1_percent_ffffa9b4 = throttle_position_1_percent_ffffa9b4;
  snapshot_DAT_ffffbfa0 = DAT_ffffbfa0;
  snapshot_cruise_output_percent_ffffbcf8 = cruise_set_speed_ffffbcf8;
  snapshot_current_gear_float_ffffcf1c = current_gear_float_ffffcf1c;
  if ((((DAT_ffffbced == '\0') && (DAT_ffffbfb5 == '\0')) && (DAT_ffffbfba == '\0')) &&
     (DAT_ffffbfb9 == '\0')) {
    DAT_ffffbd10 = 0;
  }
  else if (DAT_ffffbd3e == '\x01') {
    if (((8.0 <= DAT_ffffbd1c) && (DAT_ffffbccc < 1.0)) ||
       ((8.0 <= fVar21 && (-1.0 <= DAT_ffffbccc)))) {
      DAT_ffffbd10 = rx8_add_u16_saturate((int)DAT_ffffbd10,1);
    }
    else if ((throttle_position_1_percent_ffffa9b4 <= cruise_set_speed_ffffbcf8) &&
            ((DAT_ffffbbcb == '\0' || ((0xfd < can212_torque_signal_ffffbbc8 && (0xfd < DAT_ffffbbc9)))))) {
      DAT_ffffbd10 = 0;
    }
  }
  DAT_ffffbd20 = rx8_decode_u16_affine(0x3f800000,0,(int)DAT_ffffbd10);
  DAT_ffffbd24 = (float)lookup_3d_descriptor_scaled(snapshot_DAT_ffffbfa0,snapshot_current_gear_float_ffffcf1c,&tbl_table_3d_112_0006a8d0);
  DAT_ffffbd28 = (float)lookup_3d_descriptor_scaled(fVar20,snapshot_current_gear_float_ffffcf1c,&tbl_table_3d_113_0006a8e4);
  DAT_ffffbd2c = (float)lookup_3d_descriptor_scaled(fVar20,snapshot_current_gear_float_ffffcf1c,&tbl_table_3d_114_0006a8f8);
  DAT_ffffbd30 = (float)lookup_3d_descriptor_scaled(snapshot_DAT_ffffbfa0,snapshot_current_gear_float_ffffcf1c,&tbl_table_3d_115_0006a90c);
  DAT_ffffbd34 = (float)lookup_3d_descriptor_scaled(DAT_ffffbd20,snapshot_current_gear_float_ffffcf1c,&tbl_table_3d_116_0006a920);
  cVar12 = rx8_is_outside_tolerance_band(snapshot_cruise_output_percent_ffffbcf8,0,0x3727c5ac);
  if ((((DAT_ffffbd44 == '\0') && (cVar4 == '\x01')) ||
      (((DAT_ffffbd45 == '\0' && (cVar5 == '\x01')) || ((DAT_ffffbd46 == '\0' && (cVar6 == '\x01')))
       ))) || ((DAT_ffffbd40 == '\x01' && ((cVar11 == '\0' && (27.5 < snapshot_DAT_ffffbfa0)))))) {
    fVar19 = rx8_max_float(snapshot_throttle_position_1_percent_ffffa9b4,DAT_ffffbd24);
    arg2 = DAT_ffffbd24 * 10000.0;
LAB_0002dc34:
    cruise_set_speed_adjust_ffffbd08 = rx8_clamp_float(fVar19,0.0,arg2);
    goto LAB_0002de7c;
  }
  if ((DAT_ffffbd47 == '\0') && (cVar7 == '\x01')) {
    fVar20 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&cruise_set_speed_kmh_ffff866c);
    if (fVar20 - snapshot_DAT_ffffbfa0 <= 0.5) {
      fVar20 = rx8_max_float(snapshot_throttle_position_1_percent_ffffa9b4,DAT_ffffbd24);
      pfVar17 = (float *)&DAT_000767c4;
    }
    else {
      DAT_ffffbd24 = DAT_ffffbd24 * 1.0;
      fVar20 = rx8_max_float(snapshot_throttle_position_1_percent_ffffa9b4,DAT_ffffbd24);
      pfVar17 = (float *)&DAT_000767c8;
    }
    cruise_set_speed_adjust_ffffbd08 = rx8_clamp_float(fVar20,0.0,*pfVar17 * DAT_ffffbd24);
    goto LAB_0002de7c;
  }
  arg2 = 100.0;
  if (((DAT_ffffbd3e == '\x01') && (cVar15 == '\x01')) &&
     ((((fVar19 = cruise_set_speed_adjust_ffffbd08, 0.0 <= fVar21 && (fVar21 < 0.0)) ||
       ((((cVar11 == '\0' && (fVar20 < snapshot_DAT_ffffbfa0)) && (cVar12 == '\0')) ||
        ((snapshot_cruise_output_percent_ffffbcf8 < snapshot_throttle_position_1_percent_ffffa9b4 || (cVar14 == '\x01')))))) ||
      ((cVar13 == '\x01' && ((snapshot_can212_torque_signal_ffffbbc8 < 0xfe || (snapshot_DAT_ffffbbc9 < 0xfe)))))))) goto LAB_0002dc34;
  if ((cVar15 == '\0') && (cVar14 == '\x01')) {
    cruise_set_speed_adjust_ffffbd08 = 0.0;
    goto LAB_0002de7c;
  }
  if ((((cVar15 != '\x01') || (snapshot_cruise_output_percent_ffffbcf8 < 0.0)) || (100.0 <= snapshot_cruise_output_percent_ffffbcf8)) ||
     (((DAT_ffffbd42 != '\0' || (cVar8 != '\x01')) || (DAT_ffffbcfc != '\0')))) {
    if (((cVar15 != '\x01') || (snapshot_cruise_output_percent_ffffbcf8 < 0.0)) ||
       ((100.0 <= snapshot_cruise_output_percent_ffffbcf8 ||
        (((DAT_ffffbd43 != '\0' || (cVar9 != '\x01')) || (DAT_ffffbcfd != '\0')))))) {
      if ((DAT_ffffbd3e != '\x01') || (cVar15 != '\x01')) {
        if (cVar15 == '\0') {
          cruise_set_speed_adjust_ffffbd08 = 0.0;
        }
        goto LAB_0002de7c;
      }
      cVar13 = rx8_is_outside_tolerance_band(snapshot_current_gear_float_ffffcf1c,0x40000000,0x3727c5ac);
      cVar14 = rx8_is_outside_tolerance_band(snapshot_current_gear_float_ffffcf1c,0x40400000,0x3727c5ac);
      cVar15 = rx8_is_outside_tolerance_band(snapshot_current_gear_float_ffffcf1c,0x40800000,0x3727c5ac);
      cVar12 = rx8_is_outside_tolerance_band(snapshot_current_gear_float_ffffcf1c,0x40a00000,0x3727c5ac);
      cVar16 = rx8_is_outside_tolerance_band(snapshot_current_gear_float_ffffcf1c,0x40c00000,0x3727c5ac);
      if (cVar13 == '\0') {
        puVar18 = &tbl_table_2d_340_check_datatype_0006a880;
LAB_0002de1e:
        DAT_ffffbd0c = (float)lookup_2d_descriptor_scaled(DAT_ffffbd1c,puVar18);
      }
      else {
        if (cVar14 == '\0') {
          puVar18 = &tbl_table_2d_341_check_datatype_0006a88c;
          goto LAB_0002de1e;
        }
        if (cVar15 == '\0') {
          puVar18 = &tbl_table_2d_342_check_datatype_0006a898;
          goto LAB_0002de1e;
        }
        if (cVar12 == '\0') {
          puVar18 = &tbl_table_2d_343_check_datatype_0006a8a4;
          goto LAB_0002de1e;
        }
        if (cVar16 == '\0') {
          puVar18 = &tbl_table_2d_344_check_datatype_0006a8b0;
        }
        else {
          puVar18 = &tbl_table_2d_340_check_datatype_0006a880;
        }
        DAT_ffffbd0c = (float)lookup_2d_descriptor_scaled(DAT_ffffbd1c,puVar18);
      }
      fVar20 = cruise_set_speed_adjust_ffffbd08;
      if ((0.0 <= snapshot_cruise_output_percent_ffffbcf8) && (snapshot_cruise_output_percent_ffffbcf8 < 100.0)) {
        fVar20 = cruise_set_speed_adjust_ffffbd08 + DAT_ffffbd0c * DAT_ffffbd30 * DAT_ffffbd34 * 0.0001;
      }
      cruise_set_speed_adjust_ffffbd08 = rx8_clamp_float(fVar20,0.0,100.0);
      goto LAB_0002de7c;
    }
    cruise_set_speed_adjust_ffffbd08 = rx8_clamp_float(cruise_set_speed_adjust_ffffbd08 + DAT_ffffbd2c,0.0,100.0);
    sVar1 = -0x4303;
  }
  else {
    cruise_set_speed_adjust_ffffbd08 = rx8_clamp_float(cruise_set_speed_adjust_ffffbd08 - DAT_ffffbd28,0.0,100.0);
    sVar1 = -0x4304;
  }
  *(undefined1 *)(int)sVar1 = 1;
LAB_0002de7c:
  if (DAT_ffffbcfc == '\x01') {
    if (0x176 < DAT_ffffbd3a) {
      DAT_ffffbcfc = '\0';
    }
    DAT_ffffbd3a = rx8_add_u16_saturate((int)(short)DAT_ffffbd3a,1);
  }
  else {
    DAT_ffffbd3a = 0;
  }
  if (DAT_ffffbcfd == '\x01') {
    if (0x176 < DAT_ffffbd3c) {
      DAT_ffffbcfd = '\0';
    }
    DAT_ffffbd3c = rx8_add_u16_saturate((int)(short)DAT_ffffbd3c,1);
  }
  else {
    DAT_ffffbd3c = 0;
  }
  DAT_ffffbd44 = cVar4;
  DAT_ffffbd45 = cVar5;
  DAT_ffffbd46 = cVar6;
  DAT_ffffbd40 = cVar11;
  DAT_ffffbd41 = cVar10;
  DAT_ffffbd47 = cVar7;
  DAT_ffffbd42 = cVar8;
  DAT_ffffbd43 = cVar9;
  return;
}


