/* [ADDITIONAL SOURCE REVIEW]
 * o2_response_monitor_evaluate [high]: Evaluates the 0x3fb9e accumulators: thresholds from 3-D tbl descriptors 0x6b680/0x6b69c/0x6b6b8/0x6b6d4 (load,rpm; ROM bytes verified) -> 0xffffc6f8/c6fc/c798/c79c; ratio<=threshold sets pass flags 0xffffc7ea-0xffffc7e9, else fail flags 0xffffc7e6-0xffffc7e9; any-fail -> 0x5fd38(0x1c,1) pending, all-four-fail -> 0x5fd38(0x1c,2) confirmed. Fault id 0x1c -> id2slot u16 @0x7df7a = 0x1b -> code u16 @0x7e596 = 0x0133 = P0133 front HO2S slow response (data/dtc/60E15120_N3J1E.tsv slot 1b). Mode-06 test results written by 0x58262 (0xffffc6f0) and 0x5831c (0xffffc6f4) via 0x5904a. Called from 0x38f3e (jsr at 0x38f7a).
 * RAM 0xffffc6f0 o2_monitor_ratio_ch0 (float): Accumulated amplitude ratio channel 0 (0xffffc758/0xffffc728) from 0x3fb9e; compared vs threshold 0xffffc6f8 in 0x4128e; mode-06 result via 0x58262 (encode step 0.0039062).
 * RAM 0xffffc780 o2_monitor_ratio_ch2 (float): Ratio channel 2 (0xffffc770/0xffffc740); compared vs 0xffffc798.
 * RAM 0xffffc784 o2_monitor_ratio_ch3 (float): Ratio channel 3 (0xffffc77c/0xffffc74c); compared vs 0xffffc79c.
 * RAM 0xffffc701 o2_monitor_fluctuation_detected (uint8): Set by 0x3fb9e when the counter window completes (0xffffc904==0); gates the ratio evaluation in 0x4128e.
 * RAM 0xffffc704 o2_monitor_accum_gate (uint8): Delta-accumulation gate set in o2_response_monitor_accumulate 0x3fb9e (every 2nd run, c908, when 0xffffc700==1 && 0xffffc7b0==0 && 0xffffc7b8 != 0x32; cleared when 0xffffd1c5 set; pool read at 0x413ae in 0x4128e). With 0xffffae21 it gates the threshold running averages 0xffffc6f8/c6fc/c798/c79c (asm 0x413ae-0x413c2).
 * RAM 0xffffae21 o2_monitor_enable (uint8): O2-monitor enable computed by FUN_0001d1ca: 1 when 0xffffc700==1 OR (closed_loop_active 0xffffae1f AND coolant 0xffffa98c >= 150.0 AND 0xffffad24==1 AND 0xffffae20==0); also gates the half-period timers 0xffffae1a/0xffffae1c (0x1d2e2). Read at 0x413ba in 0x4128e (pool 0x41480).
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b680: Table 3D - 87 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b69c: Table 3D - 88 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b6b8: Table 3D - 89 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b6d4: Table 3D - 90 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004128e; body bytes: 610; decompiled */

undefined4 * o2_response_monitor_evaluate(void)

