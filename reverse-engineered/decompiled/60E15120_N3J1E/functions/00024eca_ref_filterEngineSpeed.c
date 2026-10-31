/* ROM address: 0x00024eca; body bytes: 132; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025752 (132 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_filterEngineSpeed(void)

{
  char cVar1;
  undefined4 *extraout_r0;
  undefined4 *puVar2;
  float arg3;
  
  cVar1 = engine_running_ffffa428;
  arg3 = 1e-05;
  if (engine_running_ffffa428 == '\0') {
    DAT_ffffb550 = engine_speed_rpm_ffffb548;
  }
  else {
    DAT_ffffb550 = rx8_first_order_filter(engine_speed_rpm_ffffb548,DAT_ffffb550,0.125,1e-05);
  }
  DAT_ffffb54c = ((engine_speed_rpm_ffffb548 + DAT_ffffb54c) - DAT_ffffb560) * 0.5;
  DAT_ffffb560 = engine_speed_rpm_ffffb548;
  if ((cVar1 == '\0') || (DAT_ffffa7ac + 200.0 <= engine_speed_rpm_ffffb548)) {
    puVar2 = &DAT_00024fb4;
    DAT_ffffb554 = engine_speed_rpm_ffffb548;
  }
  else {
    DAT_ffffb554 = rx8_first_order_filter(engine_speed_rpm_ffffb548,DAT_ffffb554,0.031,arg3);
    puVar2 = extraout_r0;
  }
  return puVar2;
}


