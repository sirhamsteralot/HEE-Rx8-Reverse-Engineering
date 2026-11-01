/* ROM address: 0x0004bf7c; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004b134 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getOBDCANTXVars2(void)

{
  DAT_ffffce84 = 0;
  DAT_ffffce85 = 0;
  DAT_ffffce86 = diag_encode_leading_timing();
  DAT_ffffce87 = diag_encode_iat();
  DAT_ffffce88 = diag_encode_maf();
  DAT_ffffce8a = diag_encode_throttle_pct();
  DAT_ffffce8b = diag_read_secondary_air_status();
  return;
}


