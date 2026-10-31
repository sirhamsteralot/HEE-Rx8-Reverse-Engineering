/* ROM address: 0x0002a3bc; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002ab10 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002a3bc(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0002aa02();
  ref_setSR(uVar1);
  return;
}


