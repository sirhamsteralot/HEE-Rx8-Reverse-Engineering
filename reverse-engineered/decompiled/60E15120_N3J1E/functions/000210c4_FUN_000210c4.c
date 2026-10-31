/* ROM address: 0x000210c4; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021a30 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000210c4(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0000ff10();
  FUN_0000f2ac();
  FUN_0000f8c8();
  ref_setSR(uVar1);
  return;
}


