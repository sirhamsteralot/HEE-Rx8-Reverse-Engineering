/* ROM address: 0x00019aa0; body bytes: 72; decompiled */

void FUN_00019aa0(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0001a614();
  candidate_apv_position_voltage_scale();
  ref_getApvVoltageRange();
  ref_calculateCruiseControlSwitchVolt();
  FUN_0002be40();
  ref_setGearBools();
  FUN_0002c15a();
  ref_calculateGearRPMbased();
  FUN_0002c3b2();
  ref_setSR(uVar1);
  return;
}


