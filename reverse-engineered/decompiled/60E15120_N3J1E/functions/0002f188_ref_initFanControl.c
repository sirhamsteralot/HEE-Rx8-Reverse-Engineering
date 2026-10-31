/* ROM address: 0x0002f188; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002f640 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_initFanControl_0002f188(void)

{
  undefined4 local_14;
  undefined4 auStack_10 [2];
  
  ref_setSR_PARAM(auStack_10,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,0x800,DAT_ffffbda1 == '\x01');
  FUN_00002064(auStack_10[0]);
  ref_setSR_PARAM(&local_14,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,0x10,DAT_ffffbda2 == '\x01');
  FUN_00002064(local_14);
  return;
}


