/* ROM address: 0x0002894e; body bytes: 24; decompiled */

void FUN_0002894e(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00026f9e();
  ref_setSR(uVar1);
  return;
}


