/* ROM address: 0x00038ee4; body bytes: 90; decompiled */

void FUN_00038ee4(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00046d9a();
  FUN_00046f38();
  FUN_000461dc();
  FUN_0004621c();
  FUN_0004556c();
  FUN_000455bc();
  FUN_00046392();
  FUN_00046404();
  FUN_00046fae();
  FUN_00046fee();
  FUN_00046aca();
  FUN_00046b24();
  ref_setSR(uVar1);
  return;
}


