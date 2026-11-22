/* [ADDITIONAL SOURCE REVIEW]
 * ch7d_pwm_off_init [high]: Init (from mainInit 0x61a8 chain): a214=0, a210=0, TSTR2 0xfffff400 bit7 clear, CYLR7D/TCNT7D/BFR7D/DTR7D=1 then BFR7D=0, TSTR2 bit7 set (pools 0xb36c=0xe0/0xf400, 0xb36e=0xf400, 0xb370=0xf58e/0xf586, 0xb374=0xf596/0xf59e, 0xb37c=0xffffa210, 0xb380=0xffffa214, 0xb378=0x7d00).
 */
/* ROM address: 0x0000b23c; body bytes: 84; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0000b25e) */
/* Unique exact-byte match to related 60E0FC00 function at 0000b23c (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ch7d_pwm_off_init(void)

{
  byte bVar1;
  undefined4 local_10 [2];
  
  ch7d_pwm_enabled_ffffa214 = 0;
  ch7d_pwm_duty_q16_ffffa210 = 0;
  ref_setSR_PARAM(local_10,0xe0);
  bVar1 = ATUII_TSTR2_B;
  ATUII_TSTR2_B = bVar1 & 0x7f;
  ATUII_CYLR7D_W = 1;
  ATUII_TCNT7D_W = 1;
  ATUII_BFR7D_W = 1;
  ATUII_DTR7D_W = 1;
  ATUII_BFR7D_W = 0;
  bVar1 = ATUII_TSTR2_B;
  ATUII_TSTR2_B = bVar1 | 0x80;
  FUN_00002064(local_10[0]);
  return;
}


