/* ROM address: 0x00002044; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002044 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_invertAndReturn_8bit_ADDR(short *param_1)

{
  return ~(int)*param_1 - ((uint)(int)*param_1 >> 8) & 0xff;
}


