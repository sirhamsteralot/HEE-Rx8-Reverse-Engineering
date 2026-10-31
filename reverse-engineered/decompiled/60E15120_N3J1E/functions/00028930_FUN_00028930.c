/* ROM address: 0x00028930; body bytes: 30; decompiled */

void FUN_00028930(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00026c3c();
  FUN_00027328();
  ref_setSR(uVar1);
  return;
}


