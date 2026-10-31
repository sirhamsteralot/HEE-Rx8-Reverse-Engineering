/* [ADDITIONAL SOURCE REVIEW]
 * closed_loop_fuel_trim [high]: Closed loop (ae1f): beb4 = clamp((max(bf40, c01c+b0c4) + min(tbl 0x6ac38(coolant), open_loop_fuel_target b120) + 1.0) * ad ecc - 1.0, -1, 2); filtered (0.0625) into beb8; open loop: beb4 = 0. STFT-style trim around lambda target.
 * RAM 0xffffbeb4 closed_loop_trim_raw (float): beb4 = clamp((max(bf40, c01c+b0c4) + min(tbl 0x6ac38(coolant), b120) + 1)*ad ecc - 1, -1, 2) in closed loop; 0 in open loop.
 * RAM 0xffffbeb8 closed_loop_trim_filtered (float): beb8 = first_order_filter(beb4, beb8, 0.0625, 1e-05); STFT-style trim.
 * RAM 0xffffbf20 cl_coolant_compensation (float): bf20 = lookup_2d tbl DAT_0006ac38(coolant); used in closed_loop_fuel_trim.
 */
/* ROM address: 0x000307e0; body bytes: 192; decompiled */

char closed_loop_fuel_trim(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 0.0;
  if (closed_loop_active_ffffae1f == '\0') {
    closed_loop_trim_raw_ffffbeb4 = 0.0;
  }
  else {
    fVar2 = rx8_max_float(DAT_ffffbf40,DAT_ffffc01c + DAT_ffffb0c4);
    cl_coolant_compensation_ffffbf20 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_fuel_coolant_compensation_0006ac38);
    fVar1 = rx8_min_float(cl_coolant_compensation_ffffbf20,open_loop_fuel_target_ffffb120);
    closed_loop_trim_raw_ffffbeb4 = rx8_clamp_float((fVar2 + fVar1 + 1.0) * DAT_ffffadec + -1.0,-1.0,2.0);
    fVar2 = rx8_first_order_filter(closed_loop_trim_raw_ffffbeb4,closed_loop_trim_filtered_ffffbeb8,0.0625,1e-05);
  }
  if (DAT_ffffb228 == '\x01') {
    fVar2 = fVar2 - 0.0;
  }
  else if (DAT_ffffb228 == '\x02') {
    fVar2 = fVar2 + 0.0;
  }
  closed_loop_trim_filtered_ffffbeb8 = fVar2;
  return DAT_ffffb228;
}


