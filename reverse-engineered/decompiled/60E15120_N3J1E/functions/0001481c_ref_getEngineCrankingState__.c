/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a6cc: Table 2D - 334 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * ref_getEngineCrankingState__ [high]: State machine: decrements byte 0xffffa79d by one (add of pool 0x14886 = 0x00ff at 0x14832) while it is non-zero (cmp/pl at 0x1482a); state 0xffffa79e (pool 0x1488c) = 1 when rpm 0xffffb548 (pool 0x14884) >= f32 0x757a0 = 500.0 (pool 0x14894), 0 when rpm < f32 0x7579c = 300.0 (pool 0x148a0); on the 0->1 edge the counter is primed from lookup_2d_u8(coolant 0xffffa98c, descriptor 0x6a6cc) via 0x20ac (pools 0x14898/0x1489c, jsr at 0x14852). Output 0xffffa79c (pool 0x14882) = state while the counter is zero, else 0 (0x14874/0x14878).
 * RAM 0xffffa79c candidate_engine_running_stable (uint8): Written at 0x14878 (pool 0x14882): the rpm state 0xffffa79e while the post-start blanking counter 0xffffa79d is zero, cleared otherwise. Read by 0x10e8e (status 1/2) and the CAN builder 0x10390.
 * RAM 0xffffa79d candidate_post_start_blanking_counter (uint8): Decremented by one per call while non-zero (add pool 0x14886 = 0x00ff at 0x14832) and primed from lookup_2d_u8(coolant, descriptor 0x6a6cc) on the rpm 0->1 edge (jsr 0x20ac at 0x14852, store at 0x14858). ROM data 0x757e0 = 4 counts for every coolant cell.
 * RAM 0xffffa79e candidate_engine_running_state (uint8): Rpm-derived state: 1 when rpm >= 500.0 (f32 0x757a0), 0 when rpm < 300.0 (f32 0x7579c), held in between (0x14840-0x14864).
 */
/* ROM address: 0x0001481c; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001477c (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getEngineCrankingState__(void)

{
  char cVar1;
  
  if (candidate_post_start_blanking_counter_ffffa79d != '\0') {
    candidate_post_start_blanking_counter_ffffa79d = candidate_post_start_blanking_counter_ffffa79d + -1;
  }
  if (engine_speed_rpm_ffffb548 < 500.0) {
    cVar1 = candidate_engine_running_state_ffffa79e;
    if (engine_speed_rpm_ffffb548 < 300.0) {
      cVar1 = '\0';
    }
  }
  else {
    cVar1 = '\x01';
    if (candidate_engine_running_state_ffffa79e == '\0') {
      candidate_post_start_blanking_counter_ffffa79d = rx8_lookup_2d_raw_u8(inferred_coolant_temperature_ffffa98c,&tbl_table_2d_334_check_datatype_0006a6cc);
    }
  }
  candidate_engine_running_state_ffffa79e = cVar1;
  if (candidate_post_start_blanking_counter_ffffa79d != '\0') {
    cVar1 = '\0';
  }
  candidate_engine_running_stable_ffffa79c = cVar1;
  return;
}


