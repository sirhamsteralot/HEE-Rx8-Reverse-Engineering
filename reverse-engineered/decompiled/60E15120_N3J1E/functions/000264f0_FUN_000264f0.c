/* [ADDITIONAL SOURCE REVIEW]
 * electrical_load_flag_calc [medium]: 0xffffb5b3 = 1 when filtered 0xffffb5e0 >= 40.0, 0 below 30.0; 0xffffb5a4 = first_order_filter(b5e0, b5a4, 0.035335, 1e-5) maintained by 0x2633e; 0xffffb5a8 tracks b5ec = b5e0 * clamp((b5e0-b5e8)/50.0, 0, 1) with -124.51 decay. Called from 0x2680e via pool 0x268c4. Feeds idle high-load select (idle_control_report) and the drag ratio in 0x2ce18.
 */
/* ROM address: 0x000264f0; body bytes: 238; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00026e14 (238 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_electrical_load_flag_calc(void)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  float arg0;
  
  uVar2 = 0x42480000;
  fVar3 = 30.0;
  DAT_ffffb5e4 = electrical_load_filtered_ffffb5a4;
  arg0 = electrical_load_raw_ffffb5e0;
  DAT_ffffb5e8 = rx8_first_order_filter(electrical_load_raw_ffffb5e0,DAT_ffffb5e8,1.0,1e-05);
  fVar1 = (float)rx8_divide_with_zero_fallback((arg0 - 0.0) - DAT_ffffb5e8,uVar2);
  fVar1 = rx8_clamp_float(fVar1,0.0,1.0);
  DAT_ffffb5ec = arg0 * fVar1;
  if ((engine_running_ffffa428 != '\x01') || (0.0 <= engine_speed_rpm_ffffb548)) {
    if (DAT_ffffb615 == 1) {
      DAT_ffffb5a8 = rx8_max_float(arg0,DAT_ffffb5a8 - 124.51);
    }
    else {
      DAT_ffffb5a8 = DAT_ffffb5ec + arg0;
    }
    if (DAT_ffffb5a8 <= arg0) {
      DAT_ffffb615 = 0;
    }
  }
  else {
    DAT_ffffb5a8 = rx8_max_float(arg0,DAT_ffffb5a8);
    DAT_ffffb615 = 1;
  }
  if (DAT_ffffb5e4 < 40.0) {
    if (DAT_ffffb5e4 < fVar3) {
      high_load_flag_ffffb5b3 = 0;
    }
  }
  else {
    high_load_flag_ffffb5b3 = 1;
  }
  return;
}


