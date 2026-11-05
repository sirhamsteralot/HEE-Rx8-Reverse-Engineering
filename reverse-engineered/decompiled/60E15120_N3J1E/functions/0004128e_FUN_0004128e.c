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
      if ((DAT_ffffc704 == '\x01') && (DAT_ffffae21 == '\x01')) {
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
        FUN_0005fd38(0x1c,1);
      }
      else if (DAT_ffffc702 == '\x01') {
        FUN_0005fd38(0x1c,2);
      }
    }
    puVar1 = &DAT_000415e0;
    DAT_ffffc6ec = (o2_monitor_ratio_ch0_ffffc6f0 + o2_monitor_ratio_ch1_ffffc6f4) * 0.5;
  }
  return puVar1;
}


