/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00043100; body bytes: 136; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042934 (136 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculatedEngineAccelerationFiltered(void)

{
  float snapshot_DAT_ffffca00;
  
  if (0.5 <= DAT_ffffca08) {
    if (1.5 <= DAT_ffffca08) {
      DAT_ffffc9fc = (DAT_ffffca60 + DAT_ffffca64 + DAT_ffffca68 + DAT_ffffca00) / 4.0;
    }
    else {
      DAT_ffffc9fc = (DAT_ffffca60 + DAT_ffffca00) / 2.0;
    }
  }
  else {
    DAT_ffffc9fc = DAT_ffffca00;
  }
  snapshot_DAT_ffffca00 = DAT_ffffca00;
  DAT_ffffc9f8 = rx8_first_order_filter(DAT_ffffc9fc,DAT_ffffc9f8,1.0 - DAT_ffffca1c,1e-05);
  DAT_ffffca68 = DAT_ffffca64;
  DAT_ffffca64 = DAT_ffffca60;
  DAT_ffffca60 = snapshot_DAT_ffffca00;
  return;
}


