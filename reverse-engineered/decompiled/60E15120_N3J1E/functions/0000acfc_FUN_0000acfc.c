/* ROM address: 0x0000acfc; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000acfc (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000acfc(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x90);
  if (DAT_ffffa207 != -1) {
    DAT_ffffa207 = DAT_ffffa207 + '\x01';
  }
  FUN_0000ad40();
  ref_setSR(uVar1);
  return;
}


