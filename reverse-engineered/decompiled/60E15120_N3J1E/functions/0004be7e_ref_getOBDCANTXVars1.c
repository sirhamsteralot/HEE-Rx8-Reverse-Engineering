/* ROM address: 0x0004be7e; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004b036 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getOBDCANTXVars1(void)

{
  DAT_ffffce70 = diag_ol_status_byte();
  DAT_ffffce71 = diag_ol_status_low_byte();
  DAT_ffffce72 = diag_read_calc_load_pct();
  DAT_ffffce73 = diag_encode_ect_c();
  DAT_ffffce74 = diag_encode_stft_lambda();
  DAT_ffffce75 = diag_encode_ltft();
  DAT_ffffce76 = 0;
  DAT_ffffce77 = 0;
  return;
}


