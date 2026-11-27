/* [ADDITIONAL SOURCE REVIEW]
 * fueling_main_task [high]: Task body behind ref_engineControlTASK 0x11ba4. Cranking-relevant order: 0x30274 at 0x20e5c, 0x302a2 at 0x20e62, 0x303f2 at 0x20e68, cranking_pulse_adder 0x30678 at 0x20e6e, 0x30228 at 0x20e74, then 0x306e8/0x30948/0x30b08 and injector_pulse_time_arbitrate 0x2fea8 at 0x20f08.
 */
/* ROM address: 0x00020e40; body bytes: 328; decompiled */

void fueling_main_task(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_UnknownFueling1_0000e454();
  injection_angle_limit_lookup();
  candidate_cranking_pulse_width_lookup();
  FUN_000302a2();
  FUN_000303f2();
  cranking_pulse_adder();
  candidate_cranking_pulse_product();
  FUN_0000eefa();
  FUN_00034364();
  plate_range_high_fault();
  FUN_000341be();
  FUN_00034050();
  FUN_00034126();
  load_delta_enrichment();
  FUN_00034230();
  FUN_00033d5e();
  FUN_00033cd0();
  FUN_00033c10();
  FUN_00033ba4();
  FUN_00033dc8();
  ref_setSR(uVar1);
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0002fdb0();
  FUN_0002fe00();
  FUN_0002fe1e();
  ref_coolantTempSubtractorsForCatModel();
  calc_fuel_volume_request();
  calculate_fuel_amount_per_rotation();
  primary_secondary_fuel_split();
  split_pulse_time_output();
  FUN_00030030();
  injector_pulse_time_arbitrate();
  cold_start_enrichment();
  FUN_0004af14();
  FUN_0004b190();
  ref_setSR(uVar1);
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0001c384();
  FUN_0001d5c2();
  closed_loop_enable_condition();
  FUN_0001d2e2();
  FUN_0001cc34();
  FUN_0001d3da();
  FUN_0001c880();
  FUN_0002c66c();
  FUN_0002c774();
  FUN_0002c90c();
  FUN_0002c9ca();
  FUN_0002ca8e();
  FUN_0000f31c();
  FUN_0000ff98();
  ref_setSR(uVar1);
  return;
}


