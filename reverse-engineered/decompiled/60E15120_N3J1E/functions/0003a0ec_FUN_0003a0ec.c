/* ROM address: 0x0003a0ec; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003a520 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0003a0ec(void)

{
  undefined4 local_10;
  undefined4 auStack_c [2];
  
  ref_setSR_PARAM(auStack_c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff746,0x80,DAT_ffffcfb6 == '\x01');
  FUN_00002064(auStack_c[0]);
  ref_setSR_PARAM(&local_10,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,1,DAT_ffffcfb7 == '\0');
  FUN_00002064(local_10);
  return;
}


