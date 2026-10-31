/* ROM address: 0x00028bb2; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002955a (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_can420TX_getAndPack(void)

{
  DAT_ffffbab4 = DAT_ffffbab4 + 1;
  if (0x18 < DAT_ffffbab4) {
    ref_updateCAN420Data();
    ref_can420TXPack();
    DAT_ffffbab4 = 0;
  }
  return;
}


