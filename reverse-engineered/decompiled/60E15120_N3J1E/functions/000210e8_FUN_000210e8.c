/* ROM address: 0x000210e8; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021a54 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000210e8(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0000f29c();
  FUN_0000f8d0();
  ref_setSR(uVar1);
  return;
}


