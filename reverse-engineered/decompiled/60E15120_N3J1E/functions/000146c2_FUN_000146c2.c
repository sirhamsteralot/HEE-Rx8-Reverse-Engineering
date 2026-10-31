/* ROM address: 0x000146c2; body bytes: 24; decompiled */

void FUN_000146c2(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00010320();
  ref_setSR(uVar1);
  return;
}


