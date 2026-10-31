/* ROM address: 0x0002a290; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002a9e4 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002a290(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_can216RXTimer();
  FUN_00028e1a();
  ref_setSR(uVar1);
  return;
}


