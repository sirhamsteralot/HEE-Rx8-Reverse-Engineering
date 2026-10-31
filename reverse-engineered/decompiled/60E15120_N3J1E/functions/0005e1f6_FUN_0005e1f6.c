/* ROM address: 0x0005e1f6; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ca02 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005e1f6(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if ((DAT_ffffd386 == '\x01') && (DAT_ffffd384 < 0x271)) {
    DAT_ffffd384 = DAT_ffffd384 + 1;
  }
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


