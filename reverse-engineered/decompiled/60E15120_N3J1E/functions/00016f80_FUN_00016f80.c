/* ROM address: 0x00016f80; body bytes: 24; decompiled */

void FUN_00016f80(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00017bec();
  ref_setSR(uVar1);
  return;
}


