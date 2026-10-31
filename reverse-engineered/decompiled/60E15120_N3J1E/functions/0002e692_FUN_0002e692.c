/* ROM address: 0x0002e692; body bytes: 90; decompiled */

void FUN_0002e692(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0004c828();
  FUN_0004c896();
  FUN_0004dece();
  FUN_0004c8c4();
  FUN_0004c9b2();
  FUN_0004dce8();
  FUN_0004dec0();
  FUN_0004ca7e();
  FUN_0004d4a6();
  FUN_0004d700();
  FUN_0004db22();
  FUN_0004dc9e();
  ref_setSR(uVar1);
  return;
}


