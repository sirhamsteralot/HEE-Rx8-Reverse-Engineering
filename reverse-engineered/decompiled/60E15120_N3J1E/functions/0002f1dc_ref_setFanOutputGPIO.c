/* ROM address: 0x0002f1dc; body bytes: 100; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002f694 (100 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setFanOutputGPIO(void)

{
  undefined4 local_18;
  undefined4 uStack_14;
  char cStack_10;
  
  cStack_10 = FUN_0005c724((int)DAT_ffffbda1);
  ref_setSR_PARAM(&uStack_14,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,0x800,cStack_10 == '\x01');
  FUN_00002064(uStack_14);
  cStack_10 = FUN_0005c648((int)DAT_ffffbda2);
  ref_setSR_PARAM(&local_18,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,0x10,cStack_10 == '\x01');
  FUN_00002064(local_18);
  return;
}


