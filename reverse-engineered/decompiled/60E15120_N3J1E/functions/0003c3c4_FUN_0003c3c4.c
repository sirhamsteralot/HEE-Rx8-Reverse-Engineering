/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003c3c4; body bytes: 280; decompiled */

char FUN_0003c3c4(void)

{
  char cVar1;
  float snapshot_DAT_ffffad10;
  
  snapshot_DAT_ffffad10 = DAT_ffffad10;
  ref_adcVoltageOutOfRangeCheck_(DAT_ffffad10);
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc5d0 = '\r';
    DAT_ffffc5d1 = '\r';
    DAT_ffffc5d4 = '\0';
    DAT_ffffc5d5 = '\0';
    DAT_ffffc5d6 = 0;
    DAT_ffffc5d7 = 0;
    cVar1 = '\x01';
  }
  else if ((snapshot_DAT_ffffad10 < 0.2) || (4.8 < snapshot_DAT_ffffad10)) {
    if (DAT_ffffc5d2 == '\x01') {
      if (DAT_ffffc5d0 == '\0') {
        cVar1 = ref_getFaultStatus__(0xc);
        if (cVar1 == '\0') {
          DAT_ffffc5d4 = '\x01';
        }
      }
      else {
        DAT_ffffc5d0 = DAT_ffffc5d0 + -1;
      }
    }
    if (DAT_ffffc5d3 == '\x01') {
      if (DAT_ffffc5d1 == '\0') {
        cVar1 = ref_getFaultStatus__(0xd);
        if (cVar1 == '\0') {
          DAT_ffffc5d5 = '\x01';
        }
      }
      else {
        DAT_ffffc5d1 = DAT_ffffc5d1 + -1;
      }
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
        DAT_ffffc5d0 = '\r';
        DAT_ffffc5d1 = '\r';
        DAT_ffffc5d7 = 0;
        DAT_ffffc5d4 = '\0';
        DAT_ffffc5d5 = '\0';
      }
    }
  }
  return cVar1;
}


