/* ROM address: 0x000251d0; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025a58 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000251d0(void)

{
  undefined4 local_c [2];
  
  DAT_ffffb574 = DAT_ffffccc1 != '\x01';
  ref_setSR_PARAM(local_c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff746,0x800,DAT_ffffb574 == '\x01');
  FUN_00002064(local_c[0]);
  return;
}


