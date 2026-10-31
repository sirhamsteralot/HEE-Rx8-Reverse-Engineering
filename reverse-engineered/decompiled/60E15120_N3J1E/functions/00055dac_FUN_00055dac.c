/* ROM address: 0x00055dac; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000540c8 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00055dac(void)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  cVar2 = FUN_00055e3e(0);
  if ((cVar2 == '\x01') && (cVar2 = FUN_0005632a(), cVar2 == '\0')) {
    ref_runSubfunction__(0);
  }
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


