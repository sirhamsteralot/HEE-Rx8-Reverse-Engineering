/* ROM address: 0x00025438; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025cc0 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00025438(void)

{
  undefined4 local_14;
  short sStack_10;
  
  sStack_10 = rx8_mul_s32_shift16_saturate(0,0x100);
  ref_setSR_PARAM(&local_14,0xe0);
  DAT_ffff9f52 = 0;
  DAT_ffff9f5c = 0;
  DAT_ffff9f5a = sStack_10;
  DAT_ffff9f56 = 0x100;
  DAT_ffff9f58 = sStack_10;
  DAT_ffff9f54 = 0x100;
  if (sStack_10 == 0) {
    ref_setRegister_REG_BIT_VAL(0xfffff746,0x10,0);
  }
  else {
    ref_setRegister_REG_BIT_VAL(0xfffff746,0x10,1);
  }
  FUN_00002064(local_14);
  return;
}


