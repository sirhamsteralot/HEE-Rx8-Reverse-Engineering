/* ROM address: 0x0003176e; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00031c16 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0003176e(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_getEngineOffTimer();
  ref_setSR(uVar1);
  return;
}


