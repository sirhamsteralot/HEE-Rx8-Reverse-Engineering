/* [ADDITIONAL SOURCE REVIEW]
 * closed_loop_enable_condition [high]: Computes ae1e (CL allowed: coolant >= 35 C, engine time >= tbl 0x6990c vs catalyst-temp model, open loop inactive b12c==0, O2 in tolerance, no DTC-ish conditions) and ae1f (CL active = ae1e && cd5c==0 && lambda feedback aa80/aa81).
 * RAM 0xffffb12c open_loop_active (uint8): OPEN-loop flag (polarity corrected): = (b12a != 0), set by 0x1ee30; blocks closed loop in 0x1c13c, selects open-loop targets in 0x1ee4a, gates evap 0x22144. Earlier sessions mislabeled this as the closed-loop flag.
 * RAM 0xffffaa80 lambda_in_target_band (uint8): 0x1ac00: 1 when no DTC, 0.99 <= lambda target 0xffffadfc < 1.01, ad0c==1, engine running; CL-active ingredient (ae1f).
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006990c: Table 2D - 304 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0001c13c; body bytes: 320; decompiled */

char closed_loop_enable_condition(void)

{
  char cVar1;
  
  if (engine_load_ffffc0b4 <= 2.0) {
    if (engine_load_ffffc0b4 <= 1.98) {
      DAT_ffffb066 = '\0';
    }
  }
  else {
    DAT_ffffb066 = '\x01';
  }
  if (1000.0 <= engine_speed_rpm_ffffb548) {
    if (1100.0 <= engine_speed_rpm_ffffb548) {
      DAT_ffffb067 = '\0';
    }
  }
  else {
    DAT_ffffb067 = '\x01';
  }
  DAT_ffffb05e = rx8_lookup_2d_raw_u16(inferred_coolant_temperature_catalyst_temp_model_ffffa998,&tbl_closed_loop_warmup_time_0006990c);
  if (((((inferred_coolant_temperature_ffffa98c < 35.0) || (engine_running_timer_ffffa424 < DAT_ffffb05e)) || (open_loop_active_ffffb12c != '\0')) ||
      ((DAT_ffffae18 != 0 ||
       (cVar1 = rx8_is_outside_tolerance_band(DAT_ffffbc74,0,0x3727c5ac), cVar1 != '\0')))) ||
     ((((8 < DAT_ffffa93a || ((DAT_ffffb064 < 0x10 || (secondary_air_pump_request_ffffbf6c != '\0')))) ||
       (DAT_ffffb065 < 4)) ||
      ((DAT_ffffd26d != '\0' || ((DAT_ffffb066 != '\0' && (DAT_ffffb067 != '\x01')))))))) {
    closed_loop_allowed_ffffae1e = '\0';
  }
  else {
    closed_loop_allowed_ffffae1e = '\x01';
  }
  cVar1 = closed_loop_allowed_ffffae1e;
  if (((closed_loop_allowed_ffffae1e == '\x01') && (DAT_ffffcd5c == '\0')) &&
     ((cVar1 = '\x01', lambda_in_target_band_ffffaa80 == '\x01' || (cVar1 = DAT_ffffaa81, DAT_ffffaa81 == '\x01')))) {
    closed_loop_active_ffffae1f = 1;
  }
  else {
    closed_loop_active_ffffae1f = 0;
  }
  return cVar1;
}


