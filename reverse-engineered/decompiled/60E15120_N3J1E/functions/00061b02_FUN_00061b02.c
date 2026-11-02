/* ROM address: 0x00061b02; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000603f2 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00061b02(uint param_1)

{
  undefined4 uVar1;
  undefined4 local_c;
  uint uStack_8;
  
  uStack_8 = param_1 & 0xffff;
  local_c = 0x14;
  uVar1 = os_schedule_task_event(2,3,&local_c);
  return uVar1;
}


