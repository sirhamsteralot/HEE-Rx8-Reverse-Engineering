/* [ADDITIONAL SOURCE REVIEW]
 * charging_control_batch [high]: 7-call batch, pool 0x11ca8-0x11cc0 ROM-verified: 0x19d8a, 0x39b08, 0x2145e, ref_alternatorControlMain_00026868, 0x2224e, 0x59ab0, 0x16c56. Called only from task[14] 0x65cc.
 */
/* ROM address: 0x00011adc; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00011b54 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void charging_control_batch(void)

{
  FUN_00019d8a();
  FUN_00039b08();
  FUN_0002145e();
  alternator_pid_task();
  FUN_0002224e();
  FUN_00059ab0();
  FUN_00016c56();
  return;
}


