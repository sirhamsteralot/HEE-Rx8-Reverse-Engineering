/* ROM address: 0x0002a248; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002a99c (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002a248(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_checkCANsomethingKeyOnBased();
  FUN_000547d8();
  ref_setSR(uVar1);
  return;
}


