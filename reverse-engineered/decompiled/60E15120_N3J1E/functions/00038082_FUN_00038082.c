/* ROM address: 0x00038082; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000387a2 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00038082(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_000379e4();
  ref_setSR(uVar1);
  return;
}


