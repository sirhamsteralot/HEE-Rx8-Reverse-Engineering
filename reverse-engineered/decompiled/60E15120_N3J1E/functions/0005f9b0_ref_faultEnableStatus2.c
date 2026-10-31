/* ROM address: 0x0005f9b0; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e2bc (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool ref_faultEnableStatus2(uint param_1,byte param_2)

{
  return (param_2 & (&DAT_0007e790)[param_1 & 0xffff]) == 0;
}


