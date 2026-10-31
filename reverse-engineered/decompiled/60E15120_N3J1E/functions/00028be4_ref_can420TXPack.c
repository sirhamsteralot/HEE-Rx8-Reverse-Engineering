/* ROM address: 0x00028be4; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002958c (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_can420TXPack(void)

{
  DAT_ffffbaa4 = DAT_ffffbaac;
  DAT_ffffbaa5 = DAT_ffffbaad;
  DAT_ffffbaa6 = (undefined1)((ushort)DAT_ffffbaae >> 8);
  DAT_ffffbaa7 = (undefined1)DAT_ffffbaae;
  DAT_ffffbaa8 = DAT_ffffbab0;
  DAT_ffffbaa9 = (undefined1)((ushort)DAT_ffffbab2 >> 8);
  DAT_ffffbaaa = (undefined1)DAT_ffffbab2;
  ref_txCAN_EventBased(&DAT_0004df6c);
  return;
}


