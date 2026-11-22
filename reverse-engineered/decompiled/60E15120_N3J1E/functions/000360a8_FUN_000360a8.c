/* [ADDITIONAL SOURCE REVIEW]
 * immo_key_regs_mix_timer [medium]: 32 B, unique_exact_bytes to 60E0FC00 0x367c8. c26c ^= ATUII_TCNT0H_W; c270 ^= (TCNT0>>16) + TCNT0*0x10000. Called in the dispatcher tail chain.
 */
/* ROM address: 0x000360a8; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000367c8 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000360a8(void)

{
  uint uVar1;
  
  uVar1 = ATUII_TCNT0H_W;
  DAT_ffffc26c = DAT_ffffc26c ^ uVar1;
  DAT_ffffc270 = DAT_ffffc270 ^ (uVar1 >> 0x10) + uVar1 * 0x10000;
  return;
}


