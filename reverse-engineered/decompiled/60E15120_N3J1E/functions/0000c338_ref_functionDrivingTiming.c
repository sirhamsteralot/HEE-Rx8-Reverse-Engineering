/* ROM address: 0x0000c338; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000c338 (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_functionDrivingTiming(byte param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  if (knock_state_mode_ffffa38c == '\0') {
    if (0xb < param_1) {
      param_1 = param_1 - 0xc;
    }
    do {
      if (param_1 == (&DAT_0000d90e)[iVar1]) {
        DAT_ffffa383 = (undefined1)iVar1;
        iVar2 = 1;
        break;
      }
      if (param_1 == (&DAT_0000d910)[iVar1]) {
        iVar2 = 2;
        break;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 2);
    if (iVar2 == 1) {
      ref_setupCoilOutputs();
      if (knock_rotor_index_ffffa384 != -1) {
        knock_magnitude_integrate();
        return;
      }
    }
    else if (iVar2 == 2) {
      knock_sensor_sci_command();
      DAT_ffffa385 = 1;
    }
  }
  return;
}


