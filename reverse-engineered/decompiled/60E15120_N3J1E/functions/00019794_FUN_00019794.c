/* ROM address: 0x00019794; body bytes: 42; decompiled */

void FUN_00019794(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0000e07a((int)param_1);
  FUN_0001a13c();
  FUN_0001a086();
  ref_setSR(uVar1);
  return;
}


