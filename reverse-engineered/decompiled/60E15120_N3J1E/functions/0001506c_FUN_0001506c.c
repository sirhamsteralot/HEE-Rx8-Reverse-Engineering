/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006935c: Idle Target Filter Factor (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000693d4: Idle Target F (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000693e8: Idle Target G (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000693fc: Idle Target H (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069410: Idle Target - Vehicle Moving - Automatic Transmission Related 1 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * idle_target_rpm_calculate [high]: Idle target RPM calculation inside idle task body ref_updateIdleControl__ 0x167c0 (jsr via pool 0x168ac at 0x167fa; 0x167c0 called from task[10] body 0x11744). Battery-voltage filter 0xffffa7c8 (factor 0.03125, gates 13.016/12.0 V), engine-running timers 0xffffa804/a806/a808/a818/a81a, mode selects 0xffffb534/b53c/b5b3/bd69/bdb8 -> helpers 0x15818 (open-loop ramp, floor 500.0, tbl 0x69384) and 0x15934 (cranking vs running, tbl 0x693c0); target from 2-D tbl descriptors 0x69370 (Idle Target - Base), 0x693d4 (F), 0x693e8 (G), 0x693fc (H), 0x69410 (vehicle moving, AT) indexed by coolant 0xffffa990 / vehicle speed 0xffffbbb4 (descriptor bytes verified, type 8); hard floors 500.0 and 790-840 rpm; max() chain -> 0xffffa7b0; filter factor tbl 0x6935c (n=11 type 8); first-order filter -> output 0xffffa7f4; converted by 0x5ca94.
 * RAM 0xffffa7f4 idle_target_rpm (float): Filtered idle target RPM output of 0x1506c (first-order filter with factor from tbl 0x6935c); converted to output by 0x5ca94.
 * RAM 0xffffb5b3 high_load_flag (uint8): Set by 0x264f0 when filtered 0xffffb5e0 >= 40.0 (clears below 30.0); 0xffffb5a4 = first_order_filter(b5e0, b5a4, 0.035335) in 0x2633e; 0xffffb5a4/0xffffb5a0 ratio appears in the alternator domain (0x2ce18); selects an idle-target table path in 0x1506c.
 * RAM 0xffffb53c at_drive_range_engaged (uint8): Select flag in 0x1506c (MT 790 rpm floor path); producer FUN_00024b8c (=1 when 0xffffb540||0xffffb53e; pools 0x24c5a @0x24bdc / 0x24e54 @0x24e36; cleared when 0xffffb534==1); b540/b53e derive from CAN 0x231 gear byte 0xffffbaec (0xffffbae5>>4, ref_can231TxPack 0x290c6), vss 0xffffbbb4, rpm 0xffffb548.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001506c; body bytes: 1530; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000154e2) */
/* WARNING: Removing unreachable block (ram,0x000153fc) */
/* WARNING: Removing unreachable block (ram,0x00015628) */
/* WARNING: Removing unreachable block (ram,0x000155bc) */
/* WARNING: Removing unreachable block (ram,0x000156dc) */
/* WARNING: Removing unreachable block (ram,0x0001571e) */
/* WARNING: Removing unreachable block (ram,0x0001572c) */
/* WARNING: Removing unreachable block (ram,0x0001575c) */

void idle_target_rpm_calculate(void)

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
  float *pfVar10;
  undefined **ppuVar11;
  float fVar12;
  float fVar13;
  undefined4 snapshot_inferred_coolant_temperature_ffffa990;
  float arg3;
  float fVar15;
  
  cVar9 = DAT_ffffc61e;
  cVar8 = inferred_ram_bdb8_ffffbdb8_ffffbdb8;
  cVar7 = ac_clutch_on_ffffbd69;
  cVar6 = DAT_ffffbad0;
  cVar5 = high_load_flag_ffffb5b3;
  cVar4 = at_drive_range_engaged_ffffb53c;
  cVar3 = automatic_transmission_ffffb534;
  cVar1 = engine_injectors_off_ffffa42c;
  cVar2 = engine_running_ffffa428;
  arg3 = 1e-05;
  fVar13 = vehicle_speed_ffffbbb4;
  snapshot_inferred_coolant_temperature_ffffa990 = inferred_coolant_temperature_ffffa990;
  fVar15 = inferred_ram_c6ac_ffffc6ac_ffffc6ac;
  DAT_ffffa7c8 = rx8_first_order_filter(inferred_battery_voltage_ffffb590,DAT_ffffa7c8,0.03125,1e-05);
  if ((((DAT_ffffa7b7 == '\x01') && (0x493d < DAT_ffffa806)) && (13.016 <= DAT_ffffa7c8)) ||
     ((cVar2 == '\0' || (cVar1 == '\x01')))) {
    DAT_ffffa7b7 = '\0';
    DAT_ffffa808 = 0;
  }
  else if (((engine_running_timer_ffffa424 < 0x4e2) || (cVar1 != '\0')) ||
          ((DAT_ffffa804 < 0x271 || (12.0 <= DAT_ffffa7c8)))) {
    DAT_ffffa808 = 0;
  }
  else {
    if (0x270 < DAT_ffffa808) {
      DAT_ffffa7b7 = '\x01';
    }
    DAT_ffffa808 = rx8_add_u16_saturate((int)(short)DAT_ffffa808,1);
  }
  if (cVar1 == '\0') {
    DAT_ffffa804 = rx8_add_u16_saturate((int)(short)DAT_ffffa804,1);
  }
  else {
    DAT_ffffa804 = 0;
  }
  if (DAT_ffffa7b7 == '\x01') {
    DAT_ffffa806 = rx8_add_u16_saturate((int)(short)DAT_ffffa806,1);
  }
  else {
    DAT_ffffa806 = 0;
  }
  if (fVar15 <= 0.9) {
    if (fVar15 <= 0.752) {
      DAT_ffffa7f2 = 1;
    }
  }
  else {
    DAT_ffffa7f2 = 0;
  }
  if ((cVar2 == '\x01') && (DAT_ffffa82c == '\0')) {
    DAT_ffffa818 = 0x753;
    DAT_ffffa81a = 0x271;
  }
  else {
    if (DAT_ffffa818 != 0) {
      DAT_ffffa818 = DAT_ffffa818 + -1;
    }
    if (DAT_ffffa81a != 0) {
      DAT_ffffa81a = DAT_ffffa81a + -1;
    }
  }
  fVar15 = 500.0;
  if (cVar3 == '\x01') {
    FUN_00015818(snapshot_inferred_coolant_temperature_ffffa990);
    if (DAT_ffffa6b9 == '\x01') {
      pfVar10 = &DAT_ffffa7e0;
    }
    else {
      if (DAT_ffffa6b7 != '\x01') {
        fVar12 = DAT_ffffa7dc;
        if (DAT_ffffa6b8 != '\x01') {
          cVar1 = inferred_ram_b53b_ffffb53b_ffffb53b;
          if (DAT_ffffa818 != 0) goto LAB_0001537c;
          fVar12 = rx8_max_float(0.0,fVar15);
          DAT_ffffa7b8 = 0;
        }
        goto LAB_00015398;
      }
      pfVar10 = &DAT_ffffa7d8;
    }
    fVar12 = *pfVar10;
  }
  else {
    FUN_00015818(snapshot_inferred_coolant_temperature_ffffa990);
    fVar12 = DAT_ffffa7e0;
    if (((DAT_ffffa6b9 != '\x01') && (fVar12 = DAT_ffffa7d8, DAT_ffffa6b7 != '\x01')) &&
       (fVar12 = DAT_ffffa7dc, DAT_ffffa6b8 != '\x01')) {
      cVar1 = cVar4;
      if (DAT_ffffa818 == 0) {
        fVar12 = rx8_max_float(DAT_ffffa7cc - 0.32,fVar15);
        DAT_ffffa7b8 = 0;
      }
      else {
LAB_0001537c:
        FUN_00015934((int)cVar1);
        fVar12 = DAT_ffffa7cc;
      }
    }
  }
LAB_00015398:
  DAT_ffffa7cc = fVar12;
  DAT_ffffa82c = cVar2;
  if (fVar13 < 120.0) {
    if (fVar13 < 115.0) {
      DAT_ffffa82d = '\0';
    }
  }
  else {
    DAT_ffffa82d = '\x01';
  }
  if (cVar3 == '\x01') {
    fVar15 = 820.0;
    if (cVar7 == '\x01') {
      if (cVar8 == '\x01') {
        fVar15 = 840.0;
      }
      else if (cVar5 == '\x01') {
        fVar15 = 840.0;
      }
      else {
        fVar15 = 810.0;
      }
    }
    else if (cVar5 == '\x01') {
      fVar15 = 810.0;
    }
    ppuVar11 = &tbl_idle_target_base_00069370;
  }
  else {
    if (cVar4 != '\0') {
      if (DAT_ffffb53e == '\x01') {
        fVar15 = 790.0;
        if (cVar7 == '\x01') {
          if (cVar8 == '\x01') {
            fVar15 = 830.0;
          }
          else if (cVar5 == '\x01') {
            fVar15 = 800.0;
          }
          else {
            fVar15 = 800.0;
          }
        }
        else if (cVar5 == '\x01') {
          fVar15 = 790.0;
        }
        DAT_ffffa800 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,&tbl_idle_target_vehicle_moving_automatic_transmission_related_1_00069410);
      }
      else {
        fVar15 = DAT_ffffa7d4;
        if (DAT_ffffb540 == '\x01') {
          fVar15 = 810.0;
          if (cVar7 == '\x01') {
            if (cVar8 == '\x01') {
              fVar15 = 830.0;
            }
            else if (cVar5 == '\x01') {
              fVar15 = 810.0;
            }
            else {
              fVar15 = 810.0;
            }
          }
          else if (cVar5 == '\x01') {
            fVar15 = 810.0;
          }
          DAT_ffffa800 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,&tbl_idle_target_g_000693e8);
        }
      }
      goto LAB_000156a2;
    }
    fVar15 = 810.0;
    if (((DAT_ffffa82d == '\x01') && (cVar6 == '\x01')) && (cVar9 == '\0')) {
      fVar15 = (float)lookup_2d_descriptor_scaled(fVar13,&tbl_idle_target_h_000693fc);
    }
    else if (((DAT_ffffa82d == '\0') && (cVar6 == '\x01')) && (cVar9 == '\0')) {
      pfVar10 = (float *)&DAT_0006db40;
LAB_00015526:
      fVar15 = *pfVar10;
    }
    else if (cVar7 == '\x01') {
      if (cVar8 == '\x01') {
        pfVar10 = (float *)&DAT_0006db14;
        goto LAB_00015526;
      }
      if (cVar5 == '\x01') {
        fVar15 = 830.0;
      }
      else {
        fVar15 = 830.0;
      }
    }
    else if (cVar5 == '\x01') {
      fVar15 = 830.0;
    }
    ppuVar11 = &tbl_idle_target_f_000693d4;
  }
  DAT_ffffa800 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,ppuVar11);
