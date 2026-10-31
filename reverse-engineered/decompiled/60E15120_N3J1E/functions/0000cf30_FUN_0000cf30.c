/* ROM address: 0x0000cf30; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000cf30 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000cf30(undefined1 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0xb0);
  DAT_ffffa3d6 = param_1;
  DAT_ffffa3d7 = param_2;
  ref_setSR(uVar1);
  return;
}


