/* [ADDITIONAL SOURCE REVIEW]
 * cruise_enable_pedal_override [high]: 0xffffcf18 = 0xffffbcf8 copy; enable flag 0xffffcf34 = (0xffffbced && 0xffffbcf8 >= 0xffffa9b4) - cruise enabled only while cruise output percent exceeds TP1 percent (pedal override). Pools 0x4c90c-0x4c912 = cf18/bcf8/cf34/bced. Emulator: bcf8=50 < a9b4=80 -> cf34=0; bcf8=90 -> cf34=1. Called from batch 0x2e692 (jsr 0x2e6a4, pool 0x2e7c8).
 * RAM 0xffffbcf8 cruise_output_percent (float): Cruise control OUTPUT demand in percent, clamp [0,100] by 0x2df62 (pool 0x2e004 store at 0x2dfcc); copied to 0xffffcf18 and compared with TP1 percent 0xffffa9b4 (NOT vehicle speed) for the enable flag 0xffffcf34 in 0x4c896 (pedal override), and mixed into demand 0xffffa9bc = min(max(a9b4, bcf8), c028) by 0x193c4. (Was cruise_set_speed; corrected - emulator-verified, reviews/cruise_control/dynamic_validation_log.txt.)
 */
/* ROM address: 0x0004c896; body bytes: 46; decompiled */

void cruise_enable_pedal_override(void)

{
  DAT_ffffcf18 = cruise_set_speed_ffffbcf8;
  if ((DAT_ffffbced == '\0') || (cruise_set_speed_ffffbcf8 < throttle_position_1_percent_ffffa9b4)) {
    cruise_enable_flag_ffffcf34 = 0;
  }
  else {
    cruise_enable_flag_ffffcf34 = 1;
  }
  return;
}


