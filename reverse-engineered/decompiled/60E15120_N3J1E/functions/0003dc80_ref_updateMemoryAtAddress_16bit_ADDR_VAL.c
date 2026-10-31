/* ROM address: 0x0003dc80; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003e208 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_updateMemoryAtAddress_16bit_ADDR_VAL(int *param_1,ushort param_2)

{
  *param_1 = (uint)param_2 * 0x10000 + (uint)(ushort)~param_2;
  return 0;
}


