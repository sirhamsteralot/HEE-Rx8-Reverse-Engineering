/* [ADDITIONAL SOURCE REVIEW]
 * ref_engineCrankingConditionsInit__ [high]: Clears the three cranking-state cells 0xffffa79c (pool 0x14882), 0xffffa79e (pool 0x1488c) and 0xffffa79d (pool 0x14890) at 0x14812/0x14814/0x1481a.
 */
/* ROM address: 0x0001480c; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001476c (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_engineCrankingConditionsInit__(void)

{
  candidate_engine_running_stable_ffffa79c = 0;
  candidate_engine_running_state_ffffa79e = 0;
  candidate_post_start_blanking_counter_ffffa79d = 0;
  return;
}


