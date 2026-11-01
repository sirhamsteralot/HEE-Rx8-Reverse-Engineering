/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b340: Airflow Or Load Related (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b354: Table 2D - 231 (Airflow Related) (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0003828a; body bytes: 146; decompiled */

uint FUN_0003828a(void)

{
  uint uVar1;
  float extraout_fr0;
  
  DAT_ffffc4e0 = rx8_first_order_filter(mass_air_flow_ffffa9ec,DAT_ffffc4e0,0.011799991,1e-05);
  DAT_ffffc518 = (float)lookup_2d_descriptor_scaled(vehicle_speed_ffffbbb4,&tbl_table_2d_231_airflow_related_0006b354);
  DAT_ffffc4dc = (inferred_temp_c4c8_ffffc4c8_ffffc4c8 - intake_air_temperature_ffffaddc) * DAT_ffffc518;
  uVar1 = (uint)DAT_ffffb0ca;
  if (uVar1 == 1) {
    DAT_ffffc4d8 = 0.0;
  }
  else if (open_loop_fuel_target_ffffb120 <= 0.0) {
    uVar1 = lookup_2d_descriptor_scaled(engine_load_ffffc0b4,&tbl_airflow_or_load_related_0006b340);
    DAT_ffffc4d8 = DAT_ffffc4e0 * 3018.4 * extraout_fr0;
    DAT_ffffc514 = extraout_fr0;
  }
  else {
    DAT_ffffc4d8 = DAT_ffffc4e0 * 3018.4 * 0.1328;
  }
  return uVar1;
}


