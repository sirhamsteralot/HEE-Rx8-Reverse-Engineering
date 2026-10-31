/* ROM address: 0x0002c5a8; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002cd60 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_canPackandTx231(void)

{
  DAT_ffffbc58 = DAT_ffffbc5d;
  DAT_ffffbc59 = DAT_ffffbc5e;
  DAT_ffffbc5a = (undefined1)((ushort)DAT_ffffbc60 >> 8);
  DAT_ffffbc5b = (undefined1)DAT_ffffbc60;
  DAT_ffffbc5c = DAT_ffffbc62;
  ref_txCAN_EventBased(&DAT_0004df4c);
  return;
}


