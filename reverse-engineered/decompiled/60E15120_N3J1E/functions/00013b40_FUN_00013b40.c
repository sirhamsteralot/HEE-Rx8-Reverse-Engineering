/* [ADDITIONAL SOURCE REVIEW]
 * knock_retard_slow_recovery [high]: Active && !c05c: +0.35 deg per 62 counts (two u8 saturating counters a74a/a74b selected by c05d); result clamped via 0x13bd2, mirror a738 updated.
 * RAM 0xffffa73c knock_active (uint8): Set by 0x138b2 = a73d && a73e; gates attack (0x13a60) and slow recovery (0x13b40).
 * RAM 0xffffa74a knock_recovery_counter_a (uint8): Slow-recovery pacing counter (c05d==0 path); +0.35 deg per 62 counts.
 * RAM 0xffffa74b knock_recovery_counter_b (uint8): Slow-recovery pacing counter (c05d==1 path).
 * RAM 0xffffc05d knock_transient_flag (uint8): Set by 0x336c4 stability check (0 = stable); selects recovery counter a74a vs a74b and filter constants.
 */
/* ROM address: 0x00013b40; body bytes: 146; decompiled */

void knock_retard_slow_recovery(void)

{
  float fVar1;
  
  fVar1 = knock_retard_ffffa734;
  if ((knock_active_ffffa73c == '\x01') && (knock_attack_condition_ffffc05c == '\0')) {
    if (knock_transient_flag_ffffc05d == '\0') {
      knock_recovery_counter_b_ffffa74b = 0;
      if (0x3d < knock_recovery_counter_a_ffffa74a) {
        fVar1 = knock_retard_ffffa734 + 0.35;
        knock_recovery_counter_a_ffffa74a = 0;
      }
      knock_recovery_counter_a_ffffa74a = rx8_add_u8_saturate((int)(char)knock_recovery_counter_a_ffffa74a,1);
    }
    else {
      knock_recovery_counter_a_ffffa74a = 0;
      if (0x3d < knock_recovery_counter_b_ffffa74b) {
        knock_recovery_counter_b_ffffa74b = 0;
        fVar1 = knock_retard_ffffa734 + 0.35;
      }
      knock_recovery_counter_b_ffffa74b = rx8_add_u8_saturate((int)(char)knock_recovery_counter_b_ffffa74b,1);
    }
  }
  else {
    knock_recovery_counter_a_ffffa74a = 0;
    knock_recovery_counter_b_ffffa74b = 0;
  }
  knock_retard_ffffa734 = (float)knock_retard_clamp(fVar1);
  knock_retard_mirror_ffffa738 = knock_retard_ffffa734;
  return;
}


