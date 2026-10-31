/* ROM address: 0x000548d0; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000529bc (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_000548d0(undefined1 *param_1,char *param_2,undefined2 param_3)

{
  *param_2 = *param_2 + '\x01';
  *param_1 = (char)((ushort)param_3 >> 8);
  *param_2 = *param_2 + '\x01';
  param_1[1] = (char)param_3;
  return param_1 + 2;
}


