/* [ADDITIONAL SOURCE REVIEW]
 * knock_sensor_fault_task [medium]: Task[9] entry: runs ref_knockSensorADCFault (0xc290: ADC 0xffff9f0e vs u16 thresholds 51249/16121 at ROM 0x6c17e/0x6c17c -> a325 fault status).
 */
/* ROM address: 0x000064ba; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000064ba (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

void knock_sensor_fault_task(void)

{
  ref_main__();
  FUN_00006842();
  FUN_000094fc();
  ref_knockSensorADCFault();
  FUN_0001150e();
  FUN_00009fb2(0);
  ref_taskEndRoutine_();
  return;
}


