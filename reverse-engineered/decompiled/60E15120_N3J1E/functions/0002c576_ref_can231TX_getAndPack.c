/* ROM address: 0x0002c576; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002cd2e (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_can231TX_getAndPack(void)

{
  DAT_ffffbc64 = DAT_ffffbc64 + 1;
  if (3 < DAT_ffffbc64) {
    FUN_0002c5d2();
    ref_canPackandTx231();
    DAT_ffffbc64 = 0;
  }
  return;
}


