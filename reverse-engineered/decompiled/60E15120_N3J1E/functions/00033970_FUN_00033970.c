/* [ADDITIONAL SOURCE REVIEW]
 * knock_attack_condition [high]: Sets c05c: knock latched (c078) && engine running (a428) && run timer >= 0xfa && leading and trailing timing both > 5 deg - thresholdA*0.15625 where thresholdA = raw u16 c090 (timing not already deeply retarded).
 * RAM 0xffffc078 knock_detected_latched (uint8): 0x336c4 latches a324 here; 0x33970 requires it for the attack condition c05c.
 * RAM 0xffffc090 knock_threshold_a_raw (uint16): Raw u16 threshold A from tbl 0x6b270 (or alt 0x6b27c when cd60 set); moved to a37e.
 */
/* ROM address: 0x00033970; body bytes: 122; decompiled */

undefined4 * knock_attack_condition(void)

{
  undefined4 *puVar1;
  float fVar2;
  
  fVar2 = (float)rx8_decode_u16_affine(0x3e200000,0,(int)knock_threshold_a_raw_ffffc090);
  puVar1 = (undefined4 *)0x0;
  if ((((knock_detected_latched_ffffc078 == 0) || (puVar1 = (undefined4 *)&engine_running_ffffa428, engine_running_ffffa428 == '\0')) ||
      (puVar1 = (undefined4 *)&DAT_0007a212, engine_running_timer_ffffa424 < 0xfa)) ||
     ((puVar1 = &DAT_00033a48, leading_ignition_timing_ffffa630 <= 5.0 - fVar2 ||
      (puVar1 = &DAT_00033a48, trailing_ignition_timing_ffffa638 <= 5.0 - fVar2)))) {
    knock_attack_condition_ffffc05c = 0;
  }
  else {
    puVar1 = (undefined4 *)(uint)knock_detected_latched_ffffc078;
    if (puVar1 == (undefined4 *)((int)&vector_Poweron_Reset + 1)) {
      knock_attack_condition_ffffc05c = 1;
    }
  }
  return puVar1;
}


