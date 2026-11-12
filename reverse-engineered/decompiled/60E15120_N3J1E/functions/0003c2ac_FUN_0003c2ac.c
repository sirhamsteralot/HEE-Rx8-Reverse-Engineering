/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003c2ac; body bytes: 244; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003c6e0 (244 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0003c2ac(void)

{
  char cVar1;
  float snapshot_inferred_ram_ad10_ffffad10_ffffad10;
  
  DAT_ffffc5d0 = '\r';
  DAT_ffffc5d1 = '\r';
  snapshot_inferred_ram_ad10_ffffad10_ffffad10 = inferred_ram_ad10_ffffad10_ffffad10;
  ref_adcVoltageOutOfRangeCheck_(inferred_ram_ad10_ffffad10_ffffad10);
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc5d4 = '\0';
    DAT_ffffc5d5 = '\0';
    DAT_ffffc5d6 = 0;
    DAT_ffffc5d7 = 0;
    cVar1 = '\x01';
  }
  else if ((snapshot_inferred_ram_ad10_ffffad10_ffffad10 < 0.2) || (4.8 < snapshot_inferred_ram_ad10_ffffad10_ffffad10)) {
    if ((DAT_ffffc5d2 == '\x01') &&
       ((DAT_ffffc5d0 == '\0' && (cVar1 = ref_getFaultStatus__(0xc), cVar1 == '\0')))) {
      DAT_ffffc5d4 = '\x01';
    }
    if (((DAT_ffffc5d3 == '\x01') && (DAT_ffffc5d1 == '\0')) &&
       (cVar1 = ref_getFaultStatus__(0xd), cVar1 == '\0')) {
      DAT_ffffc5d5 = '\x01';
    }
    cVar1 = '\x01';
    if ((DAT_ffffc5d4 == '\x01') || (cVar1 = DAT_ffffc5d5, DAT_ffffc5d5 == '\x01')) {
      DAT_ffffc5d7 = 1;
      DAT_ffffc5d6 = 0;
    }
  }
  else {
    cVar1 = ref_getFaultStatus__(0xc);
    if (cVar1 == '\0') {
      cVar1 = ref_getFaultStatus__(0xd);
      if (cVar1 == '\0') {
        DAT_ffffc5d6 = 1;
        DAT_ffffc5d7 = 0;
        DAT_ffffc5d4 = '\0';
        DAT_ffffc5d5 = '\0';
      }
    }
  }
  return cVar1;
}