LAB_000156a2:
  DAT_ffffa7d4 = fVar15;
  fVar13 = rx8_max_float(DAT_ffffa800,DAT_ffffa7cc);
  DAT_ffffa7b0 = rx8_max_float(fVar13,DAT_ffffa7d4);
  if ((DAT_ffffa82a == '\0') && (cVar4 == '\x01')) {
    DAT_ffffa81c = 0;
  }
  else if (DAT_ffffa81c != 0) {
    DAT_ffffa81c = DAT_ffffa81c + -1;
  }
  if (DAT_ffffa81c == 0) {
    DAT_ffffa7bc = (float)lookup_2d_descriptor_scaled(DAT_ffffa7b0 - inferred_ram_a7ac_ffffa7ac_ffffa7ac,&tbl_idle_target_filter_factor_0006935c);
  }
  else {
    DAT_ffffa7bc = 1.0;
  }
  DAT_ffffa81e = 0;
  DAT_ffffa82a = cVar4;
  if (DAT_ffffd26a == '\x01') {
    idle_target_rpm_ffffa7f4 = DAT_ffffd244;
    fVar13 = idle_target_rpm_ffffa7f4;
  }
  else {
    fVar13 = rx8_first_order_filter(DAT_ffffa7b0,inferred_ram_a7ac_ffffa7ac_ffffa7ac,DAT_ffffa7bc,arg3);
    if (DAT_ffffa7b7 != '\0') {
      fVar13 = rx8_max_float(fVar13,850.0);
    }
  }
  idle_target_rpm_ffffa7f4 = fVar13;
  inferred_ram_a7ac_ffffa7ac_ffffa7ac = (float)idle_target_encode_u16(idle_target_rpm_ffffa7f4);
  return;
}


