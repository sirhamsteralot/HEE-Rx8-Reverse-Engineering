/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00018aea; body bytes: 428; decompiled */

uint FUN_00018aea(void)

{
  byte snapshot_candidate_idle_learn_flag_ffffcc91;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  
  snapshot_candidate_idle_learn_flag_ffffcc91 = candidate_idle_learn_flag_ffffcc91;
  if (engine_speed_rpm_ffffb548 < 8500.0) {
    if (engine_speed_rpm_ffffb548 < 8400.0) {
      DAT_ffffa980 = '\0';
    }
  }
  else {
    DAT_ffffa980 = '\x01';
  }
  if (engine_speed_rpm_ffffb548 < 3000.0) {
    if (engine_speed_rpm_ffffb548 < 2900.0) {
      DAT_ffffa981 = '\0';
    }
  }
  else {
    DAT_ffffa981 = '\x01';
  }
  if (engine_speed_rpm_ffffb548 < 1300.0) {
    if (engine_speed_rpm_ffffb548 < 1200.0) {
      DAT_ffffa982 = 0;
    }
  }
  else {
    DAT_ffffa982 = 1;
  }
  if (engine_speed_rpm_ffffb548 < 1300.0) {
    if (engine_speed_rpm_ffffb548 < 1200.0) {
      DAT_ffffa983 = 0;
    }
  }
  else {
    DAT_ffffa983 = 1;
  }
  uVar2 = (uint)DAT_ffffa96b;
  if ((cranking_active_ffffaa62_ffffaa62 == 1) || (2 < candidate_idle_learn_flag_ffffcc91)) {
    DAT_ffffa970 = 0;
    DAT_ffffa972 = 0;
    DAT_ffffa974 = 0;
    uVar3 = (uint)cranking_active_ffffaa62_ffffaa62;
    DAT_ffffa966 = 0;
  }
  else if (uVar2 == 1) {
    uVar4 = DAT_ffffa966;
    if (DAT_ffffa980 == '\x01') {
      if (0x4d < DAT_ffffa970) {
        uVar4 = 1;
      }
      DAT_ffffa970 = rx8_add_u16_saturate((int)(short)DAT_ffffa970,1);
    }
    else {
      DAT_ffffa970 = 0;
    }
    if (DAT_ffffa981 == '\x01') {
      if (0x3a9 < DAT_ffffa972) {
        uVar4 = 1;
      }
      DAT_ffffa972 = rx8_add_u16_saturate((int)(short)DAT_ffffa972,1);
    }
    else {
      DAT_ffffa972 = 0;
    }
    if (DAT_ffffa982 == 1) {
      if (0x927 < DAT_ffffa974) {
        uVar4 = 1;
      }
      uVar3 = rx8_add_u16_saturate((int)(short)DAT_ffffa974,1);
      DAT_ffffa974 = (ushort)uVar3;
      DAT_ffffa966 = uVar4;
    }
    else {
      DAT_ffffa974 = 0;
      uVar3 = (uint)DAT_ffffa982;
      DAT_ffffa966 = uVar4;
    }
  }
  else {
    DAT_ffffa970 = 0;
    DAT_ffffa972 = 0;
    DAT_ffffa974 = 0;
    uVar3 = uVar2;
  }
  if (((snapshot_candidate_idle_learn_flag_ffffcc91 < 3) || (uVar3 = uVar2, uVar2 != 1)) || (uVar3 = (uint)DAT_ffffa983, uVar3 != 1)) {
    DAT_ffffa976 = 0;
  }
  else {
    if (0x927 < DAT_ffffa976) {
      decel_cut_request_b_ffffa96c = 1;
    }
    uVar3 = rx8_add_u16_saturate((int)(short)DAT_ffffa976,1);
    DAT_ffffa976 = (ushort)uVar3;
  }
  return uVar3;
}


