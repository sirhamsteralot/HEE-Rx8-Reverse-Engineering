/* [ADDITIONAL SOURCE REVIEW]
 * dbw_control_batch [high]: DBW control batch from 0x1150e (pool 0x116c8=0x00022f86), mask 0x10 around two call groups: 0x474fc (home offset cc88), 0x22f1c, 0x48558, then 0x22db4, 0x233ec, 0x231f0, 0x23558, 0x228dc, 0x22a14, 0x22d26, relay_hold_output_pd11 0x251d0 (callgraph.tsv rows for caller 00022f86).
 */
/* ROM address: 0x00022f86; body bytes: 240; decompiled */

void dbw_control_batch(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00033040();
  FUN_00033138();
  FUN_000475f8();
  FUN_00047610();
  FUN_00047704();
  FUN_00047818();
  FUN_00047cce();
  FUN_00047cd8();
  FUN_00047d9c();
  FUN_000481d2();
  FUN_00048202();
  FUN_00048484();
  FUN_000486de();
  FUN_0004876c();
  shutdown_allowed_flag();
  engine_stop_conditions_eval();
  FUN_00048c7a();
  candidate_key_voltage_timer_update();
  candidate_voltage_key_sanity_flags();
  FUN_00048e4c();
  FUN_00048ecc();
  FUN_00048fe8();
  FUN_00049052();
  FUN_00049080();
  ref_setSR(uVar1);
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_000474fc();
  FUN_00022f1c();
  FUN_00048558();
  throttle_servo_override();
  throttle_target_plate_position();
  learned_pedal_value_calc();
  throttle_position_delta_calc();
  throttle_pedal_to_plate_request_map();
  pedal_demand_filter_coeffs();
  throttle_base_position_filter();
  relay_hold_output_pd11();
  ref_setSR(uVar1);
  return;
}


