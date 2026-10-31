/* ROM address: 0x00021106; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021a72 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00021106(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0000f91e(param_1);
  ref_setSR(uVar1);
  return;
}


