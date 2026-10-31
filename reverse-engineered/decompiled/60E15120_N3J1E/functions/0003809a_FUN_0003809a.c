/* ROM address: 0x0003809a; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000387ba (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0003809a(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00037fea();
  ref_setSR(uVar1);
  return;
}


