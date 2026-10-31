/* ROM address: 0x00060dae; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f69e (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00060dae(uint param_1,uint param_2)

{
  if (((&DAT_ffff8d54)[(param_1 & 0xffff) * 2] != ' ') &&
     (param_2 = param_2 + 1, (uint)(byte)(&DAT_0007e3b6)[param_1 & 0xffff] <= (param_2 & 0x7f))) {
    param_2 = 0xc0;
  }
  return param_2;
}


