/* ROM address: 0x00045054; body bytes: 396; decompiled */

void FUN_00045054(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = 0.0;
  fVar2 = rx8_absolute_difference(DAT_ffffc160,0.0);
  DAT_ffffcbb1 = 0.05 < fVar2;
  fVar2 = rx8_absolute_difference(DAT_ffffb54c,fVar3);
  DAT_ffffcbb2 = 50.0 < fVar2;
  fVar2 = leading_ignition_timing_ffffa630;
  fVar3 = rx8_absolute_difference(leading_ignition_timing_ffffa630,DAT_ffffcbc8);
  DAT_ffffcbb3 = 90.0 < fVar3;
  if (engine_running_ffffa428 == '\0') {
    DAT_ffffcbb5 = '\n';
  }
  else if (((DAT_ffffcbb1 == '\x01') || (DAT_ffffcbb2 == '\x01')) || ((bool)DAT_ffffcbb3)) {
    DAT_ffffcbb5 = '@';
  }
  else if ((DAT_ffffcbb0 == '\0') && (DAT_ffffcbb5 != '\0')) {
    DAT_ffffcbb5 = DAT_ffffcbb5 + -1;
  }
  if (DAT_ffffa5d8 != 0) {
    DAT_ffffcbcc = 0;
  }
  DAT_ffffcbc8 = fVar2;
  if ((((DAT_ffffd1c5 != '\0') || (DAT_ffffcbb5 != '\0')) ||
      ((DAT_ffffcbcc < 0x177 ||
       (((((int)((uint)DAT_ffffcba8 - (uint)DAT_ffffcbcc) < 0x271 || (-1.0 < engine_speed_rpm_ffffb548)) ||
         (inferred_battery_voltage_ffffb590 < 9.0)) || (16.5 < inferred_battery_voltage_ffffb590)))))) ||
     (((cVar1 = ref_getFaultStatus__(0x29), cVar1 != '\0' &&
       (cVar1 = ref_getFaultStatus__(0x2a), cVar1 != '\0')) &&
      ((cVar1 = ref_getFaultStatus__(0x27), cVar1 != '\0' &&
       (cVar1 = ref_getFaultStatus__(0x28), cVar1 != '\0')))))) {
    DAT_ffffcbb4 = 0;
  }
  else {
    DAT_ffffcbb4 = 1;
  }
  DAT_ffffcbcc = DAT_ffffa0d4;
  return;
}


