/* ROM address: 0x0002e6ec; body bytes: 30; decompiled */

void FUN_0002e6ec(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0002e0b6();
  FUN_0002e080();
  ref_setSR(uVar1);
  return;
}


