/* ROM address: 0x000666aa; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064f9a (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000666aa(byte param_1,uint param_2)

{
  return (&DAT_0005ec9c)[(param_1 - 1) * 8 + ((param_2 & 0xff) >> 5)];
}


