/* ROM address: 0x00019cf4; body bytes: 48; decompiled */

void FUN_00019cf4(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_filterVehicleSpeed();
  ref_calculateVehicleAccel();
  ref_filterVehicleAccel();
  FUN_0003365a();
  knock_state_reset_rpm_window();
  ref_setSR(uVar1);
  return;
}


