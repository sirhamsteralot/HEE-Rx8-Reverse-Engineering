/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b66c: Table 3D - 123 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * o2_response_monitor_accumulate [high]: 4-channel filtered-lambda/AFR delta accumulator: snapshots 0xffffc708/0c/10/14, shifts 10-entry rings 0xffffc7f4 (float) and 0xffffc870 (u16), reloads per-channel counters 0xffffc7ba-0xffffc7d8 from 3-D tbl descriptor 0x6b66c (nx=9 ny=9 ax=0x7ad48 ay=0x7ad6c data=0x7ad90 type=0, ROM bytes verified) on (engine_load 0xffffc0b4, engine_speed_rpm 0xffffb548); accumulates max/min deltas 0xffffc724-0xffffc77c, sign/deviation bits 0xffffc7de-0xffffc7e5, tolerance band float 1e-5 (0x3727c5ac) via mova pool 0x41220 (refs 0x41140/0x41156/0x4116a/0x4117e). Outputs ratios 0xffffc6f0/c6f4/c780/c784 and flag 0xffffc701, consumed by 0x4128e. Called from slow-task batch 0x38f3e (jsr at 0x38f74; pool word 0x390b0 = 0x3fb9e). Channel inputs filtered by 0x3f924 (called from 0x38dca).
 * RAM 0xffffc710 o2_channel_lambda_slow (float): First-order filtered actual lambda 0xffffadec, factor 0.1; one of the four channels delta-accumulated in 0x3fb9e.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003fb9e; body bytes: 4884; decompiled */

