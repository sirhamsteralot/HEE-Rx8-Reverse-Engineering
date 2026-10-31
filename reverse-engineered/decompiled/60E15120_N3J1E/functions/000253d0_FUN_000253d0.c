/* ROM address: 0x000253d0; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025c58 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000253d0(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_000252b8();
  ref_setSR(uVar1);
  return;
}


