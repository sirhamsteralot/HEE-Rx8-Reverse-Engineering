/* [ADDITIONAL SOURCE REVIEW]
 * misfire_monitor_tick [high]: Per-crank-tick misfire pass, SR-masked (jsr 0x3920 at 0x287b0, tail jmp @r3 at 0x28994 to the SR restore): 44 jsr calls in body 0x287aa-0x288be in the order 0x2711a, 0x26940, 0x26982, 0x280be, 0x28118, 0x28198, 0x2842c, 0x44a78, 0x44a9e, 0x26934, 0x2853c, 0x28648, 0x26bda, 0x26d04, 0x26d5c, 0x26d70, 0x26f38, 0x26fc0, 0x28b10, 0x28b50, 0x271b0, 0x27306, 0x27390, 0x273d4, 0x27520, 0x276ec, 0x2837c, 0x27fb4, 0x28022, 0x447e2, 0x4489c, 0x4493a, 0x26a42, 0x26aa0, 0x4499c, 0x449e4, 0x44a1e, 0x4441e, 0x44436, 0x44b16, 0x44b46, 0x4458a, 0x445ba (pool-resolved targets verified in the disassembly). Called from crank_tick_message_handler 0x11c98 (group-1 rec[9] @ ROM 0xd98c, posted by 0xcf96 via 0xa156).
 */
/* ROM address: 0x000287aa; body bytes: 276; decompiled */

void misfire_monitor_tick(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  e2ram_learned_table_cell_index();
  misfire_sector_ring_copy();
  sector_parity_latch();
  misfire_high_rpm_flag();
  misfire_sector_counter();
  e2ram_learned_table_apply();
  misfire_deviation_delay_line();
  misfire_threshold_rpm_lookup();
  misfire_threshold_load_lookup();
  candidate_misfire_aux_pool_update();
  misfire_threshold_a_calc();
  misfire_threshold_b_calc();
  candidate_misfire_load_delta_gate();
  candidate_misfire_persistence_count();
  misfire_load_floor_lookup();
  misfire_enable_window();
  candidate_misfire_fault_persistence();
  misfire_supply_gate();
  misfire_window_400_tick();
  misfire_window_2000_tick();
  e2ram_learned_table_learn_gate();
  candidate_misfire_learn_hold_decay();
  candidate_misfire_ol_fuel_gate();
  candidate_misfire_sustained_gate();
  misfire_learn_steady_state();
  e2ram_learned_table_cell_learn();
  candidate_e2ram_learned_table_correction_filter();
  misfire_event_arm();
  misfire_event_arm_secondary();
  misfire_threshold_check_rpm();
  misfire_threshold_check_load();
  misfire_counter_delay();
  misfire_event_count();
  misfire_window_snapshot();
  misfire_count_floor_lookup();
  candidate_misfire_load_ceiling_lookup();
  candidate_misfire_high_rpm_latch();
  misfire_type_count_lookup();
  misfire_sustained_window();
  candidate_misfire_400_threshold();
  misfire_dtc_evaluate_400();
  misfire_2000_threshold();
  misfire_dtc_evaluate();
  ref_setSR(uVar1);
  return;
}


