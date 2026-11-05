/* ROM address: 0x0000b2c0; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000b2c0 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0000b2c0(float param_1,byte param_2)

{
  uint uVar1;
  
  (&ch7d_pwm_duty_q16_ffffa210)[param_2] = (int)(param_1 * 65536.0);
  uVar1 = (uint)(byte)(&ch7d_pwm_enabled_ffffa214)[param_2];
  if ((uVar1 == 1) && (param_2 == 0)) {
    uVar1 = rx8_mul_s32_shift16_saturate(ch7d_pwm_duty_q16_ffffa210,DAT_ffff9f50);
    ATUII_BFR7D_W = (short)uVar1;
  }
  return uVar1;
}


