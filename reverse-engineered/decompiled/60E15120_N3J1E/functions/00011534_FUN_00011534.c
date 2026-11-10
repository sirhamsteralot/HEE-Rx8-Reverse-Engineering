/* [ADDITIONAL SOURCE REVIEW]
 * slow_background_task [high]: 29-call slow/background task: 0x2e5c6, ref_calculateTorqueRelatedParams, 0x38f3e, 0x21186, candidate_timing_retard_fast_task, ..., ref_calculateDiagModeTimer 0x55d42, ref_runImmoRelatedCounter, ..., 0x2a290, 0x16b50.
 */
/* ROM address: 0x00011534; body bytes: 176; decompiled */

void slow_background_task(void)

{
  FUN_0002e5c6();
  ref_calculateTorqueRelatedParams();
  FUN_00038f3e();
  FUN_00021186();
  timing_retard_fast_task();
  FUN_00021b4c();
  FUN_000253e8();
  FUN_000288be();
  FUN_00025532();
  ref_calculateDiagModeTimer();
  FUN_00055dac();
  FUN_0005bb56();
  FUN_0005bb92();
  FUN_0005e1f6();
  FUN_0005e232();
  FUN_0005dd78();
  ref_setDiagMode85Bool_();
  ref_runImmoRelatedCounter();
  FUN_0005b7ec();
  FUN_00056856();
  FUN_0005b492();
  FUN_0005d9d8();
  FUN_0005d77c();
  FUN_0005be6c();
  FUN_0005b13a();
  FUN_00057ec8();
  FUN_0005e8a4();
  FUN_0002a290();
  FUN_00016b50();
  return;
}


