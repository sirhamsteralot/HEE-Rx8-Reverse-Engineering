/* ROM address: 0x00006592; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006592 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void task12_adc_feedback_pwm_entry(void)

{
  task12_alive_counter_clear();
  thunk_FUN_0000aee8();
  candidate_monitor_service_batch();
  atu_ch7d_pwm_enable();
  ref_taskEndRoutine_();
  return;
}


