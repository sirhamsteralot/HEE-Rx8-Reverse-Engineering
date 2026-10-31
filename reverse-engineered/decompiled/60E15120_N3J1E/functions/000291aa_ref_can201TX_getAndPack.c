/* ROM address: 0x000291aa; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00029b52 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_can201TX_getAndPack(void)

{
  DAT_ffffbb0c = DAT_ffffbb0c + 1;
  if (3 < DAT_ffffbb0c) {
    ref_getCAN201Values();
    can201_pack_and_queue_payload();
    DAT_ffffbb0c = 0;
  }
  return;
}


