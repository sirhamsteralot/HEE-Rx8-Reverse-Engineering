/* ROM address: 0x000214aa; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021e16 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000214aa(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0000f450();
  ref_setSR(uVar1);
  return;
}


