/* ROM address: 0x00039ca8; body bytes: 72; decompiled */

void FUN_00039ca8(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0004e736();
  FUN_0004f98c();
  FUN_00051c7e();
  FUN_00053466();
  FUN_0005356e();
  FUN_0003b906();
  FUN_0003b854();
  FUN_0003c8fc();
  FUN_0003d3a2();
  ref_setSR(uVar1);
  return;
}


