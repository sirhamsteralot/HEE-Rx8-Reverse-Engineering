/* ROM address: 0x00016f98; body bytes: 30; decompiled */

void FUN_00016f98(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00017dec();
  FUN_00017eb8();
  ref_setSR(uVar1);
  return;
}


