/* ROM address: 0x0003c55e; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003c992 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_adcVoltageOutOfRangeCheck_(float param_1)

{
  DAT_ffffc5d2 = param_1 < 0.2;
  DAT_ffffc5d3 = 4.8 < param_1;
  return;
}


