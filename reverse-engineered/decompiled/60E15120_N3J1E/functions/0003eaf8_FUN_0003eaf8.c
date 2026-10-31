/* ROM address: 0x0003eaf8; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003f094 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0003eaf8(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_getCatTempConditional();
  ref_getCatTempInRange();
  ref_setSR(uVar1);
  return;
}


