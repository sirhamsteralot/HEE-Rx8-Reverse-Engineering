/* ROM address: 0x00039d60; body bytes: 24; decompiled */

void FUN_00039d60(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_resetFuelCutCondition7();
  ref_setSR(uVar1);
  return;
}


