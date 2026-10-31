/* ROM address: 0x0002f122; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002f5da (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_acCompressorControlMain___(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0002eb1c();
  FUN_0002ebda();
  FUN_0002f04c();
  FUN_0002f0c6();
  FUN_0002e9a4();
  ref_calculateACClutchOn__();
  FUN_0002e840();
  ref_setSR(uVar1);
  return;
}


