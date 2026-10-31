/* ROM address: 0x00032ac6; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00032de2 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_can630TX_getAndPack(void)

{
  DAT_ffffbfe8 = DAT_ffffbfe8 + 1;
  if (0x18 < DAT_ffffbfe8) {
    ref_packCANTX630();
    FUN_00032af8();
    DAT_ffffbfe8 = 0;
  }
  return;
}


