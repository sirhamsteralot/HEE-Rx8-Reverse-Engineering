/* ROM address: 0x00039b08; body bytes: 90; decompiled */

void FUN_00039b08(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00050950();
  FUN_00051982();
  FUN_00052256();
  FUN_0005243a();
  FUN_000526d8();
  FUN_0004e566();
  FUN_0005187c();
  FUN_00041964();
  FUN_00041b32();
  FUN_00041bd4();
  FUN_00041d20();
  FUN_00041fb8();
  ref_setSR(uVar1);
  return;
}


