/* ROM address: 0x000640f4; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000629e4 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000640f4(uint param_1,uint param_2)

{
  if (((&DAT_ffff8d54)[(param_1 & 0xffff) * 2] != ' ') &&
     (param_2 = param_2 + 1, (uint)(byte)(&DAT_0007e3b6)[param_1 & 0xffff] <= (param_2 & 0x7f))) {
    param_2 = 0xc0;
  }
  return param_2;
}


