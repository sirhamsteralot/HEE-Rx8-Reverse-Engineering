/* ROM address: 0x00030228; body bytes: 76; decompiled */

void FUN_00030228(void)

{
  float fVar1;
  
  if ((engine_running_ffffa428 == '\0') || (cranking_decay_counter_ffffbe3c != '\0')) {
    fVar1 = DAT_ffffbe68 * 1.0 * DAT_ffffbe7c * DAT_ffffbe80 * DAT_ffffbe84;
    injector_pulse_crank_ffffbe58 = DAT_ffffbe88 * fVar1;
    injector_pulse_crank_base_ffffbe5c = DAT_ffffbe8c * fVar1;
  }
  return;
}


