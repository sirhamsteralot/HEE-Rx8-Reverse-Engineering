/* ROM address: 0x0005bb92; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005a382 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005bb92(void)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  cVar2 = FUN_0005bc2c();
  if ((cVar2 == '\0') && (DAT_ffffd30c == '\x01')) {
    FUN_0005bbc6(0);
  }
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


