/* [ADDITIONAL SOURCE REVIEW]
 * apv_pwm_service [medium]: Software-PWM service: consumes pending ticks a1c4/a1c6, latches a1c0/a1c2 at period boundary, drives PLDR_W 0xfffff75e bits 0x0020 (PL5, pkg pin 221) and 0x0100 (PL8, pkg pin 224) with opposite polarity; calls apv_drive_status_sample (0xaac4) at phase 4.
 * RAM 0xffffa1c0 apv_pwm_forward_latched (uint16): Latched a1c4 at PWM period boundary.
 * RAM 0xffffa1c2 apv_pwm_reverse_latched (uint16): Latched a1c6 at PWM period boundary.
 */
/* ROM address: 0x0000a936; body bytes: 286; decompiled */

/* 
   
   [WIRING REVIEW 2026-09-08]
   Candidate APV software-PWM service. Firmware fact: drives PLDR_W 0xfffff75e masks 0x0020/0x0100 (PL5 pkg pin 221 / PL8 pkg pin 224) with opposite polarity from pending ticks 0xffffa1c4/a1c6. pinout v3: APV motor control (-) at PCM 3J wire L/R (confirmed), (+) at PCM 3G wire G/B (³) (HP ³); per-bit-to-terminal polarity still unverified. */

undefined2 * apv_pwm_service(void)

{
  undefined2 *puVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 auStack_24 [2];
  
  DAT_ffffa1be = DAT_ffffa1be + 1;
  if ((undefined2 *)(uint)DAT_ffffa1be < (undefined2 *)0x60) {
    puVar1 = (undefined2 *)(uint)apv_pwm_forward_latched_ffffa1c0;
    if ((puVar1 <= (undefined2 *)(uint)DAT_ffffa1be) &&
       (puVar1 = (undefined2 *)(uint)DAT_ffffa1c8,
       puVar1 == (undefined2 *)((int)&vector_Poweron_Reset + 1))) {
      DAT_ffffa1c8 = 0;
      ref_setSR_PARAM(&uStack_2c,0xe0);
      ref_setRegister_REG_BIT_VAL(0xfffff75e,0x20,1);
      puVar1 = (undefined2 *)FUN_00002064(uStack_2c);
    }
    if ((apv_pwm_reverse_latched_ffffa1c2 <= DAT_ffffa1be) &&
       (puVar1 = (undefined2 *)(uint)DAT_ffffa1c9,
       puVar1 == (undefined2 *)((int)&vector_Poweron_Reset + 1))) {
      DAT_ffffa1c9 = 0;
      ref_setSR_PARAM(&local_30,0xe0);
      ref_setRegister_REG_BIT_VAL(0xfffff75e,0x100,0);
      puVar1 = (undefined2 *)FUN_00002064(local_30);
    }
  }
  else {
    DAT_ffffa1be = 0;
    apv_pwm_forward_latched_ffffa1c0 = apv_pwm_forward_ticks_ffffa1c4;
    apv_pwm_reverse_latched_ffffa1c2 = apv_pwm_reverse_ticks_ffffa1c6;
    if (apv_pwm_forward_ticks_ffffa1c4 != 0) {
      ref_setSR_PARAM(auStack_24,0xe0);
      ref_setRegister_REG_BIT_VAL(0xfffff75e,0x20,0);
      FUN_00002064(auStack_24[0]);
      DAT_ffffa1c8 = 1;
    }
    puVar1 = &apv_pwm_reverse_latched_ffffa1c2;
    if (apv_pwm_reverse_latched_ffffa1c2 != 0) {
      ref_setSR_PARAM(&uStack_28,0xe0);
      ref_setRegister_REG_BIT_VAL(0xfffff75e,0x100,1);
      puVar1 = (undefined2 *)FUN_00002064(uStack_28);
      DAT_ffffa1c9 = 1;
    }
  }
  if (DAT_ffffa1be == 4) {
    puVar1 = (undefined2 *)apv_drive_status_sample();
  }
  return puVar1;
}


