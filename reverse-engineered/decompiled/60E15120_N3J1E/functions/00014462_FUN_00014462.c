/* ROM address: 0x00014462; body bytes: 24; decompiled */

void FUN_00014462(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0001077a();
  ref_setSR(uVar1);
  return;
}


