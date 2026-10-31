/* ROM address: 0x0000a850; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a850 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000a850(void)

{
  ushort uVar1;
  undefined4 local_c [2];
  
  ref_setSR_PARAM(local_c,0xe0);
  uVar1 = PBDR_W;
  PBDR_W = uVar1 | 0x8000;
  sh_busy_wait_count_times_8(0x96);
  uVar1 = PBDR_W;
  PBDR_W = uVar1 & 0x7fff;
  sh_busy_wait_count_times_8(0x96);
  FUN_00002064(local_c[0]);
  return;
}


