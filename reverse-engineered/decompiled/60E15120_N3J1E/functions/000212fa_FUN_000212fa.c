/* ROM address: 0x000212fa; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021c66 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000212fa(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0001fb4c();
  FUN_0003432a();
  ref_setSR(uVar1);
  return;
}


