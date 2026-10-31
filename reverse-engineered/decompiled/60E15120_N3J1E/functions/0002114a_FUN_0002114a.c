/* ROM address: 0x0002114a; body bytes: 60; decompiled */

void FUN_0002114a(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0004afd6();
  FUN_0000e4f4();
  FUN_0000e910();
  FUN_0001de6c();
  FUN_00020656();
  FUN_000207b2();
  FUN_0002090a();
  ref_setSR(uVar1);
  return;
}


