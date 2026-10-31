/* ROM address: 0x000197be; body bytes: 72; decompiled */

void FUN_000197be(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_getEngineSpeed();
  ref_filterEngineSpeed();
  ref_calculatePredictedEngineSpeed_();
  FUN_0001a1dc();
  candidate_maf_per_rotation_calc();
  ref_airPerStroke();
  calculate_engine_load();
  knock_threshold_setup();
  knock_attack_condition();
  ref_setSR(uVar1);
  return;
}


