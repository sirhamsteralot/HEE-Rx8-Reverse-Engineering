/* ROM address: 0x0002377a; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00023fee (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002377a(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_000242ae();
  ref_setSR(uVar1);
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_000244bc();
  ref_setSR(uVar1);
  return;
}


