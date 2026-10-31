/* ROM address: 0x0000759e; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000759e (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000759e(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0xb0);
  ref_setInterruptTimer();
  FUN_00007eca();
  ref_setSR(uVar1);
  return;
}


