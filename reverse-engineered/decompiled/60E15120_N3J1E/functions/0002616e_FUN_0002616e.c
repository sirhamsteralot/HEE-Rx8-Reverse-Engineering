/* [ADDITIONAL SOURCE REVIEW]
 * alternator_voltage_error_calc [medium]: Voltage error: 0xffffb5c8 = clamp(0xffffb59c - 0xffffb65c, -2.5, 2.5) (2.5 at pool 0x2623c), delta 0xffffb5cc; target field 0xffffb5a0 = tbl 0x6a54c(alt speed) when b613, else 0; ramp (rpm - b600)/(b604 - b600) clamp [0.1, 1.0] with b600/b604 = 406.25/700.0 (pools 0x749ec/0x749e4, AT-in-neutral selects 406.25 when b534==1 && b53a==0); integral terms 0xffffb5d4 = clamp(b5c8*10, -125, 4.8828), 0xffffb5d8 accumulates. Called from 0x267c6 via pool 0x268a0.
 * RAM 0xffffb5a0 alternator_target_field (float): Target field drive from tbl 0x6a54c(alt speed 0xffffb598) when b613, else 0; written by 0x2616e; used as band reference in 0x26624/0x2ce18.
 * RAM 0xffffb5e0 electrical_load_raw (float): Raw electrical-load quantity filtered into 0xffffb5a4 (0x2633e) and thresholded at 40/30 in 0x264f0 -> 0xffffb5b3; compared against b5a0 band in 0x26624.
 * RAM 0xffffb65c battery_voltage_filtered (float): Filtered battery voltage subtracted from the target 0xffffb59c in 0x2616e to form the charging error 0xffffb5c8 (clamp ±2.5).
 */
/* ROM address: 0x0002616e; body bytes: 392; decompiled */

void candidate_alternator_voltage_error_calc(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar4 = 2.5;
  fVar5 = -2.5;
  fVar2 = rx8_clamp_float(inferred_ram_b59c_ffffb59c_ffffb59c - battery_voltage_filtered_ffffb65c,-2.5,2.5);
  fVar3 = fVar2 - DAT_ffffb5c8;
  DAT_ffffb5c8 = fVar2;
  DAT_ffffb5cc = rx8_clamp_float(fVar3,fVar5,fVar4);
  fVar2 = 0.0;
  if (DAT_ffffb613 == '\x01') {
    alternator_target_field_ffffb5a0 = (float)lookup_2d_descriptor_scaled(inferred_alternator_speed_ffffb598,&DAT_0006a54c);
  }
  else {
    alternator_target_field_ffffb5a0 = 0.0;
  }
  if ((DAT_ffffb534 == '\x01') && (DAT_ffffb53a == '\0')) {
    pfVar1 = (float *)&DAT_000749f0;
    DAT_ffffb600 = 406.25;
  }
  else {
    DAT_ffffb600 = 700.0;
    pfVar1 = (float *)&DAT_000749e8;
  }
  DAT_ffffb604 = *pfVar1;
  if (engine_running_timer_ffffa424 == 0) {
    DAT_ffffb5d0 = alternator_target_field_ffffb5a0 * 0.5;
  }
  else {
    fVar3 = (float)rx8_divide_with_zero_fallback
                             (engine_speed_rpm_ffffb548 - DAT_ffffb600,DAT_ffffb604 - DAT_ffffb600);
    fVar3 = rx8_clamp_float(fVar3,0.1,1.0);
    DAT_ffffb5d0 = alternator_target_field_ffffb5a0 * fVar3;
  }
  fVar4 = DAT_ffffb5c8 * 0.2;
  fVar3 = DAT_ffffb5cc * 0.0;
  if (DAT_ffffb614 == '\x01') {
    DAT_ffffb5d4 = rx8_clamp_float(DAT_ffffb5c8 * 10.0,-125.0,4.8828);
    fVar4 = rx8_clamp_float(fVar4,-0.1,0.0343);
    DAT_ffffb5d8 = rx8_clamp_float(DAT_ffffb5d8 + fVar4,fVar2,alternator_target_field_ffffb5a0);
    fVar4 = 249.02;
    fVar5 = -125.0;
  }
  else {
    fVar5 = -125.0;
    DAT_ffffb5d4 = rx8_clamp_float(DAT_ffffb5c8 * 10.0,-125.0,125.0);
    fVar4 = rx8_clamp_float(fVar4,fVar5,125.0);
    DAT_ffffb5d8 = rx8_clamp_float(DAT_ffffb5d8 + fVar4,fVar2,alternator_target_field_ffffb5a0);
    fVar4 = 125.0;
  }
  DAT_ffffb5dc = rx8_clamp_float(fVar3,fVar5,fVar4);
  electrical_load_raw_ffffb5e0 = rx8_clamp_float(DAT_ffffb5d4 + DAT_ffffb5d8 + DAT_ffffb5dc,fVar2,DAT_ffffb5d0);
  return;
}


