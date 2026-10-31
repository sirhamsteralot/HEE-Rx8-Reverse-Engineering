/* ROM address: 0x0002e840; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002ecf8 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0002e840(void)

{
  undefined4 uVar1;
  undefined4 local_c;
  char cStack_8;
  
  cStack_8 = FUN_0005c56c((int)DAT_ffffbd68);
  ref_setSR_PARAM(&local_c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff76c,0x80,cStack_8 == '\x01');
  uVar1 = FUN_00002064(local_c);
  return uVar1;
}


