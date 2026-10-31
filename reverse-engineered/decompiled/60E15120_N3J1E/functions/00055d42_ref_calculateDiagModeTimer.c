/* ROM address: 0x00055d42; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005405e (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_calculateDiagModeTimer(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if ((DAT_ffffd1d4 == '\x01') && (DAT_ffffd1d2 < 0x271)) {
    DAT_ffffd1d2 = DAT_ffffd1d2 + 1;
  }
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


