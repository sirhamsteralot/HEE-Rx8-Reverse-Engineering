/* [ADDITIONAL SOURCE REVIEW]
 * candidate_cranking_pulse_product [high]: While 0xffffa428 == 0 or the decay counter 0xffffbe3c > 0 (cmp/pl at 0x30238): 0xffffbe58 = be68*be7c*be80*be84*be88 and 0xffffbe5c = be68*be7c*be80*be84*be8c (factor pools 0x30312/0x30314/0x30316/0x30318/0x3031a; unity seeds via pool 0x3032c = f32 0x77f58 = 1.0).
 */
/* ROM address: 0x00030228; body bytes: 76; decompiled */

void candidate_cranking_pulse_product(void)

{
  float fVar1;
  
  if ((engine_running_ffffa428 == '\0') || (cranking_decay_counter_ffffbe3c != '\0')) {
    fVar1 = candidate_cranking_throttle_factor_ffffbe68 * 1.0 * candidate_cranking_coolant_factor_ffffbe7c * candidate_cranking_baro_factor_ffffbe80 * candidate_cranking_running_factor_ffffbe84;
    injector_pulse_crank_ffffbe58 = DAT_ffffbe88 * fVar1;
    injector_pulse_crank_base_ffffbe5c = DAT_ffffbe8c * fVar1;
  }
  return;
}


