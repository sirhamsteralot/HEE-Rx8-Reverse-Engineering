/* ROM address: 0x0003a152; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003a586 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0003a152(void)

{
  char cVar1;
  uint uVar2;
  undefined4 local_10 [2];
  
  cVar1 = DAT_ffffcfc4;
  if ((DAT_ffffc528 == 0) && (DAT_ffffcfc4 == '\x01')) {
    local_10[0] = 0;
    os_schedule_task_event(0,2,local_10);
  }
  uVar2 = (uint)DAT_ffffc528;
  if ((uVar2 == 1) && (cVar1 == '\0')) {
    local_10[0] = 0;
    uVar2 = os_schedule_task_event(0,3,local_10);
  }
  DAT_ffffc528 = cVar1;
  return uVar2;
}


