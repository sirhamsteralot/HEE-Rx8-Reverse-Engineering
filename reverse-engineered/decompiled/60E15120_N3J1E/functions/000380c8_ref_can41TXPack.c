/* ROM address: 0x000380c8; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000387e8 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_can41TXPack(void)

{
  uint uVar1;
  
  if (DAT_ffffc1d1 != 1) {
    return (uint)DAT_ffffc1d1;
  }
  DAT_ffffc4a8 = DAT_ffffc1c8;
  DAT_ffffc4a9 = DAT_ffffc1c9;
  DAT_ffffc4aa = DAT_ffffc1ca;
  DAT_ffffc4ab = DAT_ffffc1cb;
  DAT_ffffc4ac = DAT_ffffc1cc;
  DAT_ffffc4ad = DAT_ffffc1cd;
  DAT_ffffc4ae = DAT_ffffc1ce;
  DAT_ffffc4af = DAT_ffffc1cf;
  uVar1 = ref_txCAN_EventBased(&DAT_0004dfac);
  return uVar1;
}


