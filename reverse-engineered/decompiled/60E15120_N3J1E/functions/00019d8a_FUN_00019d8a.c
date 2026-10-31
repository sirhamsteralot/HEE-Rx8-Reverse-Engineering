/* ROM address: 0x00019d8a; body bytes: 24; decompiled */

void FUN_00019d8a(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_getMaxLoadCompensations();
  ref_setSR(uVar1);
  return;
}


