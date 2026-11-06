/* ROM address: 0x00011744; body bytes: 104; decompiled */

void FUN_00011744(void)

{
  FUN_00019aa0();
  FUN_0002e692();
  candidate_knock_sensor_monitor_task();
  fueling_condition_flags_task();
  FUN_00014628();
  ref_alternatorControl();
  idle_control_calc_batch();
  FUN_0003eaf8();
  apv_control_task();
  FUN_00016f80();
  candidate_ssv_control_task_wrapper();
  candidate_vdi_control_task_wrapper();
  candidate_vfad_control_task_wrapper();
  FUN_000288f4();
  ref_updateDSCRelatedCANStuff__();
  ref_getFaultEvalState();
  FUN_00016b82();
  return;
}


