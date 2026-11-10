/* [ADDITIONAL SOURCE REVIEW]
 * fueling_main_task [high]: Called from ref_engineControlTASK 0x11ba4; three masked blocks: enrichments + injection_angle_limit_lookup (0xe48e) + load_delta_enrichment (0x33ec4) + cranking_pulse_adder (0x30678); fuel core: calc_fuel_volume_request (0x306e8), calculate_fuel_amount_per_rotation (0x30948), injector_pulse_time_arbitrate (0x2fea8), cold_start_enrichment (0x1ddfc); closed-loop conditions (0x1c13c chain).
 */
/* ROM address: 0x00020e40; body bytes: 328; decompiled */

void fueling_main_task(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_UnknownFueling1_0000e454();
  injection_angle_limit_lookup();
  FUN_00030274();
  FUN_000302a2();
  FUN_000303f2();
  cranking_pulse_adder();
  FUN_00030228();
  FUN_0000eefa();
  FUN_00034364();
  ref_getThrottlePositionFault__();
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
  FUN_00030b08();
  FUN_00030f5c();
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


