/* ROM address: 0x0002f266; body bytes: 42; decompiled */

void FUN_0002f266(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0002f2ac();
  FUN_0002f51a();
  FUN_0002f65c();
  ref_setFanOutputGPIO();
  ref_setSR(uVar1);
  return;
}


