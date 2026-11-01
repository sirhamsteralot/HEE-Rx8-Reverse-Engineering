/* [ADDITIONAL SOURCE REVIEW]
 * calc_fuel_volume_request [high]: Core fuel-mass calc: bed0 = engine_load*0.07196; bed4 = tbl 0x6ac88 'Fuel Injection - Engine Load Compensation'(RPM); bf1c = tbl DAT_0006ac38(coolant); bf14 = (b0d0 - c0c8 - ae08 - b21c + max(c104,cde0) + min(bf1c, c00c+b120) + max(ae10,b124) + 1.0) * ad ecc * bed4; beac = FUN_0005c024(bf14); beb0 = beac*bed0.
 * RAM 0xffffb120 open_loop_fuel_target (float): Open-loop fuel target computed by 0x1ee4a (b130*b134 or b138*b13c blend); zero in closed loop.
 * RAM 0xffffbed0 fuel_load_scale (float): bed0 = engine_load_ffffc0b4 * 0.07196; multiplied into final fuel volume beb0 = beac * bed0.
 * RAM 0xffffbed4 fuel_load_compensation (float): bed4 = lookup_3d tbl 0x6ac88 'Fuel Injection - Engine Load Compensation'(RPM); multiplier in bf14.
 * RAM 0xffffbf1c fuel_coolant_compensation (float): bf1c = lookup_2d tbl DAT_0006ac38(coolant); added via min(bf1c, c00c + open_loop_fuel_target b120) in bf14.
 * RAM 0xffffbf14 fuel_correction_sum (float): bf14 = (b0d0 - c0c8 - ae08 - b21c + max(c104,cde0) + min(bf1c, c00c+b120) + max(ae10,b124) + 1.0) * ad ecc * bed4; scaled by FUN_0005c024 into beac.
 * RAM 0xffffbeac fuel_volume_scaled (float): beac = FUN_0005c024(bf14) (diagnostic-scaler transform); beb0 = beac * bed0.
 * RAM 0xffffbeb0 fuel_volume_final (float): beb0 = beac * bed0: final requested fuel volume; read by open_loop_request_condition (0x1f0c4) as snapshot_DAT_ffffbeb0.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ac88: Fuel Injection - Engine Load Compensation (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000306e8; body bytes: 248; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00030720) */
/* Unique exact-byte match to related 60E0FC00 function at 00030b84 (248 bytes). Names prefixed ref_
   are inherited hypotheses. */

void calc_fuel_volume_request(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fuel_load_scale_ffffbed0 = engine_load_ffffc0b4 * 0.07196;
  fuel_load_compensation_ffffbed4 = (float)lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_fuel_injection_engine_load_compensation_0006ac88);
  fVar3 = 1.0;
  fVar1 = rx8_max_float(DAT_ffffc104,DAT_ffffcde0);
  fuel_coolant_compensation_ffffbf1c = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_fuel_coolant_compensation_0006ac38);
  fVar2 = rx8_min_float(fuel_coolant_compensation_ffffbf1c,warmup_enrichment_total_ffffc00c + open_loop_fuel_target_ffffb120);
  fVar1 = rx8_max_float(DAT_ffffbf40,
                        DAT_ffffc01c + DAT_ffffb0c4 + DAT_ffffbc74 + DAT_ffffcdf4 + DAT_ffffa5dc +
                        fVar1 + fVar2);
  fVar2 = rx8_max_float(DAT_ffffae10,open_loop_changeover_enrichment_ffffb124);
  fuel_correction_sum_ffffbf14 = ((((inferred_ltft_bank1_ffffb0d0_ffffb0d0 - DAT_ffffc0c8) - DAT_ffffae08) - DAT_ffffb21c) + fVar1 + fVar2 +
                 fVar3) * inferred_lambda_actual_ffffadec_ffffadec * fuel_load_compensation_ffffbed4;
  fuel_volume_scaled_ffffbeac = (float)FUN_0005c024(fuel_correction_sum_ffffbf14);
  fuel_volume_final_ffffbeb0 = fuel_volume_scaled_ffffbeac * fuel_load_scale_ffffbed0;
  return;
}


