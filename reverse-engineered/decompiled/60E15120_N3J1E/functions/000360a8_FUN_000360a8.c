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


