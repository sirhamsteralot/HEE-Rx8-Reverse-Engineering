/* ROM address: 0x0002a374; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002aac8 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002a374(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0002aa46();
  FUN_0002aa62();
  FUN_0002aa88();
  FUN_0002ae7c();
  ref_setSR(uVar1);
  return;
}


