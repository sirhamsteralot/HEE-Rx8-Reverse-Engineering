/* ROM address: 0x000394ee; body bytes: 78; decompiled */

void FUN_000394ee(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0003828a();
  FUN_0003820e();
  FUN_0003836a();
  FUN_000385c6();
  FUN_00038628();
  FUN_0003898a();
  FUN_000385de();
  FUN_0003fa18();
  FUN_000453f4();
  FUN_00044de0();
  ref_setSR(uVar1);
  return;
}


