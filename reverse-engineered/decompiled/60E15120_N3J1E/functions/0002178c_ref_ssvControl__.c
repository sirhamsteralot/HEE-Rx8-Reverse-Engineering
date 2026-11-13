/* [ADDITIONAL SOURCE REVIEW]
 * ssv_solenoid_control [high]: Writes PEDR_W 0xfffff754 bit 0x80 (PE7, SH7055F pkg pin 16) via ref_setRegister_REG_BIT_VAL after diag override 0x5c9ac. On-condition: coolant hysteresis 197/200 C (b2b4), counter b2b2=0xbc, (aa68==0 && b2b5 prev) || becd. Harness: SSV solenoid PCM 1L (position switch is separate, PCM 1D). Reached from task 0x64f6 -> 0x11744 -> 0x21766.
 * RAM 0xffffb2b0 ssv_diag_override_result (uint8): Result of ssv_diag_override (0x5c9ac); 1 -> PEDR PE7 set.
 * RAM 0xffffb2b2 ssv_on_counter (uint8): Set to 0xbc when (aa68==0 && b2b5==1), else decremented; gates SSV on with b2b4.
 * RAM 0xffffb2b4 ssv_coolant_hot_flag (uint8): coolant >= 200 (clear below 197) hysteresis; blocks SSV on-condition.
 * RAM 0xffffb2b5 ssv_was_enabled (uint8): previous aa68 snapshot; edge term in the on-condition.
 */
/* ROM address: 0x0002178c; body bytes: 250; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000220f8 (250 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Candidate SSV control. Firmware fact: writes mask 0x0080 of 0xfffff754 (PEDR_W, PE7 = SH7055F pkg pin 16) via 0x4bbc after diagnostic arbitration. Pinout v3 (mazda-rx-8-pcm-pinout-series-1.pdf, 2026-10-30): SSV solenoid control at PCM 1L, wire L/Y (confirmed); SSV position switch at PCM 1D, wire L (confirmed). Chip-pin -> terminal routing still board-level unresolved. */

void ssv_solenoid_control(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_1c;
  undefined4 auStack_18 [2];
  
  cVar1 = engine_running_flag_ffffaa68;
  if (inferred_coolant_temperature_ffffa98c < 200.0) {
    if (inferred_coolant_temperature_ffffa98c < 197.0) {
      ssv_coolant_hot_flag_ffffb2b4 = '\0';
    }
  }
  else {
    ssv_coolant_hot_flag_ffffb2b4 = '\x01';
  }
  if ((engine_running_flag_ffffaa68 == '\0') && (ssv_was_enabled_ffffb2b5 == '\x01')) {
    ssv_on_counter_ffffb2b2 = 0xbc;
  }
  else if (ssv_on_counter_ffffb2b2 != 0) {
    ssv_on_counter_ffffb2b2 = ssv_on_counter_ffffb2b2 + -1;
  }
  if ((secondary_injectors_active_flag_ffffbecd == '\x01') ||
     (((engine_running_flag_ffffaa68 == '\0' && (ssv_on_counter_ffffb2b2 != 0)) && (ssv_coolant_hot_flag_ffffb2b4 == '\0')))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  ssv_diag_override_result_ffffb2b0 = candidate_ssv_diag_override(uVar2);
  if (ssv_diag_override_result_ffffb2b0 == '\x01') {
    ref_setSR_PARAM(auStack_18,0xe0);
    ref_setRegister_REG_BIT_VAL(0xfffff754,0x80,1);
  }
  else {
    ref_setSR_PARAM(&local_1c,0xe0);
    ref_setRegister_REG_BIT_VAL(0xfffff754,0x80,0);
    auStack_18[0] = local_1c;
  }
  FUN_00002064(auStack_18[0]);
  ssv_was_enabled_ffffb2b5 = cVar1;
  return;
}


