/* ROM address: 0x00001182; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001182 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001182(void)

{
  HCAN0_RXPR_W = 0x40;
  HCAN0_UMSR_W = 0x40;
  return;
}


