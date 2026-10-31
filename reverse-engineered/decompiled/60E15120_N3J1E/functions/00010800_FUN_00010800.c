/* ROM address: 0x00010800; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000107f4 (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00010800(int param_1,int param_2)

{
  param_2 = param_2 - param_1;
  if (param_2 < -0x1dffff) {
    param_2 = param_2 + 0x1680000;
  }
  return param_2;
}


