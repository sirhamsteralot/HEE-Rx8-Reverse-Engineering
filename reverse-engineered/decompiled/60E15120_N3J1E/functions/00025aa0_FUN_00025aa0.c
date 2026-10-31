/* ROM address: 0x00025aa0; body bytes: 90; decompiled */

void FUN_00025aa0(void)

{
  if (inferred_coolant_temperature_ffffa98c < 60.0) {
    if (inferred_coolant_temperature_ffffa98c < 55.0) {
      DAT_ffffb648 = '\0';
    }
  }
  else {
    DAT_ffffb648 = '\x01';
  }
  if ((engine_running_ffffa428 == '\0') && (DAT_ffffb648 == '\x01')) {
    DAT_ffffb60c = 100;
  }
  else if (DAT_ffffb60c != 0) {
    DAT_ffffb60c = DAT_ffffb60c + -1;
  }
  return;
}


