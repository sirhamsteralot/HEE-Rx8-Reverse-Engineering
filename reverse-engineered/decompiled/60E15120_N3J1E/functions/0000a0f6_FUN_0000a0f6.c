/* ROM address: 0x0000a0f6; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a0f6 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000a0f6(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  uVar1 = os_schedule_task_event(1,7,local_8);
  return uVar1;
}