{
  undefined4 *puVar1;
  float fVar2;
  undefined4 snapshot_engine_load_ffffc0b4;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  undefined4 uVar5;
  
  puVar1 = (undefined4 *)(uint)DAT_ffffc908;
  if (puVar1 == (undefined4 *)0x1) {
    uVar5 = 0;
    if (DAT_ffffd1c5 == '\x01') {
      DAT_ffffc7ea = '\0';
      DAT_ffffc7e6 = '\0';
      DAT_ffffc7eb = '\0';
      DAT_ffffc7e7 = '\0';
      DAT_ffffc7ec = '\0';
      DAT_ffffc7e8 = '\0';
      DAT_ffffc7ed = '\0';
      DAT_ffffc7e9 = '\0';
      DAT_ffffc702 = '\0';
      DAT_ffffc703 = '\0';
      DAT_ffffc7da = 0;
      DAT_ffffc7a0 = 0.0;
      DAT_ffffc7a4 = 0.0;
      DAT_ffffc7a8 = 0.0;
      DAT_ffffc7ac = 0.0;
      DAT_ffffc6f8 = 0.0;
      DAT_ffffc6fc = 0.0;
      DAT_ffffc798 = 0.0;
      DAT_ffffc79c = 0.0;
    }
    else {
      snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
      snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
      DAT_ffffc788 = (float)lookup_3d_descriptor_scaled(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&tbl_table_3d_87_0006b680);
      DAT_ffffc78c = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&tbl_table_3d_88_0006b69c);
      DAT_ffffc790 = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&tbl_table_3d_89_0006b6b8);
      DAT_ffffc794 = (float)lookup_3d_descriptor_scaled(snapshot_engine_load_ffffc0b4,snapshot_engine_speed_rpm_ffffb548,&tbl_table_3d_90_0006b6d4);
      if ((o2_monitor_accum_gate_ffffc704 == '\x01') && (o2_monitor_enable_ffffae21 == '\x01')) {
        DAT_ffffc7da = rx8_add_u16_saturate((int)DAT_ffffc7da,1);
        fVar2 = (float)rx8_decode_u16_affine(0x3f800000,uVar5,(int)DAT_ffffc7da);
        DAT_ffffc7a0 = DAT_ffffc788 + DAT_ffffc7a0;
        DAT_ffffc7a4 = DAT_ffffc78c + DAT_ffffc7a4;
        DAT_ffffc7a8 = DAT_ffffc790 + DAT_ffffc7a8;
        DAT_ffffc7ac = DAT_ffffc794 + DAT_ffffc7ac;
        DAT_ffffc6f8 = DAT_ffffc7a0 / fVar2;
        DAT_ffffc6fc = DAT_ffffc7a4 / fVar2;
        DAT_ffffc798 = DAT_ffffc7a8 / fVar2;
        DAT_ffffc79c = DAT_ffffc7ac / fVar2;
      }
      if (o2_monitor_fluctuation_detected_ffffc701 == '\x01') {
        if (o2_monitor_ratio_ch0_ffffc6f0 <= DAT_ffffc6f8) {
          DAT_ffffc7ea = '\x01';
        }
        else {
          DAT_ffffc7e6 = '\x01';
        }
        if (o2_monitor_ratio_ch1_ffffc6f4 <= DAT_ffffc6fc) {
          DAT_ffffc7eb = '\x01';
        }
        else {
          DAT_ffffc7e7 = '\x01';
        }
        if (o2_monitor_ratio_ch2_ffffc780 <= DAT_ffffc798) {
          DAT_ffffc7ec = '\x01';
        }
        else {
          DAT_ffffc7e8 = '\x01';
        }
        if (o2_monitor_ratio_ch3_ffffc784 <= DAT_ffffc79c) {
          DAT_ffffc7ed = '\x01';
        }
        else {
          DAT_ffffc7e9 = '\x01';
        }
      }
      if ((((DAT_ffffc7e6 == '\x01') && (DAT_ffffc7e7 == '\x01')) && (DAT_ffffc7e8 == '\x01')) &&
         (DAT_ffffc7e9 == '\x01')) {
        DAT_ffffc702 = '\x01';
      }
      if (((DAT_ffffc7ea == '\x01') || (DAT_ffffc7eb == '\x01')) ||
         ((DAT_ffffc7ec == '\x01' || (DAT_ffffc7ed == '\x01')))) {
        DAT_ffffc703 = '\x01';
      }
      if (DAT_ffffc703 == '\x01') {
        dtc_set_fault_x0(0x1c,1);
      }
      else if (DAT_ffffc702 == '\x01') {
        dtc_set_fault_x0(0x1c,2);
      }
    }
    puVar1 = &DAT_000415e0;
    DAT_ffffc6ec = (o2_monitor_ratio_ch0_ffffc6f0 + o2_monitor_ratio_ch1_ffffc6f4) * 0.5;
  }
  return puVar1;
}


