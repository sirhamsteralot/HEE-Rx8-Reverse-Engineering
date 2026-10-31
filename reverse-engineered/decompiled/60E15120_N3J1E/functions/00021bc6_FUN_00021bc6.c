/* ROM address: 0x00021bc6; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00022532 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00021bc6(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0004b3a8();
  FUN_0004b210();
  ref_setSR(uVar1);
  return;
}


