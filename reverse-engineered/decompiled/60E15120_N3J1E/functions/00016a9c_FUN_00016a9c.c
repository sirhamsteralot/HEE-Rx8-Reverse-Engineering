/* ROM address: 0x00016a9c; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000168a0 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00016a9c(void)

{
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 auStack_1c [2];
  
  ref_setSR_PARAM(auStack_1c,0xe0);
  ref_setSR_PARAM(&uStack_20,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff746,0x40,0);
  FUN_00002064(uStack_20);
  ref_setSR_PARAM(&local_24,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff746,0x40,1);
  FUN_00002064(local_24);
  FUN_00002064(auStack_1c[0]);
  return;
}


