/* ROM address: 0x0002e5c6; body bytes: 204; decompiled */

void FUN_0002e5c6(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  gear_float_band_producer();
  FUN_0002d1d4();
  FUN_0002d280();
  FUN_0002d318();
  ref_cruiseControlOvershootPlausibilityMon();
  ref_getCruiseControlAllowedBool__();
  FUN_0002d586();
  ref_cruiseControllAccelResCheck__();
  FUN_000321f4();
  FUN_000322a8();
  ref_debounceCruiseControlSET();
  ref_debounceCruiseControlACCELRES();
  FUN_0003242c();
  cruise_set_speed_latch();
  FUN_0003290c();
  FUN_000329fc();
  FUN_0002d5e4();
  cruise_control_output_law();
  cruise_set_speed_adjust_integrator();
  cruise_set_speed_apply();
  FUN_0002dfd6();
  FUN_0002e2cc();
  FUN_0002cf48();
  FUN_0002cf6a();
  FUN_0002d07e();
  FUN_0002d188();
  FUN_0002e33c();
  FUN_0002e3dc();
  FUN_0002e54e();
  FUN_0004dd46();
  FUN_0004dd82();
  ref_setSR(uVar1);
  return;
}


