/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001a1dc; body bytes: 362; decompiled */

uint FUN_0001a1dc(void)

{
  char cVar1;
  byte snapshot_DAT_ffffaa4e;
  uint uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float arg0;
  float arg1;
  float arg1_00;
  
  snapshot_DAT_ffffaa4e = DAT_ffffaa4e;
  cVar1 = DAT_ffffaa4d;
  arg0 = DAT_ffffa834;
  arg1 = inferred_throttle_position_ffffad44;
  arg1_00 = engine_speed_rpm_ffffb548;
  DAT_ffffaa44 = rx8_first_order_filter(engine_speed_rpm_ffffb548,DAT_ffffaa44,0.5,1e-05);
  fVar4 = rx8_absolute_difference(DAT_ffffaa40,arg1);
  fVar5 = rx8_absolute_difference(DAT_ffffaa44,arg1_00);
  fVar6 = rx8_absolute_difference(arg0,DAT_ffffaa58);
  DAT_ffffaa50 = (float)lookup_2d_descriptor_scaled(arg1,&DAT_000697a0);
  if (DAT_ffffaa62 == '\0') {
    if ((DAT_ffffaa50 <= fVar4) || (8000.0 <= fVar5)) {
      DAT_ffffaa4d = 1;
    }
    else {
      DAT_ffffaa4d = 0;
    }
    DAT_ffffaa4e = 0;
  }
  else {
    DAT_ffffaa4d = 0;
    if (((0.0 <= fVar6) || (0.0 <= fVar4)) || (0.0 <= fVar5)) {
      DAT_ffffaa4e = 1;
    }
    else {
      DAT_ffffaa4e = 0;
    }
  }
  if ((cVar1 == '\x01') && (DAT_ffffaa4d == 0)) {
    DAT_ffffaa5c = '\f';
  }
  uVar3 = (uint)snapshot_DAT_ffffaa4e;
  if ((uVar3 == 1) && (DAT_ffffaa4e == 0)) {
    uVar3 = 0xc;
    DAT_ffffaa5d = '\f';
  }
  if (((((DAT_ffffaa5c != '\0') || (uVar3 = (uint)DAT_ffffaa4d, uVar3 == 1)) ||
       (DAT_ffffaa5d != '\0')) || ((uVar3 = (uint)DAT_ffffaa4e, uVar3 == 1 || (0.0 <= arg1_00)))) ||
     ((0.0 <= arg1 || (uVar3 = (uint)engine_running_timer_ffffa424, uVar3 < 0xd)))) {
    maf_filter_mode_ffffaa4c = 1;
  }
  else {
    maf_filter_mode_ffffaa4c = 0;
  }
  DAT_ffffaa58 = arg0;
  return uVar3;
}


