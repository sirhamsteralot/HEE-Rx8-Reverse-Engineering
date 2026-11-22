/* [ADDITIONAL SOURCE REVIEW]
 * ch7d_pwm_duty_ratio [high]: b570 = clamp(b354, 0, 100.0f) / 100.0f (pools 0x251c0=0xb354, 0x251c2=0xb570, 0x251c4=0x42c80000, helper 0x251c8=0x2404), then tail jmp 0xb2c0 (pool 0x251cc) with r4=0. Called from 0x2253c.
 */
/* ROM address: 0x00025198; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025a20 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ch7d_pwm_duty_ratio(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 100.0;
  fVar1 = rx8_clamp_float(ch7d_pwm_duty_percent_ffffb354,0.0,100.0);
  inferred_ram_b570_ffffb570_ffffb570 = fVar1 / fVar2;
  ch7d_pwm_duty_write(0);
  return;
}


