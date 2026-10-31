/* ROM address: 0x00007088; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007088 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00007088(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff74e,0x100,1);
  uVar1 = FUN_00002064(local_8[0]);
  return uVar1;
}


