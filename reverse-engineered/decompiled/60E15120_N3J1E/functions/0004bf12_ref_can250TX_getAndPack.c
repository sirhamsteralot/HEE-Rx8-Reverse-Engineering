/* ROM address: 0x0004bf12; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004b0ca (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_can250TX_getAndPack(void)

{
  DAT_ffffce8c = DAT_ffffce8c + 1;
  if (0x18 < DAT_ffffce8c) {
    ref_can250TX_pack();
    DAT_ffffce8c = 0;
  }
  return;
}


