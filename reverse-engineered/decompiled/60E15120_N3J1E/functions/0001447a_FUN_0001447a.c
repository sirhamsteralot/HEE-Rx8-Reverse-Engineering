/* ROM address: 0x0001447a; body bytes: 42; decompiled */

void FUN_0001447a(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_000128ac();
  FUN_00012c22();
  FUN_00012cd6();
  FUN_000129c0();
  ref_setSR(uVar1);
  return;
}


