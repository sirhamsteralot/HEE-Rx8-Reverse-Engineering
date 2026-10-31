/* ROM address: 0x00019950; body bytes: 132; decompiled */

void FUN_00019950(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0004adc4();
  FUN_0000e1b8();
  update_injectors_off_flag();
  FUN_0001adb8();
  FUN_0001a5d8();
  FUN_0001a600();
  FUN_00024fda();
  FUN_00024ff0();
  FUN_00025614();
  FUN_0002561e();
  ref_filterBatteryVoltage();
  FUN_000268dc();
  FUN_000268f8();
  FUN_00026908();
  FUN_0001a686();
  ref_fuelingRealtedInitalVals__();
  FUN_0001a7b4();
  FUN_0001aa98();
  FUN_0001ac00();
  ref_setSR(uVar1);
  return;
}


