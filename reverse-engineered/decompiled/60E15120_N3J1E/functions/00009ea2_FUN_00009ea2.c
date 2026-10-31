/* ROM address: 0x00009ea2; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009ea2 (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00009ea2(void)

{
  ushort uVar1;
  undefined4 local_4;
  
  ref_setSR_PARAM(&local_4,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff74e,8,0);
  FUN_00002064(local_4);
  do {
    do {
      sh_busy_wait_count_times_8(5000);
      FUN_0000a850();
      uVar1 = PFDR_W;
    } while ((uVar1 & 1) == 0);
    ref_whileLoop();
  } while( true );
}


