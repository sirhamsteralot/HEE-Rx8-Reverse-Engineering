/* ROM address: 0x00001fe2; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001fe2 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte FUN_00001fe2(uint param_1)

{
  return (&HCAN0_MC0_1__B)[(param_1 & 0xf) * 8] & 0xf;
}