void o2_response_monitor_accumulate(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  float snapshot_o2_channel_afr_fast_ffffc708;
  float snapshot_o2_channel_afr_medium_ffffc70c;
  float snapshot_o2_channel_lambda_slow_ffffc710;
  float snapshot_o2_channel_lambda_very_slow_ffffc714;
  short sVar11;
  ushort uVar12;
  ushort uVar13;
  ushort uVar14;
  ushort uVar15;
  ushort uVar16;
  ushort uVar17;
  ushort uVar18;
  ushort uVar19;
  ushort uVar20;
  ushort uVar21;
  ushort uVar22;
  ushort uVar23;
  ushort uVar24;
  ushort uVar25;
  ushort uVar26;
  ushort uVar27;
  char cVar28;
  char cVar29;
  char cVar30;
  char cVar31;
  char cVar32;
  char cVar33;
  char cVar34;
  char cVar35;
  char cVar36;
  float fVar37;
  char cStack_59;
  char cStack_58;
  char cStack_53;
  char cStack_52;
  char cStack_51;
  char cStack_50;
  ushort uStack_40;
  
  cVar34 = DAT_ffffd1c5;
  sVar11 = DAT_ffffc7b0;
  snapshot_o2_channel_lambda_very_slow_ffffc714 = o2_channel_lambda_very_slow_ffffc714;
  snapshot_o2_channel_lambda_slow_ffffc710 = o2_channel_lambda_slow_ffffc710;
  snapshot_o2_channel_afr_medium_ffffc70c = o2_channel_afr_medium_ffffc70c;
  snapshot_o2_channel_afr_fast_ffffc708 = o2_channel_afr_fast_ffffc708;
  cVar6 = DAT_ffffc700;
  cVar33 = o2_monitor_enable_ffffae21;
  cStack_50 = DAT_ffffc7e2;
  cStack_51 = DAT_ffffc7e3;
  cStack_52 = DAT_ffffc7e4;
  cStack_53 = DAT_ffffc7e5;
  bVar5 = false;
  DAT_ffffc8fc = rx8_add_u16_saturate((int)(short)DAT_ffffc8fc,1);
  if (DAT_ffffc8fc < 2) {
    DAT_ffffc908 = '\0';
  }
  else {
    DAT_ffffc8fc = 0;
    DAT_ffffc908 = '\x01';
    DAT_ffffc7b2 = rx8_lookup_3d_raw_u16(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&tbl_table_3d_123_0006b66c);
  }
  if (cVar34 == '\x01') {
    DAT_ffffc7b6 = 0;
    DAT_ffffc7b4 = 0xffff;
    DAT_ffffc7b8 = 0;
    DAT_ffffc724 = 0.0;
    DAT_ffffc728 = 0.0;
    DAT_ffffc730 = 0.0;
    DAT_ffffc734 = 0.0;
    DAT_ffffc73c = 0.0;
    DAT_ffffc740 = 0.0;
    DAT_ffffc748 = 0.0;
    DAT_ffffc74c = 0.0;
    DAT_ffffc754 = 0.0;
    DAT_ffffc758 = 0.0;
    DAT_ffffc760 = 0.0;
    DAT_ffffc764 = 0.0;
    DAT_ffffc76c = 0.0;
    DAT_ffffc770 = 0.0;
    DAT_ffffc778 = 0.0;
    DAT_ffffc77c = 0.0;
    DAT_ffffc7dd = '\0';
    o2_monitor_accum_gate_ffffc704 = '\0';
    o2_monitor_fluctuation_detected_ffffc701 = 0;
    o2_monitor_ratio_ch0_ffffc6f0 = 0.0;
    o2_monitor_ratio_ch1_ffffc6f4 = 0.0;
    o2_monitor_ratio_ch2_ffffc780 = 0.0;
    o2_monitor_ratio_ch3_ffffc784 = 0.0;
    DAT_ffffc7ee = '\0';
    DAT_ffffc7ef = '\0';
    DAT_ffffc7f0 = '\0';
    DAT_ffffc7f1 = '\0';
    DAT_ffffc904 = 0;
    DAT_ffffc90a = '\0';
    DAT_ffffc907 = '\0';
    DAT_ffffc906 = '\0';
  }
  else {
    cStack_58 = o2_monitor_accum_gate_ffffc704;
    if (DAT_ffffc908 == '\x01') {
      if (((cVar6 == '\x01') && (sVar11 == 0)) && (DAT_ffffc7b8 != 0x32)) {
        o2_monitor_accum_gate_ffffc704 = '\x01';
        o2_monitor_fluctuation_detected_ffffc701 = 0;
      }
      else {
        o2_monitor_accum_gate_ffffc704 = '\0';
      }
      if ((((o2_monitor_accum_gate_ffffc704 == '\x01') && (cVar33 == '\x01')) &&
          ((DAT_ffffc906 == '\x01' || (DAT_ffffc907 == '\x01')))) && (DAT_ffffc7b8 < 0x32)) {
        DAT_ffffc7b8 = rx8_add_u16_saturate((int)(short)DAT_ffffc7b8,1);
      }
      DAT_ffffc907 = '\0';
      DAT_ffffc906 = '\0';
    }
    if (((DAT_ffffc909 == '\x01') && (cVar6 == '\0')) && (DAT_ffffc7b4 != 0xffff)) {
      DAT_ffffc7b6 = DAT_ffffc7b2;
    }
    else if (DAT_ffffc7b6 != 0) {
      DAT_ffffc7b6 = DAT_ffffc7b6 - 1;
    }
    if (((cVar6 == '\x01') && (sVar11 == 0)) && (DAT_ffffc7b8 != 0x32)) {
      if (DAT_ffffc8fe == 1) {
        DAT_ffffc7b4 = DAT_ffffc7b2;
      }
      else if (DAT_ffffc7b4 != 0) {
        DAT_ffffc7b4 = DAT_ffffc7b4 - 1;
      }
    }
    else if ((DAT_ffffc7b4 == 0xffff) || (DAT_ffffc7b4 == 0)) {
      DAT_ffffc7b4 = 0xffff;
    }
    else {
      DAT_ffffc7b4 = DAT_ffffc7b4 - 1;
    }
    cStack_59 = DAT_ffffc7dd;
    if ((DAT_ffffc7b4 == 0) || (DAT_ffffc7b6 != 0)) {
      DAT_ffffc7dd = '\x01';
    }
    else {
      DAT_ffffc7dd = '\0';
    }
  }
  if (DAT_ffffc908 == '\x01') {
    for (uStack_40 = 10; uStack_40 != 0; uStack_40 = uStack_40 - 1) {
      (&DAT_ffffc7f4)[uStack_40] = (&DAT_ffffc7f4)[(ushort)(uStack_40 - 1)];
    }
    DAT_ffffc7f4 = snapshot_o2_channel_lambda_slow_ffffc710;
    for (uStack_40 = 10; cVar32 = DAT_ffffc7e5, cVar31 = DAT_ffffc7e4, cVar30 = DAT_ffffc7e3,
        cVar29 = DAT_ffffc7e2, cVar28 = DAT_ffffc7e1, cVar36 = DAT_ffffc7e0, cVar35 = DAT_ffffc7df,
        cVar33 = DAT_ffffc7de, uVar27 = DAT_ffffc7d8, uVar26 = DAT_ffffc7d6, uVar25 = DAT_ffffc7d4,
        uVar24 = DAT_ffffc7d2, uVar23 = DAT_ffffc7d0, uVar22 = DAT_ffffc7ce, uVar21 = DAT_ffffc7cc,
        uVar20 = DAT_ffffc7ca, uVar19 = DAT_ffffc7c8, uVar18 = DAT_ffffc7c6, uVar17 = DAT_ffffc7c4,
        uVar16 = DAT_ffffc7c2, uVar15 = DAT_ffffc7c0, uVar14 = DAT_ffffc7be, uVar13 = DAT_ffffc7bc,
        uVar12 = DAT_ffffc7ba, uStack_40 != 0; uStack_40 = uStack_40 - 1) {
      (&DAT_ffffc870)[uStack_40] = (&DAT_ffffc870)[(ushort)(uStack_40 - 1)];
    }
    DAT_ffffc870 = snapshot_o2_channel_lambda_very_slow_ffffc714;
    DAT_ffffc718 = snapshot_o2_channel_lambda_slow_ffffc710 - DAT_ffffc81c;
    DAT_ffffc71c = snapshot_o2_channel_lambda_very_slow_ffffc714 - DAT_ffffc898;
    if (DAT_ffffc718 < 0.0) {
      if (0.0 <= DAT_ffffc718) {
        DAT_ffffc7de = '\0';
        DAT_ffffc7df = '\0';
      }
      else {
        DAT_ffffc7df = '\x01';
        DAT_ffffc7de = '\0';
      }
    }
    else {
      DAT_ffffc7de = '\x01';
      DAT_ffffc7df = '\0';
    }
    if (DAT_ffffc71c < 0.0) {
      if (0.0 <= DAT_ffffc71c) {
        DAT_ffffc7e0 = '\0';
        DAT_ffffc7e1 = '\0';
      }
      else {
        DAT_ffffc7e1 = '\x01';
        DAT_ffffc7e0 = '\0';
      }
    }
    else {
      DAT_ffffc7e0 = '\x01';
      DAT_ffffc7e1 = '\0';
    }
    if ((cVar33 == '\x01') && (DAT_ffffc7de == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((cVar35 == '\x01') && (DAT_ffffc7df == '\0')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((cVar36 == '\x01') && (DAT_ffffc7e0 == '\0')) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if ((cVar28 == '\x01') && (DAT_ffffc7e1 == '\0')) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if (DAT_ffffc7ba < 2) {
      DAT_ffffc7ba = 0;
    }
    else {
      DAT_ffffc7ba = DAT_ffffc7ba - 2;
    }
    if (DAT_ffffc7bc < 2) {
      DAT_ffffc7bc = 0;
    }
    else {
      DAT_ffffc7bc = DAT_ffffc7bc - 2;
    }
    if (DAT_ffffc7be < 2) {
      DAT_ffffc7be = 0;
    }
    else {
      DAT_ffffc7be = DAT_ffffc7be - 2;
    }
    if (DAT_ffffc7c0 < 2) {
      DAT_ffffc7c0 = 0;
    }
    else {
      DAT_ffffc7c0 = DAT_ffffc7c0 - 2;
    }
    if ((uVar12 != 0) && (DAT_ffffc7ba == 0)) {
      cStack_50 = '\x01';
    }
    if ((uVar13 != 0) && (DAT_ffffc7bc == 0)) {
      cStack_50 = '\x01';
    }
    if ((uVar14 != 0) && (DAT_ffffc7be == 0)) {
      cStack_50 = '\0';
      if (DAT_ffffc7ba != 0) {
        DAT_ffffc7de = '\0';
        DAT_ffffc7ba = 0;
        DAT_ffffc7ee = '\x01';
      }
      if ((uVar13 != 0) && (DAT_ffffc7bc == 0)) {
        cStack_50 = DAT_ffffc7de;
      }
    }
    if ((uVar15 != 0) && (DAT_ffffc7c0 == 0)) {
      cStack_50 = '\0';
      if (DAT_ffffc7bc != 0) {
        DAT_ffffc7de = '\0';
        DAT_ffffc7bc = 0;
        DAT_ffffc7ee = '\x01';
      }
      if ((uVar12 != 0) && (DAT_ffffc7ba == 0)) {
        cStack_50 = DAT_ffffc7de;
      }
    }
    DAT_ffffc7e2 = cStack_50;
    if ((cVar33 == '\0') && (DAT_ffffc7de == '\x01')) {
      if (DAT_ffffc90b == '\0') {
        if ((DAT_ffffc7be == 0) && (DAT_ffffc7ba == 0)) {
          DAT_ffffc7ba = DAT_ffffc7b2;
          DAT_ffffc90b = '\x01';
        }
      }
      else if ((DAT_ffffc7c0 == 0) && (DAT_ffffc7bc == 0)) {
        DAT_ffffc7bc = DAT_ffffc7b2;
        DAT_ffffc90b = '\0';
      }
    }
    if (bVar1) {
      if (DAT_ffffc90b == '\x01') {
        if (DAT_ffffc7be == 0) {
          DAT_ffffc7be = DAT_ffffc7b2;
        }
      }
      else if (DAT_ffffc7c0 == 0) {
        DAT_ffffc7c0 = DAT_ffffc7b2;
      }
    }
    if (DAT_ffffc7c2 < 2) {
      DAT_ffffc7c2 = 0;
    }
    else {
      DAT_ffffc7c2 = DAT_ffffc7c2 - 2;
    }
    if (DAT_ffffc7c4 < 2) {
      DAT_ffffc7c4 = 0;
    }
    else {
      DAT_ffffc7c4 = DAT_ffffc7c4 - 2;
    }
    if (DAT_ffffc7c6 < 2) {
      DAT_ffffc7c6 = 0;
    }
    else {
      DAT_ffffc7c6 = DAT_ffffc7c6 - 2;
    }
    if (DAT_ffffc7c8 < 2) {
      DAT_ffffc7c8 = 0;
    }
    else {
      DAT_ffffc7c8 = DAT_ffffc7c8 - 2;
    }
    if ((uVar16 != 0) && (DAT_ffffc7c2 == 0)) {
      cStack_51 = '\x01';
    }
    if ((uVar17 != 0) && (DAT_ffffc7c4 == 0)) {
      cStack_51 = '\x01';
    }
    if ((uVar18 != 0) && (DAT_ffffc7c6 == 0)) {
      cStack_51 = '\0';
      if (DAT_ffffc7c2 != 0) {
        DAT_ffffc7df = '\0';
        DAT_ffffc7c2 = 0;
        DAT_ffffc7ef = '\x01';
      }
      if ((uVar17 != 0) && (DAT_ffffc7c4 == 0)) {
        cStack_51 = DAT_ffffc7df;
      }
    }
    if ((uVar19 != 0) && (DAT_ffffc7c8 == 0)) {
      cStack_51 = '\0';
      if (DAT_ffffc7c4 != 0) {
        DAT_ffffc7df = '\0';
        DAT_ffffc7c4 = 0;
        DAT_ffffc7ef = '\x01';
      }
      if ((uVar16 != 0) && (DAT_ffffc7c2 == 0)) {
        cStack_51 = DAT_ffffc7df;
      }
    }
    DAT_ffffc7e3 = cStack_51;
    if ((cVar35 == '\0') && (DAT_ffffc7df == '\x01')) {
      if (DAT_ffffc90c == '\0') {
        if ((DAT_ffffc7c6 == 0) && (DAT_ffffc7c2 == 0)) {
          DAT_ffffc7c2 = DAT_ffffc7b2;
          DAT_ffffc90c = '\x01';
        }
      }
      else if ((DAT_ffffc7c8 == 0) && (DAT_ffffc7c4 == 0)) {
        DAT_ffffc7c4 = DAT_ffffc7b2;
        DAT_ffffc90c = '\0';
      }
    }
    if (bVar2) {
      if (DAT_ffffc90c == '\x01') {
        if (DAT_ffffc7c6 == 0) {
          DAT_ffffc7c6 = DAT_ffffc7b2;
        }
      }
      else if (DAT_ffffc7c8 == 0) {
        DAT_ffffc7c8 = DAT_ffffc7b2;
      }
    }
    if (DAT_ffffc7ca < 2) {
      DAT_ffffc7ca = 0;
    }
    else {
      DAT_ffffc7ca = DAT_ffffc7ca - 2;
    }
    if (DAT_ffffc7cc < 2) {
      DAT_ffffc7cc = 0;
    }
    else {
      DAT_ffffc7cc = DAT_ffffc7cc - 2;
    }
    if (DAT_ffffc7ce < 2) {
      DAT_ffffc7ce = 0;
    }
    else {
      DAT_ffffc7ce = DAT_ffffc7ce - 2;
    }
    if (DAT_ffffc7d0 < 2) {
      DAT_ffffc7d0 = 0;
    }
    else {
      DAT_ffffc7d0 = DAT_ffffc7d0 - 2;
    }
    if ((uVar20 != 0) && (DAT_ffffc7ca == 0)) {
      cStack_52 = '\x01';
    }
    if ((uVar21 != 0) && (DAT_ffffc7cc == 0)) {
      cStack_52 = '\x01';
    }
    if ((uVar22 != 0) && (DAT_ffffc7ce == 0)) {
      cStack_52 = '\0';
      if (DAT_ffffc7ca != 0) {
        DAT_ffffc7e0 = '\0';
        DAT_ffffc7ca = 0;
        DAT_ffffc7f0 = '\x01';
      }
      if ((uVar21 != 0) && (DAT_ffffc7cc == 0)) {
        cStack_52 = DAT_ffffc7e0;
      }
    }
    if ((uVar23 != 0) && (DAT_ffffc7d0 == 0)) {
      cStack_52 = '\0';
      if (DAT_ffffc7cc != 0) {
        DAT_ffffc7e0 = '\0';
        DAT_ffffc7cc = 0;
        DAT_ffffc7f0 = '\x01';
      }
      if ((uVar20 != 0) && (DAT_ffffc7ca == 0)) {
        cStack_52 = DAT_ffffc7e0;
      }
    }
    DAT_ffffc7e4 = cStack_52;
    if ((cVar36 == '\0') && (DAT_ffffc7e0 == '\x01')) {
      if (DAT_ffffc90d == '\0') {
        if ((DAT_ffffc7ce == 0) && (DAT_ffffc7ca == 0)) {
          DAT_ffffc7ca = DAT_ffffc7b2;
          DAT_ffffc90d = '\x01';
        }
      }
      else if ((DAT_ffffc7d0 == 0) && (DAT_ffffc7cc == 0)) {
        DAT_ffffc7cc = DAT_ffffc7b2;
        DAT_ffffc90d = '\0';
      }
    }
    if (bVar3) {
      if (DAT_ffffc90d == '\x01') {
        if (DAT_ffffc7ce == 0) {
          DAT_ffffc7ce = DAT_ffffc7b2;
        }
      }
      else if (DAT_ffffc7d0 == 0) {
        DAT_ffffc7d0 = DAT_ffffc7b2;
      }
    }
    if (DAT_ffffc7d2 < 2) {
      DAT_ffffc7d2 = 0;
    }
    else {
      DAT_ffffc7d2 = DAT_ffffc7d2 - 2;
    }
    if (DAT_ffffc7d4 < 2) {
      DAT_ffffc7d4 = 0;
    }
    else {
      DAT_ffffc7d4 = DAT_ffffc7d4 - 2;
    }
    if (DAT_ffffc7d6 < 2) {
      DAT_ffffc7d6 = 0;
    }
    else {
      DAT_ffffc7d6 = DAT_ffffc7d6 - 2;
    }
    if (DAT_ffffc7d8 < 2) {
      DAT_ffffc7d8 = 0;
    }
    else {
      DAT_ffffc7d8 = DAT_ffffc7d8 - 2;
    }
    if ((uVar24 != 0) && (DAT_ffffc7d2 == 0)) {
      cStack_53 = '\x01';
    }
    if ((uVar25 != 0) && (DAT_ffffc7d4 == 0)) {
      cStack_53 = '\x01';
    }
    if ((uVar26 != 0) && (DAT_ffffc7d6 == 0)) {
      cStack_53 = '\0';
      if (DAT_ffffc7d2 != 0) {
        DAT_ffffc7e1 = '\0';
        DAT_ffffc7d2 = 0;
        DAT_ffffc7f1 = '\x01';
      }
      if ((uVar25 != 0) && (DAT_ffffc7d4 == 0)) {
        cStack_53 = DAT_ffffc7e1;
      }
    }
    if ((uVar27 != 0) && (DAT_ffffc7d8 == 0)) {
      cStack_53 = '\0';
      if (DAT_ffffc7d4 != 0) {
        DAT_ffffc7e1 = '\0';
        DAT_ffffc7d4 = 0;
        DAT_ffffc7f1 = '\x01';
      }
      if ((uVar24 != 0) && (DAT_ffffc7d2 == 0)) {
        cStack_53 = DAT_ffffc7e1;
      }
    }
    DAT_ffffc7e5 = cStack_53;
    if ((cVar28 == '\0') && (DAT_ffffc7e1 == '\x01')) {
      if (DAT_ffffc90e == '\0') {
        if ((DAT_ffffc7d6 == 0) && (DAT_ffffc7d2 == 0)) {
          DAT_ffffc7d2 = DAT_ffffc7b2;
          DAT_ffffc90e = '\x01';
        }
      }
      else if ((DAT_ffffc7d8 == 0) && (DAT_ffffc7d4 == 0)) {
        DAT_ffffc7d4 = DAT_ffffc7b2;
        DAT_ffffc90e = '\0';
      }
    }
    if (bVar4) {
      if (DAT_ffffc90e == '\x01') {
        if (DAT_ffffc7d6 == 0) {
          DAT_ffffc7d6 = DAT_ffffc7b2;
        }
      }
      else if (DAT_ffffc7d8 == 0) {
        DAT_ffffc7d8 = DAT_ffffc7b2;
      }
    }
    if (cVar34 == '\0') {
      if (DAT_ffffc7ee == '\x01') {
        DAT_ffffc724 = 0.0;
        DAT_ffffc754 = 0.0;
        DAT_ffffc7ee = '\0';
      }
      else {
        if ((o2_monitor_accum_gate_ffffc704 == '\x01') && (DAT_ffffc7de == '\x01')) {
          DAT_ffffc720 = snapshot_o2_channel_lambda_slow_ffffc710 - DAT_ffffc8f4;
          fVar37 = rx8_max_float(0.0,DAT_ffffc720);
          DAT_ffffc724 = DAT_ffffc724 + fVar37;
        }
        else if (((cVar33 == '\x01') && (DAT_ffffc7de == '\0')) ||
                ((cStack_58 == '\x01' && (o2_monitor_accum_gate_ffffc704 == '\0')))) {
          DAT_ffffc728 = DAT_ffffc724 + DAT_ffffc728;
          DAT_ffffc724 = 0.0;
        }
        if ((DAT_ffffc7dd == '\x01') && (DAT_ffffc7e2 == '\x01')) {
          DAT_ffffc750 = snapshot_o2_channel_afr_fast_ffffc708 - DAT_ffffc8ec;
          fVar37 = rx8_min_float(0.0,DAT_ffffc750);
          DAT_ffffc754 = DAT_ffffc754 - fVar37;
        }
        else if (((cStack_59 == '\x01') && (DAT_ffffc7dd == '\0')) ||
                ((cVar29 == '\x01' && (DAT_ffffc7e2 == '\0')))) {
          DAT_ffffc758 = DAT_ffffc754 + DAT_ffffc758;
          DAT_ffffc754 = 0.0;
        }
      }
      if (DAT_ffffc7ef == '\x01') {
        DAT_ffffc730 = 0.0;
        DAT_ffffc760 = 0.0;
        DAT_ffffc7ef = '\0';
      }
      else {
        if ((o2_monitor_accum_gate_ffffc704 == '\x01') && (DAT_ffffc7df == '\x01')) {
          DAT_ffffc72c = snapshot_o2_channel_lambda_slow_ffffc710 - DAT_ffffc8f4;
          fVar37 = rx8_min_float(0.0,DAT_ffffc72c);
          DAT_ffffc730 = DAT_ffffc730 - fVar37;
        }
        else if (((cVar35 == '\x01') && (DAT_ffffc7df == '\0')) ||
                ((cStack_58 == '\x01' && (o2_monitor_accum_gate_ffffc704 == '\0')))) {
          DAT_ffffc734 = DAT_ffffc730 + DAT_ffffc734;
          DAT_ffffc730 = 0.0;
        }
        if ((DAT_ffffc7dd == '\x01') && (DAT_ffffc7e3 == '\x01')) {
          DAT_ffffc75c = snapshot_o2_channel_afr_fast_ffffc708 - DAT_ffffc8ec;
          fVar37 = rx8_max_float(0.0,DAT_ffffc75c);
          DAT_ffffc760 = DAT_ffffc760 + fVar37;
        }
        else if (((cStack_59 == '\x01') && (DAT_ffffc7dd == '\0')) ||
                ((cVar30 == '\x01' && (DAT_ffffc7e3 == '\0')))) {
          DAT_ffffc764 = DAT_ffffc760 + DAT_ffffc764;
          DAT_ffffc760 = 0.0;
        }
      }
      if (DAT_ffffc7f0 == '\x01') {
        DAT_ffffc73c = 0.0;
        DAT_ffffc76c = 0.0;
        DAT_ffffc7f0 = '\0';
      }
      else {
        if ((o2_monitor_accum_gate_ffffc704 == '\x01') && (DAT_ffffc7e0 == '\x01')) {
          DAT_ffffc738 = snapshot_o2_channel_lambda_very_slow_ffffc714 - DAT_ffffc8f8;
          fVar37 = rx8_max_float(0.0,DAT_ffffc738);
          DAT_ffffc73c = DAT_ffffc73c + fVar37;
        }
        else if (((cVar36 == '\x01') && (DAT_ffffc7e0 == '\0')) ||
                ((cStack_58 == '\x01' && (o2_monitor_accum_gate_ffffc704 == '\0')))) {
          DAT_ffffc740 = DAT_ffffc73c + DAT_ffffc740;
          DAT_ffffc73c = 0.0;
        }
        if ((DAT_ffffc7dd == '\x01') && (DAT_ffffc7e4 == '\x01')) {
          DAT_ffffc768 = snapshot_o2_channel_afr_medium_ffffc70c - DAT_ffffc8f0;
          fVar37 = rx8_min_float(0.0,DAT_ffffc768);
          DAT_ffffc76c = DAT_ffffc76c - fVar37;
        }
        else if (((cStack_59 == '\x01') && (DAT_ffffc7dd == '\0')) ||
                ((cVar31 == '\x01' && (DAT_ffffc7e4 == '\0')))) {
          DAT_ffffc770 = DAT_ffffc76c + DAT_ffffc770;
          DAT_ffffc76c = 0.0;
        }
      }
      if (DAT_ffffc7f1 == '\x01') {
        DAT_ffffc748 = 0.0;
        DAT_ffffc778 = 0.0;
        DAT_ffffc7f1 = '\0';
      }
      else {
        if ((o2_monitor_accum_gate_ffffc704 == '\x01') && (DAT_ffffc7e1 == '\x01')) {
          DAT_ffffc744 = snapshot_o2_channel_lambda_very_slow_ffffc714 - DAT_ffffc8f8;
          fVar37 = rx8_min_float(0.0,DAT_ffffc744);
          DAT_ffffc748 = DAT_ffffc748 - fVar37;
        }
        else if (((cVar28 == '\x01') && (DAT_ffffc7e1 == '\0')) ||
                ((cStack_58 == '\x01' && (o2_monitor_accum_gate_ffffc704 == '\0')))) {
          DAT_ffffc74c = DAT_ffffc748 + DAT_ffffc74c;
          DAT_ffffc748 = 0.0;
        }
        if ((DAT_ffffc7dd == '\x01') && (DAT_ffffc7e5 == '\x01')) {
          DAT_ffffc774 = snapshot_o2_channel_afr_medium_ffffc70c - DAT_ffffc8f0;
          fVar37 = rx8_max_float(0.0,DAT_ffffc774);
          DAT_ffffc778 = DAT_ffffc778 + fVar37;
        }
        else if (((cStack_59 == '\x01') && (DAT_ffffc7dd == '\0')) ||
                ((cVar32 == '\x01' && (DAT_ffffc7e5 == '\0')))) {
          DAT_ffffc77c = DAT_ffffc778 + DAT_ffffc77c;
          DAT_ffffc778 = 0.0;
        }
      }
      cVar33 = DAT_ffffc90a;
      uVar12 = DAT_ffffc904;
      if (((cVar6 == '\x01') && (sVar11 == 0)) && (DAT_ffffc7b8 == 0x32)) {
        DAT_ffffc90a = '\x01';
        if (cVar33 == '\0') {
          bVar5 = true;
        }
      }
      else {
        DAT_ffffc90a = '\0';
      }
      if ((bVar5) && (DAT_ffffc904 == 0)) {
        DAT_ffffc904 = DAT_ffffc7b2;
      }
      else if (DAT_ffffc904 < 2) {
        DAT_ffffc904 = 0;
      }
      else {
        DAT_ffffc904 = DAT_ffffc904 - 2;
      }
      if ((uVar12 == 0) || (DAT_ffffc904 != 0)) {
        o2_monitor_fluctuation_detected_ffffc701 = 0;
      }
      else {
        o2_monitor_fluctuation_detected_ffffc701 = 1;
        cVar33 = rx8_is_outside_tolerance_band(DAT_ffffc728,0,0x3727c5ac);
        cVar34 = rx8_is_outside_tolerance_band(DAT_ffffc734,0,0x3727c5ac);
        cVar35 = rx8_is_outside_tolerance_band(DAT_ffffc740,0,0x3727c5ac);
        cVar36 = rx8_is_outside_tolerance_band(DAT_ffffc74c,0,0x3727c5ac);
        if (cVar33 == '\0') {
          o2_monitor_ratio_ch0_ffffc6f0 = 0.0;
        }
        else {
          o2_monitor_ratio_ch0_ffffc6f0 = DAT_ffffc758 / DAT_ffffc728;
        }
        if (cVar34 == '\0') {
          o2_monitor_ratio_ch1_ffffc6f4 = 0.0;
        }
        else {
          o2_monitor_ratio_ch1_ffffc6f4 = DAT_ffffc764 / DAT_ffffc734;
        }
        if (cVar35 == '\0') {
          o2_monitor_ratio_ch2_ffffc780 = 0.0;
        }
        else {
          o2_monitor_ratio_ch2_ffffc780 = DAT_ffffc770 / DAT_ffffc740;
        }
        if (cVar36 == '\0') {
          o2_monitor_ratio_ch3_ffffc784 = 0.0;
        }
        else {
          o2_monitor_ratio_ch3_ffffc784 = DAT_ffffc77c / DAT_ffffc74c;
        }
      }
    }
    DAT_ffffc8f4 = snapshot_o2_channel_lambda_slow_ffffc710;
    DAT_ffffc8f8 = snapshot_o2_channel_lambda_very_slow_ffffc714;
    DAT_ffffc8ec = snapshot_o2_channel_afr_fast_ffffc708;
    DAT_ffffc8f0 = snapshot_o2_channel_afr_medium_ffffc70c;
  }
  DAT_ffffc8fe = sVar11;
  DAT_ffffc909 = cVar6;
  return;
}


