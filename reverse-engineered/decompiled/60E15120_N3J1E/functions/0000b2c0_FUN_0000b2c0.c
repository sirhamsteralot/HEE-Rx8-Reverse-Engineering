/* [ADDITIONAL SOURCE REVIEW]
 * ch7d_pwm_duty_write [high]: 0xb2c0(ch, fr4): a210[ch] = (u32)(fr4 * 65536.0f) (pools 0xb37c=0xffffa210, 0xb390=0x47800000); if a214[ch]==1 and ch==0: BFR7D 0xfffff596 = rx8_mul_s32_shift16_saturate(a210[0], 0xffff9f50) via 0x231c (pools 0xb380=0xffffa214, 0xb374=0xf596, 0xb38c=0xffff9f50, 0xb394=0x231c). Sole caller 0x25198 (only ROM pointer word to 0xb2c0 is 0x251cc).
 * RAM 0xffffa210 ch7d_pwm_duty_q16 (uint32): Duty percent * 65536, written by 0xb2c0 (from 0x25198, clamp 0-100% of DAT_ffffb354); BFR7D = duty*32000>>16 (0xb308/0xb2c0).
 */
/* ROM address: 0x0000b2c0; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000b2c0 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ch7d_pwm_duty_write(float param_1,byte param_2)

{
  uint uVar1;
  
  (&ch7d_pwm_duty_q16_ffffa210)[param_2] = (int)(param_1 * 65536.0);
  uVar1 = (uint)(byte)(&ch7d_pwm_enabled_ffffa214)[param_2];
  if ((uVar1 == 1) && (param_2 == 0)) {
    uVar1 = rx8_mul_s32_shift16_saturate(ch7d_pwm_duty_q16_ffffa210,ch7d_pwm_period_ffff9f50);
    ATUII_BFR7D_W = (short)uVar1;
  }
  return uVar1;
}


