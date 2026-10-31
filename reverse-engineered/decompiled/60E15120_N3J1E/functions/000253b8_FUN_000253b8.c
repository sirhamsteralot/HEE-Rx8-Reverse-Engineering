/* ROM address: 0x000253b8; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025c40 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000253b8(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_000252ae();
  ref_setSR(uVar1);
  return;
}


