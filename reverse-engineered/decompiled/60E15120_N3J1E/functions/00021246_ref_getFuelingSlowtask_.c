/* [ADDITIONAL SOURCE REVIEW]
 * fueling_slow_task [high]: Task[11] worker (0x6584 -> 0x117ac) under interrupt mask 0x10: open_loop_request_condition, set_open_loop_flag, open_loop_fueling_targets, open_loop_changeover_enrichment (0x2024c), warmup_fueling_compensation (0x32e08), 0x20298/0x2048c/0x20288, rear-O2 chain (0x1d6b4/0x1d772/0x1d850/0x1d8dc/0x1e134), maf_operating_range (0x1e842), 0x1e448, LTFT-for-CAN (0x1e900), 0x1ea56/0x1e99c/0x1eae0/0x1eba6/0x1ecee, 0x188a4, fuel_cut_rpm_condition (0x18cfe), rev_limit_conditionals (0xee82).
 */
/* ROM address: 0x00021246; body bytes: 180; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021bb2 (180 bytes). Names prefixed ref_
   are inherited hypotheses. */

void fueling_slow_task(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  open_loop_request_condition();
  set_open_loop_flag();
  open_loop_fueling_targets();
  open_loop_changeover_enrichment();
  warmup_fueling_compensation();
  FUN_00020298();
  FUN_0002048c();
  FUN_00020288();
  closed_loop_fuel_trim();
  FUN_0001ce6c();
  FUN_0001c31c();
  ref_rearO2Correction_MAYBE_();
  FUN_0001d772();
  ref_getRearO2FilteredValue();
  FUN_0001d8dc();
  FUN_0001e134();
  maf_operating_range();
  FUN_0001e448();
  ref_LTFTForCAN__();
  FUN_0001ea56();
  FUN_0001e99c();
  FUN_0001eae0();
  FUN_0001eba6();
  FUN_0001ecee();
  FUN_000188a4();
  candidate_fuel_cut_rpm_condition();
  candidate_rev_limit_conditionals();
  ref_setSR(uVar1);
  return;
}


