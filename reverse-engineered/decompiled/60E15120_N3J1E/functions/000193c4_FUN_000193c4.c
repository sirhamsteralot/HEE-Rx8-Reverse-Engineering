/* [ADDITIONAL SOURCE REVIEW]
 * throttle_percent_and_demand_calc [high]: TP percents 0xffffa9b4/a9b8 = clamp(a9ac/a9b0 / 12.7 * 100, 0, 100) (span pool 0x414b3333=12.7); demand 0xffffa9bc = min(max(a9b4, cruise output 0xffffbcf8), limiter 0xffffc028) capped 13.5/100. Emulator: AN4 50% -> a9b4=39.27 (learned zero default), 75% -> 100; TP%=30 + bcf8=70 + c028=100 -> a9bc=70. Called from 0x199d4 (jsr 0x19a46, pool 0x19c30).
 * RAM 0xffffa9b4 throttle_position_1_percent (float): TP1 percent 0-100: AN4 raw 0xffff9eec (ADDR4H via sweep 0x6884) -> 0x94f0 a108[0]=raw*6.341*7.6294e-5 (ROM 0x6eeb8/0x6eec0) -> 0x18f60 a99c=min(25,a108) -> 0x1933a a9ac=max(0,a99c-learned 10.856 @0xffff8068) -> 0x193c4 a9b4=clamp(a9ac/12.7*100,0,100). NOT vehicle speed (that is 0xffffbbb4 km/h, PID 0x0D). Emulator: AN4 50% -> 39.27, 75% -> 100.
 * RAM 0xffffa9b8 throttle_position_2_percent (float): TP2 percent 0-100, same chain via AN5 raw 0xffff9eee (base 3.488 ROM 0x6eec4): a9b8=clamp(a9b0/12.7*100,0,100) in 0x193c4.
 */
/* ROM address: 0x000193c4; body bytes: 322; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00019508) */
/* WARNING: Removing unreachable block (ram,0x00019522) */
/* WARNING: Removing unreachable block (ram,0x00019510) */
/* WARNING: Removing unreachable block (ram,0x0001952e) */

undefined4 FUN_000193c4(void)

{
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 extraout_r0_01;
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float arg2;
  
  arg2 = 100.0;
  fVar2 = (float)rx8_divide_with_zero_fallback(DAT_ffffa9ac,0x414b3333);
  fVar3 = 0.0;
  DAT_ffffa9b4 = rx8_clamp_float(fVar2 * arg2 - 0.0,0.0,arg2);
  fVar2 = (float)rx8_divide_with_zero_fallback(DAT_ffffa9b0,0x414b3333);
  DAT_ffffa9b8 = rx8_clamp_float(fVar2 * arg2 - 0.0,fVar3,arg2);
  if (DAT_ffffa9b4 < 50.0) {
    if (DAT_ffffa9b4 < 45.0) {
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
      inferred_ram_a9bc_ffffa9bc_ffffa9bc = rx8_min_float(13.5,DAT_ffffa9b8);
      uVar1 = extraout_r0;
    }
  }
  else if (DAT_ffffcc9c == '\x01') {
    inferred_ram_a9bc_ffffa9bc_ffffa9bc = rx8_min_float(13.5,DAT_ffffa9b4);
    uVar1 = extraout_r0_00;
  }
  else {
    fVar2 = rx8_max_float(DAT_ffffa9b4,cruise_set_speed_ffffbcf8);
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


