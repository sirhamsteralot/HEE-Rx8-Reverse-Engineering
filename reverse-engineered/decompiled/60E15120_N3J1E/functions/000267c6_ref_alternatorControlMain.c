/* ROM address: 0x000267c6; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000270ea (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_alternatorControlMain_000267c6(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00025a22();
  FUN_00025a3c();
  FUN_00025a68();
  FUN_00025b36();
  FUN_00025ba4();
  FUN_0002616e();
  ref_calculateAlternatorDiagDCOutput();
  ref_calculateOutputforAlternator();
  FUN_000545bc();
  ref_setSR(uVar1);
  return;
}


