/* ROM address: 0x00060190; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ea80 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00060190(uint param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint local_10;
  uint uStack_c;
  uint uStack_8;
  
  local_10 = param_1 & 0xffff;
  uStack_c = param_2 & 0xff;
  uStack_8 = param_3 & 0xffff;
  uVar1 = os_schedule_task_event(2,2,&local_10);
  return uVar1;
}


