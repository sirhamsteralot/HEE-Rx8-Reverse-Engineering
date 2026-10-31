/* ROM address: 0x0000661e; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000661e (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_task2_(void)

{
  char cVar1;
  
  cVar1 = ref_getRotorNumberForControl_(1);
  knock_voltage_sample();
  ref_engineControlTASK((int)cVar1);
  FUN_00008320();
  ref_getIgnitionDwellTime_00009110();
  ref_taskEndRoutine_();
  return;
}


