/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a524: Battery Temperature Model - Decay Amount (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00025ba4; body bytes: 134; decompiled */

void FUN_00025ba4(void)

{
  float arg0;
  
  if (DAT_ffffc5db == '\0') {
    DAT_ffffb5b8 = (float)lookup_2d_descriptor_scaled(vehicle_speed_ffffbbb4,&tbl_battery_temperature_model_decay_amount_0006a524);
    DAT_ffffb5bc = (inferred_coolant_temperature_ffffa98c - 93.0) * 0.43;
    if (DAT_ffffb5bc < 0.0) {
      DAT_ffffb5bc = 0.0;
    }
    arg0 = rx8_first_order_filter(DAT_ffffb5b8,DAT_ffffb5c0,2e-05,1e-05);
    DAT_ffffb5c0 = rx8_clamp_float(arg0,-7.2,4.4);
    inferred_estimated_battery_temperature_ffffb5c4 = intake_air_temperature_ffffaddc + DAT_ffffb5bc + DAT_ffffb5c0;
  }
  else {
    inferred_estimated_battery_temperature_ffffb5c4 = 66.25;
  }
  return;
}


