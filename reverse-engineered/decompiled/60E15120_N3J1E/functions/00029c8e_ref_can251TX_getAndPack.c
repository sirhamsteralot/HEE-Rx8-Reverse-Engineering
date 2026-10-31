/* ROM address: 0x00029c8e; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002a3e2 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_can251TX_getAndPack(void)

{
  DAT_ffffbb60 = DAT_ffffbb60 + 1;
  if (1 < DAT_ffffbb60) {
    FUN_00029d00();
    ref_can215TXpack();
    DAT_ffffbb60 = 0;
  }
  return;
}


