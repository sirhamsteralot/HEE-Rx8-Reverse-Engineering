/* ROM address: 0x0005674a; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00054a66 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_runImmoRelatedCounter(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if ((DAT_ffffd1e4 == '\x01') && (DAT_ffffd1e2 != -1)) {
    DAT_ffffd1e2 = DAT_ffffd1e2 + 1;
  }
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


