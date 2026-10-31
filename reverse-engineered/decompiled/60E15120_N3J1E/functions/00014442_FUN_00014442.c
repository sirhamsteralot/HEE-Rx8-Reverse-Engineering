/* ROM address: 0x00014442; body bytes: 32; decompiled */

void FUN_00014442(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00010b38(0);
  FUN_00010772();
  ref_setSR(uVar1);
  return;
}


