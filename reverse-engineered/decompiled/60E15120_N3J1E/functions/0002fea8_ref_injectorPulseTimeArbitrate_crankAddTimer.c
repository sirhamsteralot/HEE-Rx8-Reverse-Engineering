/* [ADDITIONAL SOURCE REVIEW]
 * injector_pulse_time_arbitrate [high]: Cranking (!engine_running): be30 = be38 = be5c + latency be44; running: be30 = be50+be44, be38 = be54+be44; be28 = be24 = (cranking? be58 : be4c) + latency be40; be2c = be30, be34 = be38; cranking decay counter be3c from tbl 0x6bab0 'Primary Fuel Injector Cranking Pulse Decay Time'(coolant), decrementing while running.
 * RAM 0xffffbe24 injector_pulse_time (float): Final arbitrated pulse time be24 = be28; encoded by diag PID 0x1410 handler 0x56f6c (step 8; logger x*8*0.001 ms).
 * RAM 0xffffbe28 injector_pulse_time_base (float): be28 = (cranking? be58 : be4c) + injector_latency_primary be40; copied to be24.
 * RAM 0xffffbe2c injector_pulse_time_ch1 (float): be2c = be30 (running: be50 + be44; cranking: be5c + be44).
 * RAM 0xffffbe30 injector_pulse_time_ch2 (float): be30 = running? be50 + be44 : be5c + be44 (latency be44 added).
 * RAM 0xffffbe34 injector_pulse_time_ch3 (float): be34 = be38.
 * RAM 0xffffbe38 injector_pulse_time_ch4 (float): be38 = running? be54 + be44 : be5c + be44.
 * RAM 0xffffbe3c cranking_decay_counter (uint8): Cranking: loaded from tbl 0x6bab0 'Primary Fuel Injector Cranking Pulse Decay Time'(coolant); decrements while running.
 * RAM 0xffffbe5c injector_pulse_crank_base (float): Cranking base for be30/be38 while engine not running.
 */
/* ROM address: 0x0002fea8; body bytes: 164; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00030344 (164 bytes). Names prefixed ref_
   are inherited hypotheses. */

void injector_pulse_time_arbitrate(void)

{
  float fVar1;
  char cVar2;
  
  cVar2 = engine_running_ffffa428;
  if (engine_running_ffffa428 == '\0') {
    cranking_decay_counter_ffffbe3c = rx8_lookup_2d_raw_u8(inferred_coolant_temperature_ffffa98c,&tbl_primary_fuel_injector_cranking_pulse_decay_time_0006bab0);
  }
  else if (cranking_decay_counter_ffffbe3c != '\0') {
    cranking_decay_counter_ffffbe3c = cranking_decay_counter_ffffbe3c + -1;
  }
  if ((cVar2 == '\0') || (cranking_decay_counter_ffffbe3c != '\0')) {
    injector_pulse_time_ch2_ffffbe30 = injector_pulse_crank_base_ffffbe5c + injector_latency_primary_ffffbe44;
    injector_pulse_time_ch4_ffffbe38 = injector_pulse_time_ch2_ffffbe30;
    fVar1 = injector_pulse_crank_ffffbe58;
  }
  else {
    injector_pulse_time_ch2_ffffbe30 = DAT_ffffbe50 + injector_latency_primary_ffffbe44;
    injector_pulse_time_ch4_ffffbe38 = DAT_ffffbe54 + injector_latency_primary_ffffbe44;
    fVar1 = DAT_ffffbe4c;
  }
  injector_pulse_time_base_ffffbe28 = fVar1 + injector_latency_secondary_ffffbe40;
  injector_pulse_time_ffffbe24 = injector_pulse_time_base_ffffbe28;
  injector_pulse_time_ch1_ffffbe2c = injector_pulse_time_ch2_ffffbe30;
  injector_pulse_time_ch3_ffffbe34 = injector_pulse_time_ch4_ffffbe38;
  return;
}


