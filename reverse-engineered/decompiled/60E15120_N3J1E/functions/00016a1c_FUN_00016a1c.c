/* ROM address: 0x00016a1c; body bytes: 128; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00016820 (128 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00016a1c(undefined1 param_1)

{
  byte bVar1;
  undefined4 local_20;
  undefined4 auStack_1c [2];
  
  DAT_ffffdf94 = -1;
  DAT_ffffdf92 = param_1;
  ref_setSR_PARAM(auStack_1c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff746,0x40,0);
  FUN_00002064(auStack_1c[0]);
  bVar1 = 0;
  while ((bVar1 < 200 && (DAT_ffffdf94 == -1))) {
    sh_busy_wait_count_times_8(1);
    bVar1 = bVar1 + 1;
  }
  ref_setSR_PARAM(&local_20,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff746,0x40,1);
  FUN_00002064(local_20);
  return;
}


