/* ROM address: 0x0000be30; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000be30 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000be30(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_c;
  undefined4 uStack_8;
  
  uStack_8 = param_1;
  FUN_0000bf3a();
  FUN_0000bfa0(uStack_8,2);
  ref_setSR_PARAM(&local_c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff74e,0x400,0);
  uVar1 = FUN_00002064(local_c);
  return uVar1;
}


