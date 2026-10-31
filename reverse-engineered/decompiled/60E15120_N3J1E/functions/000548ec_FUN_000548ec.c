/* ROM address: 0x000548ec; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000529d8 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_000548ec(undefined1 *param_1,char *param_2,undefined4 param_3)

{
  *param_2 = *param_2 + '\x01';
  *param_1 = (char)((uint)param_3 >> 0x18);
  *param_2 = *param_2 + '\x01';
  param_1[1] = (char)((uint)param_3 >> 0x10);
  *param_2 = *param_2 + '\x01';
  param_1[2] = (char)((uint)param_3 >> 8);
  *param_2 = *param_2 + '\x01';
  param_1[3] = (char)param_3;
  return param_1 + 4;
}


