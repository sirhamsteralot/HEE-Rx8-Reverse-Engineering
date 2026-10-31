/* ROM address: 0x0002f8ce; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002fd86 (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002f8ce(void)

{
  undefined4 local_18;
  undefined4 uStack_14;
  char cStack_10;
  
  cStack_10 = FUN_0005c204((int)DAT_ffffbdd8);
  ref_setSR_PARAM(&uStack_14,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,4,cStack_10 == '\x01');
  FUN_00002064(uStack_14);
  cStack_10 = DAT_ffffbdbc;
  ref_setSR_PARAM(&local_18,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,2,cStack_10 == '\x01');
  FUN_00002064(local_18);
  return;
}


