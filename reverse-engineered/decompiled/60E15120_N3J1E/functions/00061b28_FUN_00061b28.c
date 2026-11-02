/* ROM address: 0x00061b28; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060418 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00061b28(uint param_1)

{
  undefined4 uVar1;
  uint local_8 [2];
  
  local_8[0] = param_1 & 0xffff;
  uVar1 = os_schedule_task_event(2,5,local_8);
  return uVar1;
}


