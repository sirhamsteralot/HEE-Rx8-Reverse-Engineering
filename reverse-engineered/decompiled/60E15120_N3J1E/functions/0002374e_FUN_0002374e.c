/* ROM address: 0x0002374e; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00023fc2 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002374e(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_000235f8();
  ref_setSR(uVar1);
  return;
}


