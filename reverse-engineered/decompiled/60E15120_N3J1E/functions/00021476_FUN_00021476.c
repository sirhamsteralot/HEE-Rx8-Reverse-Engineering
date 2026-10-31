/* ROM address: 0x00021476; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021de2 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00021476(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0002fe4e();
  ref_setSR(uVar1);
  return;
}


