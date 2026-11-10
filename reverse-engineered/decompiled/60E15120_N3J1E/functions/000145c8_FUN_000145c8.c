/* [ADDITIONAL SOURCE REVIEW]
 * timing_retard_fast_task [medium]: 0x1391c knock-seen counter + 0x13b40 slow recovery + throttle/rev-limit/AC retards; reached from task-table record 0x64e8 (ROM 0x4ab8, dispatch mechanism unresolved).
 */
/* ROM address: 0x000145c8; body bytes: 96; decompiled */

void timing_retard_fast_task(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00014754();
  ref_calcKnockRAMUpdate_();
  knock_retard_slow_recovery();
  FUN_00013ce0();
  ref_debounceThrottleRate();
  FUN_00013db8();
  ref_acCompressorLeadingTimingRetard();
  ref_acCompressorTrailingTimingRetard();
  ref_liftoffRelated__();
  ref_getThrottleLessThanLookupTimer();
  ref_calculateThrottlePercentDuringLift();
  FUN_000437a0();
  ref_can216DataPlausibilityCheck();
  ref_setSR(uVar1);
  return;
}


