/* ROM address: 0x00021b4c; body bytes: 36; decompiled */

void FUN_00021b4c(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00021970();
  ref_throttlePlateControl_Related();
  ref_getThrottleBasedTorque_Related();
  ref_setSR(uVar1);
  return;
}


