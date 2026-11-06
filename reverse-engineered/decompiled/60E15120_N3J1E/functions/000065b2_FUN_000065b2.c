/* [ADDITIONAL SOURCE REVIEW]
 * task13_temp_sensor_dtc_entry [high]: ROADMAP C item 7. rec[13] @ROM 0x4a60 entry; pool 0x66d0-0x66d8 = {0x7298, 0x73a0, 0x118d0}. Dynamic: harness call 0x65b2 visits all three, writes 0xffff9f60/9f70/9f64/9f74 (test_c7_task_handlers.py).
 */
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


