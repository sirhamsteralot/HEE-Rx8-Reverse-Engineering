/* ROM address: 0x0003eb3a; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003f0d6 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_catTempRelated(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0003e39e();
  FUN_0003e560();
  FUN_0003e7b6();
  ref_setSR(uVar1);
  return;
}


