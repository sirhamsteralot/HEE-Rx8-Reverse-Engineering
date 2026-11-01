/* ROM address: 0x0003232e; body bytes: 36; decompiled */

void secondary_air_on_time_task(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  FUN_0003252e();
  FUN_00032608();
  secondary_air_pump_control();
  FUN_00003934(uVar1);
  return;
}


