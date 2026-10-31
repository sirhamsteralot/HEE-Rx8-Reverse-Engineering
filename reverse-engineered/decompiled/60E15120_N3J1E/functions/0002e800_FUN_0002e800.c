/* ROM address: 0x0002e800; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002ecb8 (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0002e800(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  if (DAT_ffffbd68 == '\x01') {
    ref_setRegister_REG_BIT_VAL(0xfffff76c,0x80);
  }
  else {
    ref_setRegister_REG_BIT_VAL(0xfffff76c,0x80,0);
  }
  uVar1 = FUN_00002064(local_8[0]);
  return uVar1;
}


