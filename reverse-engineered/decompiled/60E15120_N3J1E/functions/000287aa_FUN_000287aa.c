/* ROM address: 0x000287aa; body bytes: 276; decompiled */

void FUN_000287aa(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  e2ram_learned_table_cell_index();
  FUN_00026940();
  FUN_00026982();
  FUN_000280be();
  FUN_00028118();
  e2ram_learned_table_apply();
  misfire_deviation_delay_line();
  misfire_threshold_rpm_lookup();
  misfire_threshold_load_lookup();
  FUN_00026934();
  FUN_0002853c();
  FUN_00028648();
  FUN_00026bda();
  FUN_00026d04();
  FUN_00026d5c();
  FUN_00026d70();
  FUN_00026f38();
  FUN_00026fc0();
  FUN_00028b10();
  FUN_00028b50();
  e2ram_learned_table_learn_gate();
  FUN_00027306();
  FUN_00027390();
  FUN_000273d4();
  FUN_00027520();
  e2ram_learned_table_cell_learn();
  candidate_e2ram_learned_table_correction_filter();
  misfire_event_arm();
  misfire_event_arm_secondary();
  misfire_threshold_check_rpm();
  misfire_threshold_check_load();
  FUN_0004493a();
  misfire_event_count();
  FUN_00026aa0();
  FUN_0004499c();
  FUN_000449e4();
  FUN_00044a1e();
  FUN_0004441e();
  misfire_sustained_window();
  FUN_00044b16();
  FUN_00044b46();
  FUN_0004458a();
  misfire_dtc_evaluate();
  ref_setSR(uVar1);
  return;
}


