/* ROM address: 0x0002556c; body bytes: 130; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025df4 (130 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setImmoLight__(char param_1)

{
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 auStack_1c [2];
  
  if (param_1 == '\x01') {
    ref_setSR_PARAM(auStack_1c,0xe0);
    ref_setRegister_REG_BIT_VAL(0xfffff754,0x40,1);
    FUN_00002064(auStack_1c[0]);
    ref_setSR_PARAM(&uStack_20,0xe0);
    ref_setRegister_REG_BIT_VAL(0xfffff754,0x20,1);
  }
  else {
    ref_setSR_PARAM(&uStack_24,0xe0);
    ref_setRegister_REG_BIT_VAL(0xfffff754,0x20,0);
    FUN_00002064(uStack_24);
    ref_setSR_PARAM(&uStack_28,0xe0);
    ref_setRegister_REG_BIT_VAL(0xfffff754,0x40,0);
    uStack_20 = uStack_28;
  }
  FUN_00002064(uStack_20);
  return;
}


