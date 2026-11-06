/* [ADDITIONAL SOURCE REVIEW]
 * hot_engine_dtc_timer [medium]: 0xffffb648 = coolant >= 60 (hyst 55); 0xffffb60c = 100 when engine stopped && coolant hot, else counts down. Called from 0x2680e via pool 0x268bc.
 */
/* ROM address: 0x00025aa0; body bytes: 90; decompiled */

void candidate_hot_engine_dtc_timer(void)

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


