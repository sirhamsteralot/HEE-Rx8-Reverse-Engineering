/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ad30: Table 2D - 191 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ad44: Table 2D - 192 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * calculate_air_charge [high]: bf68 = rpm*load/38.07; bf44 = tbl 0x6ad44(bf68) * tbl 0x6ad30(battery V); bf4c = baro*353.0163/((IAT+273)*101.32) (density ratio); bf50 = min(bf44*0.6345*bf4c/(60*rpm), 2.0) air charge per cycle; bf54 = first-order-filtered bf50/load, clamp 50.
 * RAM 0xffffbf68 airflow_rpm_load_product (float): bf68 = rpm * load / 38.07; axis for tbl 0x6ad44 in calculate_air_charge.
 * RAM 0xffffbf44 airflow_corrected (float): bf44 = tbl 0x6ad44(bf68) * tbl 0x6ad30(battery V b590).
 * RAM 0xffffbf4c air_density_ratio (float): bf4c = baro*353.0163 / ((IAT+273)*101.32): pressure/temperature density ratio.
 * RAM 0xffffbf50 air_charge_per_cycle (float): bf50 = min(bf44*0.6345*bf4c/(60*rpm), 2.0); 2.0 when rpm ~ 0.
 * RAM 0xffffbf54 air_charge_filtered (float): bf54 = first_order_filter(bf50/load, bf54, 1.0, 1e-05) clamped to 50.0.
 */
/* ROM address: 0x000314d0; body bytes: 252; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00031978 (252 bytes). Names prefixed ref_
   are inherited hypotheses. */

void calculate_air_charge(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  
  fVar6 = 60.0;
  airflow_rpm_load_product_ffffbf68 = (engine_speed_rpm_ffffb548 * engine_load_ffffc0b4) / 38.07;
  fVar4 = engine_load_ffffc0b4;
  fVar7 = engine_speed_rpm_ffffb548;
  fVar2 = (float)lookup_2d_descriptor_scaled(airflow_rpm_load_product_ffffbf68,&tbl_table_2d_192_0006ad44);
  fVar3 = (float)lookup_2d_descriptor_scaled(inferred_battery_voltage_ffffb590,&tbl_table_2d_191_0006ad30);
  airflow_corrected_ffffbf44 = fVar2 * fVar3;
  air_density_ratio_ffffbf4c = (inferred_barometric_pressure_ffffad14 * 353.0163) / ((intake_air_temperature_ffffaddc + 273.0) * 101.32);
  fVar7 = fVar7 * fVar6;
  uVar5 = 0;
  fVar2 = 1e-05;
  cVar1 = rx8_is_outside_tolerance_band(fVar7,0,0x3727c5ac);
  if (cVar1 == '\0') {
    air_charge_per_cycle_ffffbf50 = 2.0;
  }
  else {
    air_charge_per_cycle_ffffbf50 = rx8_min_float((airflow_corrected_ffffbf44 * 0.6345 * air_density_ratio_ffffbf4c) / fVar7,2.0);
  }
  cVar1 = rx8_is_outside_tolerance_band(fVar4,uVar5,fVar2);
  fVar7 = 50.0;
  if (cVar1 == '\0') {
    air_charge_filtered_ffffbf54 = 50.0;
  }
  else {
    fVar4 = rx8_first_order_filter(air_charge_per_cycle_ffffbf50 / fVar4,air_charge_filtered_ffffbf54,1.0,fVar2);
    air_charge_filtered_ffffbf54 = rx8_min_float(fVar4,fVar7);
  }
  return;
}


