/* ROM address: 0x00002034; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002034 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00002034(uint *param_1)

{
  return ~*param_1 - (*param_1 >> 0x10) & 0xffff;
}


