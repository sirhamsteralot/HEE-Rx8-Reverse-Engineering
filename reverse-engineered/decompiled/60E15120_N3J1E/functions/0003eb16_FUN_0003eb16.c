/* ROM address: 0x0003eb16; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003f0b2 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0003eb16(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0003e364();
  ref_coolantTempModelBooleans();
  ref_getCatTempConditional2();
  ref_setSR(uVar1);
  return;
}


