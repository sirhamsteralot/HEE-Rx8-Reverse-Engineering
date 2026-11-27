/* [ADDITIONAL SOURCE REVIEW]
 * ignition_timing_main_task [high]: Task body called from ref_engineControlTASK 0x11ba4 at 0x11bbe. Cranking-relevant order: cranking state 0x1481c at 0x142b0, base timing 0x11f00 at 0x142b6, timing filters 0x43934/0x439b2 at 0x14328/0x1432e, blends 0x123da at 0x143d6 and 0x124d6 at 0x143f4. It contains no call to idle_base_timing_select 0x14100.
 */
/* ROM address: 0x000142a4; body bytes: 414; decompiled */

void ignition_timing_main_task(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_getEngineCrankingState__();
  leading_base_timing_calc();
  trailing_base_timing_calc();
  knock_enable_gate();
  knock_sensor_health_gate();
  knock_active_gate();
  knock_retard_learn_to_eeprom();
  knock_retard_attack();
  ref_setSR(uVar1);
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  idle_leading_timing_error_correction();
  idle_trailing_timing_error_correction();
  FUN_00013c7c();
  FUN_00013da0();
  coolant_timing_derate_calc();
  FUN_00013e3e();
  FUN_00012938();
  FUN_00012dec();
  timing_trim_scale_calc();
  dsc_timing_derate_select();
  cranking_timing_leading_filter();
  cranking_timing_trailing_filter();
  ref_calculateDriverConditions();
  FUN_00042ca8();
  ref_vehicleSpeedRelatedSOmething();
  ref_throttleLiftCountersandConditions();
  FUN_000438ca();
  FUN_00042d00();
  FUN_00042d6e();
  ref_setLoadandRPM();
  FUN_00042eb6();
  ref_engineLoad2ndOrderLowPass();
  FUN_0004301e();
  FUN_00042f84();
  ref_calculatedEngineAccelerationFiltered();
  ref_getEngineSpeedRateOfChange();
  FUN_000431ba();
  FUN_0004331e();
  ref_relatedToFuelCut_();
  FUN_00043722();
  FUN_000433c2();
  FUN_000434ac();
  FUN_000434d4();
  FUN_00043560();
  FUN_0004359a();
  FUN_000435c8();
  FUN_0004363c();
  min_advance_clamp_select();
  knock_retard_apply_leading();
  leading_timing_cranking_blend();
  leading_timing_add_corrections();
  leading_final_timing_clamp_output();
  FUN_00012754();
  knock_retard_apply_trailing();
  trailing_timing_cranking_blend();
  trailing_timing_add_corrections();
  trailing_final_timing_clamp_output();
  ref_finalLeadingTimingStuff_();
  ref_finalTrailingTimingStuff_();
  ref_setPerRotorTimingValuesLeading();
  ref_setPerRotorTimingValuesTrailing();
  jump_to_FUN_00010fa8();
  FUN_00010ea2();
  FUN_0002bd4c();
  FUN_0002bdae();
  FUN_0004c6a4();
  ref_setSR(uVar1);
  return;
}


