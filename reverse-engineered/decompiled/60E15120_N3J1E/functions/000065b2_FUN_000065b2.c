/* ROM address: 0x000065b2; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000065b2 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void task13_temp_sensor_dtc_entry(void)

{
  iat_sensor_scaling_fault();
  clt_sensor_scaling_fault();
  dtc_fault_service_batch();
  ref_taskEndRoutine_();
  return;
}


