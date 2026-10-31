/* ROM address: 0x0004bf40; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004b0f8 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_can250TX_pack(void)

{
  DAT_ffffce7c = DAT_ffffce84;
  DAT_ffffce7d = DAT_ffffce85;
  DAT_ffffce7e = DAT_ffffce86;
  DAT_ffffce7f = DAT_ffffce87;
  DAT_ffffce80 = (undefined1)((ushort)DAT_ffffce88 >> 8);
  DAT_ffffce81 = (undefined1)DAT_ffffce88;
  DAT_ffffce82 = DAT_ffffce8a;
  DAT_ffffce83 = DAT_ffffce8b;
  ref_txCAN_EventBased(&DAT_0004dfcc);
  return;
}


