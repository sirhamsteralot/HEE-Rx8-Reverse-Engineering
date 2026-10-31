/* ROM address: 0x0002e5a8; body bytes: 30; decompiled */

void FUN_0002e5a8(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_cruiseControlStateStuff();
  FUN_0002e15e();
  ref_setSR(uVar1);
  return;
}


