/* ROM address: 0x00035356; body bytes: 120; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035a76 (120 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_immo_related__(void)

{
  DAT_ffffc1dc = FUN_00035438(DAT_ffffc270,DAT_ffffc208);
  DAT_ffffc1e0 = FUN_00035438(DAT_ffffc270 >> 0x10,DAT_ffffc208 >> 8);
  DAT_ffffc1e4 = FUN_00035438(DAT_ffffc26c,DAT_ffffc208 >> 0x10);
  DAT_ffffc1e8 = FUN_00035438(DAT_ffffc26c >> 0x10,DAT_ffffc208 >> 0x18);
  DAT_ffffc1f0 = DAT_ffffc1dc | 0x1000000;
  DAT_ffffc1f4 = DAT_ffffc1e0 | 0x2000000;
  DAT_ffffc1f8 = DAT_ffffc1e4 | 0x3000000;
  DAT_ffffc1fc = DAT_ffffc1e8 | 0x4000000;
  return;
}


