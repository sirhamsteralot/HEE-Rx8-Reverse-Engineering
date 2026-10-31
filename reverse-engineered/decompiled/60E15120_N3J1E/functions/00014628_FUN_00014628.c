/* ROM address: 0x00014628; body bytes: 54; decompiled */

void FUN_00014628(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00017f20();
  FUN_00017fc6();
  FUN_000180c8();
  FUN_0001805c();
  FUN_000436a6();
  FUN_000437d2();
  ref_setSR(uVar1);
  return;
}


