/* ROM address: 0x00026868; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002718c (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_alternatorControlMain_00026868(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00025c6c();
  ref_setSR(uVar1);
  return;
}


