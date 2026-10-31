/* ROM address: 0x000065f6; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000065f6 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_task1_(void)

{
  undefined4 uVar1;
  
  uVar1 = ref_getRotorNumberForControl_(0);
  ref_functionDrivingTiming(uVar1);
  FUN_000082d8();
  FUN_00009038();
  FUN_00011b7e(uVar1);
  ref_taskEndRoutine_();
  return;
}


