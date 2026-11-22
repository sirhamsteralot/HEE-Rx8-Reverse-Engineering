/* [ADDITIONAL SOURCE REVIEW]
 * throttle_percent_and_demand_calc [high]: TP percents 0xffffa9b4/a9b8 = clamp(a9ac/a9b0 / 12.7 * 100, 0, 100) (span pool 0x414b3333=12.7); demand 0xffffa9bc = min(max(a9b4, cruise output 0xffffbcf8), limiter 0xffffc028) capped 13.5/100. Emulator: AN4 50% -> a9b4=39.27 (learned zero default), 75% -> 100; TP%=30 + bcf8=70 + c028=100 -> a9bc=70. Called from 0x199d4 (jsr 0x19a46, pool 0x19c30).
 * RAM 0xffffa9b4 accelerator_pedal_1_percent (float): CORRECTION (was 'throttle_position_1_percent'): a9b4 = clamp(a9ac/12.7f*100, 0, 100) where a9ac comes from AN4 (0xffff9eec) via 0x94f0/0x18f60/0x1933a — the PEDAL (APP1) percent; it feeds demand a9bc (0x193c4), the pedal-zero learner 0x18fe8 and the cruise pedal-override compare inside 0x4c896 (against cruise output bcf8); the pedal-to-plate maps 0x228dc read the demand a9bc, not a9b4. The throttle PLATE position is ad44 (AN18/AN19 chain). Pool 0x194d4=0x6ef18 (12.7f), 0x194d0=0x42c80000 (100.0f), 0x194e0=0x2404 (clamp).
 * RAM 0xffffa9b8 accelerator_pedal_2_percent (float): CORRECTION (was 'throttle_position_2_percent'): a9b8 = same chain from AN5 (0xffff9eee) — the PEDAL (APP2) percent; see a9b4. Pool 0x194bc=0xa9b4/0xa9b0, 0x194be=0xa9b0.
 */
/* ROM address: 0x000193c4; body bytes: 322; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00019508) */
/* WARNING: Removing unreachable block (ram,0x00019522) */
/* WARNING: Removing unreachable block (ram,0x00019510) */
/* WARNING: Removing unreachable block (ram,0x0001952e) */

undefined4 throttle_percent_and_demand_calc(void)

{
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 extraout_r0_01;
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float arg2;
  
  arg2 = 100.0;
  fVar2 = (float)rx8_divide_with_zero_fallback(pedal_1_volts_zeroed_ffffa9ac,0x414b3333);
  fVar3 = 0.0;
  accelerator_pedal_1_percent_ffffa9b4 = rx8_clamp_float(fVar2 * arg2 - 0.0,0.0,arg2);
  fVar2 = (float)rx8_divide_with_zero_fallback(DAT_ffffa9b0,0x414b3333);
  accelerator_pedal_2_percent_ffffa9b8 = rx8_clamp_float(fVar2 * arg2 - 0.0,fVar3,arg2);
  if (accelerator_pedal_1_percent_ffffa9b4 < 50.0) {
    if (accelerator_pedal_1_percent_ffffa9b4 < 45.0) {
      DAT_ffffa9df = 0;
    }
  }
  else {
    DAT_ffffa9df = 1;
  }
  if (DAT_ffffcc9b == '\x01') {
    if (DAT_ffffcc9c == '\x01') {
      inferred_ram_a9bc_ffffa9bc_ffffa9bc = 15.0;
      uVar1 = 1;
    }
    else {
      inferred_ram_a9bc_ffffa9bc_ffffa9bc = rx8_min_float(13.5,accelerator_pedal_2_percent_ffffa9b8);
      uVar1 = extraout_r0;
    }
  }
  else if (DAT_ffffcc9c == '\x01') {
    inferred_ram_a9bc_ffffa9bc_ffffa9bc = rx8_min_float(13.5,accelerator_pedal_1_percent_ffffa9b4);
    uVar1 = extraout_r0_00;
  }
  else {
    fVar2 = rx8_max_float(accelerator_pedal_1_percent_ffffa9b4,cruise_set_speed_ffffbcf8);
    fVar2 = rx8_min_float(fVar2,DAT_ffffc028);
    if (DAT_ffffa914 == '\x01') {
      fVar3 = 13.5;
    }
    else {
      fVar3 = 100.0;
    }
    inferred_ram_a9bc_ffffa9bc_ffffa9bc = rx8_min_float(fVar2,fVar3);
    uVar1 = extraout_r0_01;
  }
  DAT_ffffa9c0 = inferred_ram_a9bc_ffffa9bc_ffffa9bc - DAT_ffffa9d4;
  DAT_ffffa9d4 = DAT_ffffa9d0;
  DAT_ffffa9d0 = inferred_ram_a9bc_ffffa9bc_ffffa9bc;
  return uVar1;
}


