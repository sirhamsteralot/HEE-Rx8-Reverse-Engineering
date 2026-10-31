/* ROM address: 0x0004be16; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004afce (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_can240TX_getAndPack(void)

{
  DAT_ffffce78 = DAT_ffffce78 + 1;
  if (0x18 < DAT_ffffce78) {
    ref_can240TX_pack();
    DAT_ffffce78 = 0;
  }
  return;
}


