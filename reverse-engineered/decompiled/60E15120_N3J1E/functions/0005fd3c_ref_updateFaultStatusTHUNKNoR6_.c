/* [ADDITIONAL SOURCE REVIEW]
 * dtc_set_fault_xdefault [high]: Entry 0x5fd3c: extu.w r6,r3; tst r3,r3; bf/s skip; mov.l @(0x5fe0c,pc),r6 where pool 0x5fe0c = 0x0000ffff; then bra 0x5fe20 (a06b at 0x5fd46): trampoline to dtc_set_fault with x defaulted to 0xffff when the caller passes r6==0. 2 callers (0x44724, 0x44cec), both computing r6 from flag bits before the call (jsr via pool words 0x447ac/0x44d54). Inherited ref_updateFaultStatusTHUNKNoR6_ is a misnomer: the body is set_fault, not a fault-status update; 'NoR6' = trampoline for callers that leave r6 unset.
 */
/* ROM address: 0x0005fd3c; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e648 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void dtc_set_fault_xdefault(undefined4 param_1,undefined4 param_2,uint param_3)

{
  if ((param_3 & 0xffff) == 0) {
    param_3 = 0xffff;
  }
  FUN_0005fe20(param_1,param_2,param_3);
  return;
}


