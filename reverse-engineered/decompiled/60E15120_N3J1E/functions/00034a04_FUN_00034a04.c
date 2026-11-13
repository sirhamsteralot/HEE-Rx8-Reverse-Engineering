/* ROM address: 0x00034a04; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035124 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00034a04(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  e2ram_immo_key_read();
  FUN_0003583c();
  FUN_0000e2d4(1);
  ref_setSR(uVar1);
  return;
}


