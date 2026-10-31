/* ROM address: 0x0003dc70; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003e1f8 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_updateMemoryAtAddress_8bit_ADDR_VAL(short *param_1,ushort param_2)

{
  *param_1 = param_2 * 0x100 + (~param_2 & 0xff);
  return 0;
}


