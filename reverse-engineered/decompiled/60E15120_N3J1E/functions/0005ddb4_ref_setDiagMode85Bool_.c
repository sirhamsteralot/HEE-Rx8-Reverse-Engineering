/* ROM address: 0x0005ddb4; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005c5a4 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_setDiagMode85Bool_(void)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  cVar2 = FUN_0005de3c();
  if ((cVar2 == '\0') && (DAT_ffffd378 == '\x01')) {
    ref_setDiagMode85Bool2(1);
  }
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


