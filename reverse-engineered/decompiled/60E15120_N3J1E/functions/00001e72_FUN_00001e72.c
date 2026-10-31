/* ROM address: 0x00001e72; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001e72 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00001e72(byte *param_1)

{
  return (uint)param_1[1] * 0x100 + (uint)*param_1 * 0x10000 + (uint)param_1[2];
}


