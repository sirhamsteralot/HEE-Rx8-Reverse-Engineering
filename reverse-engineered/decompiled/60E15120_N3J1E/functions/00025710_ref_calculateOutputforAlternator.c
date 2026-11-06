/* [ADDITIONAL SOURCE REVIEW]
 * alternator_field_pwm_output [high]: Final field PWM duty: 0xffff9f48 = rx8_mul_s32_shift16_saturate((clamp(0xffffb5ac,0,100)/100.0)*65536, period u16 at 0xffff9f44). Disasm: pool 0x2578c = 0xffff9f44 (u32 address), 0x25788 = f32 100.0, mov.w @r5 reads period, mov.w r0,@(0x4,r2) stores duty at 0xffff9f48. Called from 0x267c6 via pool 0x268a8.
 */
/* ROM address: 0x00025710; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025f98 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

void alternator_field_pwm_output(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 100.0;
  fVar1 = rx8_clamp_float(inferred_ram_b5ac_ffffb5ac_ffffb5ac,0.0,100.0);
  alternator_pwm_duty_ffff9f48 = rx8_mul_s32_shift16_saturate((int)((fVar1 / fVar2) * 65536.0),alternator_pwm_period_ffff9f44);
  return;
}


