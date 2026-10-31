/* ROM address: 0x000288f4; body bytes: 60; decompiled */

void FUN_000288f4(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00028ae4();
  FUN_000447b4();
  FUN_00026a10();
  FUN_00044974();
  FUN_000443f4();
  FUN_00044ae4();
  FUN_00044558();
  ref_setSR(uVar1);
  return;
}


