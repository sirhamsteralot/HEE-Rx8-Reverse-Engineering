/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003c9e4; body bytes: 244; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003cf3c (244 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0003c9e4(void)

{
  char cVar1;
  float snapshot_inferred_ram_a984_ffffa984_ffffa984;
  
  DAT_ffffc5e4 = '\x03';
  DAT_ffffc5e5 = '\x03';
  snapshot_inferred_ram_a984_ffffa984_ffffa984 = inferred_ram_a984_ffffa984_ffffa984;
  FUN_0003cc96(inferred_ram_a984_ffffa984_ffffa984);
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc5e6 = 0;
    DAT_ffffc5e9 = '\0';
    DAT_ffffc5ea = '\0';
    DAT_ffffc5eb = 0;
    cVar1 = '\x01';
  }
  else if ((snapshot_inferred_ram_a984_ffffa984_ffffa984 < 0.2) || (4.8 < snapshot_inferred_ram_a984_ffffa984_ffffa984)) {
    if ((DAT_ffffc5e7 == '\x01') &&
       ((DAT_ffffc5e4 == '\0' && (cVar1 = ref_getFaultStatus__(0x11), cVar1 == '\0')))) {
      DAT_ffffc5e9 = '\x01';
    }
    if (((DAT_ffffc5e8 == '\x01') && (DAT_ffffc5e5 == '\0')) &&
       (cVar1 = ref_getFaultStatus__(0x12), cVar1 == '\0')) {
      DAT_ffffc5ea = '\x01';
    }
    cVar1 = '\x01';
    if ((DAT_ffffc5e9 == '\x01') || (cVar1 = DAT_ffffc5ea, DAT_ffffc5ea == '\x01')) {
      DAT_ffffc5e6 = 1;
      DAT_ffffc5eb = 0;
    }
  }
  else {
    cVar1 = ref_getFaultStatus__(0x11);
    if (cVar1 == '\0') {
      cVar1 = ref_getFaultStatus__(0x12);
      if (cVar1 == '\0') {
        DAT_ffffc5eb = 1;
        DAT_ffffc5e6 = 0;
        DAT_ffffc5e9 = '\0';
        DAT_ffffc5ea = '\0';
      }
    }
  }
  return cVar1;
}


