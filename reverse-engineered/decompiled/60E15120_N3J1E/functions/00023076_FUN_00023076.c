/* ROM address: 0x00023076; body bytes: 30; decompiled */

void FUN_00023076(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00023190();
  FUN_00025216();
  ref_setSR(uVar1);
  return;
}


