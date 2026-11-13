/* [ADDITIONAL SOURCE REVIEW]
 * dsc_timing_derate_select [high]: DSC torque-request derate on leading timing: if DSC mode bc83==4 -> a91c = bc94 (DSC Mode A base, tbl 0x6a7a4; Map4 tbl 0x6957c also referenced); if bc90 in band -> -20.0; else blends by a930/a92c. Leading rotor only (no trailing reader found).
 * RAM 0xffffa91c dsc_timing_derate_leading (float): mov.w pool 0x18284 (sign-extends to 0xffffa91c) in 0x1815c dsc_timing_derate_select; DSC leading-timing derate value selected in 0x1815c.
 * RAM 0xffffbbd8 engine_max_torque_allowed (float): Max engine torque allowed for DSC, computed by 0x2b3b8 (clamp(..., 0, 512)); consumed by dsc_timing_derate_select 0x1815c (pool 0x1827c at 0x18188) and 0x17f20.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006957c: Igntion Leading Timing - DSC Mode A - Map 4 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001815c; body bytes: 390; decompiled */

undefined4 dsc_timing_derate_select(void)

{
  char cVar1;
  float snapshot_DAT_ffffbc98;
  float snapshot_DAT_ffffbca8;
  char cVar5;
  undefined4 extraout_r0;
  undefined4 uVar4;
  undefined *puVar6;
  int iVar7;
  float fVar8;
  float snapshot_DAT_ffffbc90;
  float fVar10;
  float fVar11;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_DAT_ffffbca8 = DAT_ffffbca8;
  snapshot_DAT_ffffbc98 = DAT_ffffbc98;
  fVar11 = dsc_mode_a_base_timing_ffffbc94;
  cVar1 = DAT_ffffbc83;
  fVar8 = engine_max_torque_allowed_ffffbbd8;
  iVar7 = (int)DAT_ffffbc83;
  snapshot_DAT_ffffbc90 = DAT_ffffbc90;
  fVar10 = DAT_ffffbac4;
  uVar4 = engine_load_ffffc0b4;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  cVar5 = rx8_is_outside_tolerance_band(DAT_ffffbc90,0,0x3727c5ac);
  if (cVar1 == '\x04') {
    dsc_timing_derate_leading_ffffa91c = fVar11;
  }
  else if (cVar5 == '\0') {
    dsc_timing_derate_leading_ffffa91c = -20.0;
  }
  else {
    if (DAT_ffffa930 <= DAT_ffffa92c) {
      fVar10 = fVar8;
    }
    fVar10 = ((snapshot_DAT_ffffbca8 - DAT_ffffbc78) - DAT_ffffbcb4) - fVar10;
    fVar8 = (float)rx8_decode_u8_affine(0x3f800000,0,iVar7);
    fVar8 = rx8_max_float((DAT_ffffbcb8 + DAT_ffffbcbc + snapshot_DAT_ffffbc98 + fVar10 * (4.0 / (-fVar8 + 4.0))) -
                          snapshot_DAT_ffffbca8,0.0);
    fVar8 = (float)ref_checkFloatValidity_(fVar8 / snapshot_DAT_ffffbc90);
    dsc_timing_derate_leading_ffffa91c = fVar11 - fVar8;
  }
  if (cVar1 == '\x01') {
    puVar6 = &DAT_00069598;
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 == '\x03') {
        puVar6 = &DAT_000695d0;
      }
      else {
        puVar6 = &tbl_igntion_leading_timing_dsc_mode_a_map_4_0006957c;
      }
      DAT_ffffa928 = (float)lookup_3d_descriptor_scaled(uVar4,snapshot_engine_speed_rpm_ffffb548,puVar6);
      goto LAB_000182d8;
    }
    puVar6 = &DAT_000695b4;
  }
  DAT_ffffa928 = (float)lookup_3d_descriptor_scaled(uVar4,snapshot_engine_speed_rpm_ffffb548,puVar6);
LAB_000182d8:
  fVar8 = (float)lookup_3d_descriptor_scaled(uVar4,snapshot_engine_speed_rpm_ffffb548,&DAT_000695ec);
  fVar11 = dsc_timing_derate_leading_ffffa91c + fVar8;
  fVar8 = DAT_ffffa928 + fVar8;
  DAT_ffffa924 = rx8_max_float(dsc_timing_derate_leading_ffffa91c,DAT_ffffa928);
  DAT_ffffa920 = rx8_max_float(fVar11,fVar8);
  uVar4 = extraout_r0;
  if (DAT_ffffa928 < dsc_timing_derate_leading_ffffa91c) {
    uVar4 = 0;
  }
  DAT_ffffa93c = DAT_ffffa928 >= dsc_timing_derate_leading_ffffa91c;
  return uVar4;
}


