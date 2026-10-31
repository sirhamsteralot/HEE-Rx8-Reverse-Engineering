/* ROM address: 0x00026850; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00027174 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00026850(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0002633e();
  ref_setSR(uVar1);
  return;
}


