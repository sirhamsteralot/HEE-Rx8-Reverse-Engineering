/* ROM address: 0x0002680e; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00027132 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_alternatorControl(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_000257b4();
  FUN_0002590a();
  FUN_00025aa0();
  FUN_0002635c();
  FUN_000264f0();
  ref_setAlternatorWarningLight();
  FUN_00054590();
  FUN_000545a6();
  ref_setSR(uVar1);
  return;
}


