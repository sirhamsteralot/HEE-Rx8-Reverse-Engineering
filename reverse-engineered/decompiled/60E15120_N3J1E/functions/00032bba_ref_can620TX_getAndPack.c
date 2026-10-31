/* ROM address: 0x00032bba; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00032ed6 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_can620TX_getAndPack(void)

{
  DAT_ffffbff6 = DAT_ffffbff6 + 1;
  if (0x18 < DAT_ffffbff6) {
    FUN_00032c12();
    ref_can620Pack();
    DAT_ffffbff6 = 0;
  }
  return;
}


