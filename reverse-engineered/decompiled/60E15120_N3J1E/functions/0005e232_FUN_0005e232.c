/* ROM address: 0x0005e232; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ca3e (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005e232(void)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  cVar2 = FUN_0005e2d8();
  if ((cVar2 == '\0') && (DAT_ffffd387 == '\x01')) {
    FUN_00059390();
    DAT_ffffd387 = '\0';
  }
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


