/* ROM address: 0x00021434; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021da0 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00021434(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00030468();
  FUN_000189f8();
  FUN_00018aea();
  FUN_00018db8();
  ref_setSR(uVar1);
  return;
}


