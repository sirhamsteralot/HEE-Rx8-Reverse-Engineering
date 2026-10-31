/* ROM address: 0x0002f890; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002fd48 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0002f890(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  if (DAT_ffffbdd8 == '\x01') {
    ref_setRegister_REG_BIT_VAL(0xfffff754,4,1);
  }
  else {
    ref_setRegister_REG_BIT_VAL(0xfffff754,4,0);
  }
  uVar1 = FUN_00002064(local_8[0]);
  return uVar1;
}


