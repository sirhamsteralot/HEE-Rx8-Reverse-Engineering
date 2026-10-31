/* ROM address: 0x00022f86; body bytes: 240; decompiled */

void FUN_00022f86(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00033040();
  FUN_00033138();
  FUN_000475f8();
  FUN_00047610();
  FUN_00047704();
  FUN_00047818();
  FUN_00047cce();
  FUN_00047cd8();
  FUN_00047d9c();
  FUN_000481d2();
  FUN_00048202();
  FUN_00048484();
  FUN_000486de();
  FUN_0004876c();
  FUN_00048cc0();
  FUN_000487d6();
  FUN_00048c7a();
  FUN_00048d38();
  FUN_00048d70();
  FUN_00048e4c();
  FUN_00048ecc();
  FUN_00048fe8();
  FUN_00049052();
  FUN_00049080();
  ref_setSR(uVar1);
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_000474fc();
  FUN_00022f1c();
  FUN_00048558();
  FUN_00022db4();
  FUN_000233ec();
  FUN_000231f0();
  FUN_00023558();
  ref_calculateThrottlePedalPositionMapBased();
  FUN_00022a14();
  FUN_00022d26();
  FUN_000251d0();
  ref_setSR(uVar1);
  return;
}


