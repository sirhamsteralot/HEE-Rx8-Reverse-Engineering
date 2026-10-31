/* ROM address: 0x0000bccc; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000bccc (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000bccc(void)

{
  undefined4 local_14;
  undefined4 auStack_10 [2];
  
  ISR_W = 0xf7;
  DAT_ffffa322 = 1;
  DAT_ffffa31e = 0;
  DAT_ffffa321 = 0;
  ref_setSR_PARAM(auStack_10,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff72c,0x100,0);
  FUN_00002064(auStack_10[0]);
  ref_setSR_PARAM(&local_14,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff72c,0x80,0);
  FUN_00002064(local_14);
  return;
}


