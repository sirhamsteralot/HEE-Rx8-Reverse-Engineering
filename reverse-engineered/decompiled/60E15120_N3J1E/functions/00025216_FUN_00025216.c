/* ROM address: 0x00025216; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025a9e (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00025216(void)

{
  char cVar1;
  uint uVar2;
  undefined4 local_10 [2];
  
  cVar1 = DAT_ffffccc6;
  if ((DAT_ffffb575 == 0) && (DAT_ffffccc6 == '\x01')) {
    local_10[0] = 0;
    ref_osTaskScheduler(0,2,local_10);
  }
  uVar2 = (uint)DAT_ffffb575;
  if ((uVar2 == 1) && (cVar1 == '\0')) {
    local_10[0] = 0;
    uVar2 = ref_osTaskScheduler(0,3,local_10);
  }
  DAT_ffffb575 = cVar1;
  return uVar2;
}


