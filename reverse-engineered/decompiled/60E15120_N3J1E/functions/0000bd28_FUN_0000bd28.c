/* ROM address: 0x0000bd28; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000bd28 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000bd28(void)

{
  undefined4 local_14;
  undefined4 auStack_10 [2];
  
  ref_setSR_PARAM(auStack_10,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff72c,0x100,1);
  FUN_00002064(auStack_10[0]);
  ref_setSR_PARAM(&local_14,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff72c,0x80);
  FUN_00002064(local_14);
  sh_busy_wait_count_times_8(4);
  FUN_0000bccc();
  return;
}


