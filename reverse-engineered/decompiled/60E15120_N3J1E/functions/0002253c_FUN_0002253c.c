/* ROM address: 0x0002253c; body bytes: 36; decompiled */

void FUN_0002253c(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00022574();
  FUN_00022630();
  FUN_00025198();
  ref_setSR(uVar1);
  return;
}


