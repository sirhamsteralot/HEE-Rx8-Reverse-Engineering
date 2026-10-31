/* ROM address: 0x00016fb6; body bytes: 24; decompiled */

void FUN_00016fb6(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00017d10();
  ref_setSR(uVar1);
  return;
}


