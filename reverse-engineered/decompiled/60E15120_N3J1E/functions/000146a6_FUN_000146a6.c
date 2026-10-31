/* ROM address: 0x000146a6; body bytes: 16; decompiled */

void FUN_000146a6(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_setSR(uVar1);
  return;
}


