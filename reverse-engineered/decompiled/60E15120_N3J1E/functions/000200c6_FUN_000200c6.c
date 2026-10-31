/* [ADDITIONAL SOURCE REVIEW]
 * blend_weight_update [high]: Sets DAT_ffffb11c/b118: 1.0 in normal conditions (no c590/cca1 fault, coolant plausible b1d0, c644<=1000, mode flags clear), decays -0.0667/call while open_loop_active with b142/b154/b157/b159 set, else 0.0. Consumed by open_loop_fueling_targets (0x1ee4a: OL target blend) and leading/trailing_base_timing_calc (0x11f00/0x1206c: base-timing blend). Resolves knock-review unresolved item 2.
 * RAM 0xffffb11c fuel_blend_weight (float): Set with b118 by blend_weight_update (0x200c6): 1.0 normal, decays -0.0667 in open loop, 0 on faults; weights the implausible-coolant OL target branch in 0x1ee4a.
 * RAM 0xffffb118 timing_blend_weight (float): Same producer as b11c (0x200c6); blends base ignition timing with the open-loop cap in 0x11f00/0x1206c.
 * RAM 0xffffb1d0 coolant_plausible_flag (uint8): b1d0 = 1 when coolant >= -40 C (clear below -43); gates blend-weight set in 0x200c6.
 * RAM 0xffffb142 ol_decay_enable_a (uint8): b142 checked (with b157) in the blend_weight_update decay condition 0x200c6.
 * RAM 0xffffb152 ol_decay_enable_b (uint8): b152 checked in the fault branch of 0x200c6.
 * RAM 0xffffb157 ol_decay_enable_c (uint8): b157 must be set (with b142) for the b11c/b118 decay branch in 0x200c6.
 */
/* ROM address: 0x000200c6; body bytes: 296; decompiled */

void blend_weight_update(void)

{
  float arg1;
  
  if (inferred_coolant_temperature_ffffa98c < -40.0) {
    if (inferred_coolant_temperature_ffffa98c < -43.0) {
      coolant_plausible_flag_ffffb1d0 = '\0';
    }
  }
  else {
    coolant_plausible_flag_ffffb1d0 = '\x01';
  }
  arg1 = 0.0;
  if ((DAT_ffffc590 == '\0') && (DAT_ffffcca1 == '\0')) {
    if ((((coolant_plausible_flag_ffffb1d0 != '\x01') || (safe_mode_ffffcd60 != '\0')) || (1000.0 < DAT_ffffc644)) ||
       ((((ol_decay_enable_b_ffffb152 != '\x01' || (ol_decay_enable_a_ffffb142 == 0)) &&
         ((ol_timer_expired_ffffb159 != '\x01' || (ol_band_condition_ffffb154 != '\x01')))) && (ol_decay_enable_c_ffffb157 != '\x01')))) {
      if ((open_loop_active_ffffb12c != '\x01') ||
         (((ol_decay_enable_a_ffffb142 != 0 && (ol_decay_enable_c_ffffb157 != '\0')) &&
          ((ol_timer_expired_ffffb159 != '\0' && ((DAT_ffffc644 <= 1000.0 && (ol_band_condition_ffffb154 != '\0')))))))) {
        fuel_blend_weight_ffffb11c = 0.0;
        timing_blend_weight_ffffb118 = 0.0;
      }
      else {
        fuel_blend_weight_ffffb11c = rx8_max_float(fuel_blend_weight_ffffb11c - 0.0667,0.0);
        timing_blend_weight_ffffb118 = rx8_max_float(timing_blend_weight_ffffb118 - 0.0667,arg1);
      }
    }
    else {
      fuel_blend_weight_ffffb11c = 1.0;
      timing_blend_weight_ffffb118 = 1.0;
    }
  }
  else {
    fuel_blend_weight_ffffb11c = 0.0;
    timing_blend_weight_ffffb118 = 0.0;
  }
  return;
}


