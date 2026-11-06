/* [ADDITIONAL SOURCE REVIEW]
 * idle_control_calc_batch [high]: 28-call batch (27 jsr + 1 tail jmp in the 174-byte body) under interrupt mask 0x10, called from task[10] body 0x11744 (task rec[10].entry thunk 0x64f6 at ROM 0x4a38). First jsr 0x167c6 -> 0x3920 sh_raise_interrupt_mask_return_previous with r4=0x10; callees via pool 0x16888-0x168fc (classified mixed_pool) words read from ROM: 0x1688c=0x148a4, 0x16890=0x16748, 0x16894=0x16358, 0x16898=0x16900, 0x1689c=0x148c4, 0x168a0=0x15f5c, 0x168a4=0x14944, 0x168a8=0x14baa, 0x168ac=0x1506c idle_target_rpm_calculate, 0x168b0=0x14d10, 0x168b4=0x14f6c, 0x168b8=0x16432, 0x168bc=0x165d6, 0x168c0=0x16672, 0x168c4=0x15ffc, 0x168c8=0x1617e, 0x168cc=0x15fa0, 0x168d0=0x15a40, 0x168d4=0x16380, 0x168d8=0x16720, 0x168dc=0x3337c, 0x168e0=0x3354e, 0x168e4=0x34650, 0x168e8=0x34814, 0x168ec=0x15a9a, 0x168f0=0x216f8; tail jmp 0x1686a -> 0x3934 ref_setSR. Callee set is the idle air/target/trim chain (inherited name confirmed).
 */
/* ROM address: 0x000167c0; body bytes: 174; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000165c4 (174 bytes). Names prefixed ref_
   are inherited hypotheses. */

void idle_control_calc_batch(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  candidate_idle_target_term_lookup();
  candidate_idle_ac_load_calc();
  candidate_idle_baro_comp();
  candidate_idle_air_correction_select();
  candidate_idle_maf_airflow_term();
  candidate_idle_air_terms_sum();
  candidate_idle_drive_flags();
  candidate_idle_mode_timers();
  idle_target_rpm_calculate();
  candidate_idle_stall_flags();
  candidate_idle_trim_ramp();
  candidate_idle_ac_request_calc();
  candidate_idle_ac_clutch_gate();
  candidate_idle_stall_detect();
  candidate_idle_learn_condition();
  candidate_idle_trim_integrator();
  candidate_idle_trim_load();
  candidate_fuel_cut_resume_threshold();
  candidate_idle_aux_air_term();
  candidate_idle_iat_comp();
  candidate_idle_ratio_calcs();
  candidate_idle_ac_blend_ramp();
  candidate_idle_vehicle_speed_flags();
  FUN_00034814();
  idle_air_feedback_calc();
  idle_air_output_clamp();
  ref_setSR(uVar1);
  return;
}


