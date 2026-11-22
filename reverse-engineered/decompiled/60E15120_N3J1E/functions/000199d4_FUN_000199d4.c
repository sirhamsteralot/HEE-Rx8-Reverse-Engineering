/* [ADDITIONAL SOURCE REVIEW]
 * pedal_tp_sensor_batch [high]: Sensor/percent batch called from 0x1150e (pool 0x116b8=0x000199d4): runs 0x18f60/0x18fa4/0x18fe8/0x1933a/0x193c4 (pedal AN4/AN5 -> volts -> percent -> demand), 0x1b08e/0x1b14c/0x1b940 (plate AN18/AN19 -> TP volts -> plate position), learning/plausibility 0x1b166/0x1b3f2/0x1b6fc/0x1ba20/0x1bcae (callgraph.tsv rows for caller 000199d4).
 */
/* ROM address: 0x000199d4; body bytes: 204; decompiled */

void pedal_tp_sensor_batch(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  key_input_pf15_edge_latch();
  key_on_time_counter_update();
  key_off_time_counter_update();
  FUN_000312f8();
  FUN_00031318();
  engine_running_from_rpm();
  FUN_0000e060();
  FUN_0000e0f4();
  ref_calculateEngineRunningTimer2();
  ref_calculateEngineRunningTimer();
  FUN_0001a394();
  pedal_volts_clamp_latch();
  ref_filterSomething();
  FUN_00018fa4();
  ref_filterSomething2();
  FUN_00018fe8();
  pedal_learned_zero_subtract();
  throttle_percent_and_demand_calc();
  ref_getDriverOffThrottleTimer__();
  ref_getDriverOffThrottleInstatanious();
  plate_tp1_volts_latch();
  plate_tp2_volts_latch();
  FUN_0001b166();
  FUN_0001b3f2();
  FUN_0001b6fc();
  ref_calculateThrottlePedalPercentForSomethingElse_();
  FUN_0001ba20();
  FUN_0001bcae();
  ref_getACSwitchStatus();
  FUN_0003ebe4();
  FUN_00049490();
  ref_setSR(uVar1);
  return;
}


