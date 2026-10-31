/* ROM address: 0x00028966; body bytes: 24; decompiled */

void FUN_00028966(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00027444();
  ref_setSR(uVar1);
  return;
}


