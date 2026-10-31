/* ROM address: 0x0002224e; body bytes: 42; decompiled */

void FUN_0002224e(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00022294();
  FUN_000223b4();
  FUN_00022510();
  FUN_0002549e();
  ref_setSR(uVar1);
  return;
}


