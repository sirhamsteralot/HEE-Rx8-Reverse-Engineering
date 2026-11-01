/* ROM address: 0x00032804; body bytes: 48; decompiled */

void apv_control_task(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  FUN_00032850();
  apv_position_voltage_counter();
  apv_counter_calc();
  FUN_00032b16();
  apv_command_wrapper();
  FUN_00003934(uVar1);
  return;
}


