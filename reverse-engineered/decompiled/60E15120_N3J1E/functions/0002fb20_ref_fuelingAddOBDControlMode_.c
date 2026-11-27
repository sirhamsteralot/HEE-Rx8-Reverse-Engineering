/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffbdd5 fuel_pump_demand_threshold (uint8): Hysteresis latch inside 0x2fb20: set 1 at 0x2fb44 when DAT_ffffbdc0 >= DAT_ffffbdc4, cleared at 0x2fb4c once DAT_ffffbdc0 < DAT_ffffbdc4 - 3.5 (ROM 0x775d8), unchanged inside the band. Pool 0x2fbdc=0xffffbdd5.
 * RAM 0xffffbdd4 fuel_pump_speed_hold_counter (uint8): Hold counter in 0x2fb20: loaded from ROM[0x775be]=0x01 while injectors_off 0xffffa42c==1, else incremented by 255 with u8 saturation (add r3,r4 at 0x2fbba, pool 0x2fbcc=0x00ff). Feeds the third request term (gated by ROM[0x775bd], which is 0x01 here so the term is inert). Pool 0x2fbe4=0xffffbdd4.
 * RAM 0xffffbdc0 fuel_pump_filtered_demand (float32): Filtered fuel-volume demand from 0x2f9d0 ref_filterFuelVolumeRequest = first_order_filter(rpm 0xffffb548 x fuel_volume_final 0xffffbeb0 x 0.12, coeff 0.75) via helper 0x23b0; also read back as the filter state by 0x2f9d0. Pools 0x2fae0=0xffffbdc0, 0x2fad4=0x3df5c28f (0.12), ROM 0x775c0=0.75. Compared against 0xffffbdc4 by 0x2fb20.
 * RAM 0xffffbdc4 fuel_pump_max_demand (float32): Max fueling request from 0x2f9fc ref_calculateFuelingRequestMaxForOBDControl: 2D-167 (0x6a97c) or 2D-168 (0x6a990) looked up on battery voltage 0xffffb590 while intake air 0xffffaddc stays within the 200/190 margins of 2D-166 (0x6a968, axis baro 0xffffad14), else 0.0 with 0xffffbdcc=1. Pool 0x2fafc=0xffffbdc4; reader 0x2fb20 (pool 0x2fbd0).
 */
/* ROM address: 0x0002fb20; body bytes: 164; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0002fb80) */
/* Unique exact-byte match to related 60E0FC00 function at 0002ffd8 (164 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_fuelingAddOBDControlMode_(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = engine_injectors_off_ffffa42c;
  if (fuel_pump_filtered_demand_ffffbdc0 < fuel_pump_max_demand_ffffbdc4) {
    if (fuel_pump_filtered_demand_ffffbdc0 < fuel_pump_max_demand_ffffbdc4 - 3.5) {
      fuel_pump_demand_threshold_ffffbdd5 = '\0';
    }
  }
  else {
    fuel_pump_demand_threshold_ffffbdd5 = '\x01';
  }
  if (((fuel_pump_demand_threshold_ffffbdd5 == '\x01') && (engine_stopped_latch_ffffa41c == '\0')) ||
     ((engine_injectors_off_ffffa42c == '\x01' && (engine_running_flag_ffffaa68 == '\x01')))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  fuel_pump_speed_request_ffffbdbc = ref_obdFuelingAddRequst_(uVar2);
  if (cVar1 == '\x01') {
    fuel_pump_speed_hold_counter_ffffbdd4 = '\x01';
  }
  else if (fuel_pump_speed_hold_counter_ffffbdd4 != '\0') {
    fuel_pump_speed_hold_counter_ffffbdd4 = fuel_pump_speed_hold_counter_ffffbdd4 + -1;
  }
  return cVar1;
}


