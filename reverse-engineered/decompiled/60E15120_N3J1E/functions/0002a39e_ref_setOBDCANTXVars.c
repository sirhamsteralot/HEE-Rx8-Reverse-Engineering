/* ROM address: 0x0002a39e; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002aaf2 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setOBDCANTXVars(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_getOBDCANTXVars1();
  ref_getOBDCANTXVars2();
  ref_setSR(uVar1);
  return;
}


