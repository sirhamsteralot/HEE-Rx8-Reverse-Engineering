/* ROM address: 0x0000a10e; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a10e (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_putTaskInSchedule_FuelArrayStuff(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  uVar1 = os_schedule_task_event(1,4,local_8);
  return uVar1;
}


