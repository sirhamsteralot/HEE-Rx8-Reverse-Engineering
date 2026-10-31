/* ROM address: 0x000074e0; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000074e0 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000074e0(char param_1)

{
  undefined4 uVar1;
  
  if ((DAT_ffff9fa5 != param_1) && (DAT_ffff9fa5 = param_1, param_1 == '\x01')) {
    uVar1 = sh_raise_interrupt_mask_return_previous(0xb0);
    FUN_0000765a();
    ref_setSR(uVar1);
    return;
  }
  return;
}


