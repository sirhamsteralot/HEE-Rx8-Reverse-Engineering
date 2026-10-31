/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003c6c8; body bytes: 280; decompiled */

char FUN_0003c6c8(void)

{
  char cVar1;
  float snapshot_DAT_ffffadd4;
  
  snapshot_DAT_ffffadd4 = DAT_ffffadd4;
  FUN_0003c99a(DAT_ffffadd4);
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc5d8 = '\x03';
    DAT_ffffc5d9 = '\x03';
    DAT_ffffc5db = 0;
    DAT_ffffc5de = '\0';
    DAT_ffffc5df = '\0';
    DAT_ffffc5e0 = 0;
    cVar1 = '\x01';
  }
  else if ((snapshot_DAT_ffffadd4 < 0.16) || (4.8 < snapshot_DAT_ffffadd4)) {
    if (DAT_ffffc5dc == '\x01') {
      if (DAT_ffffc5d8 == '\0') {
        cVar1 = ref_getFaultStatus__(0xf);
        if (cVar1 == '\0') {
          DAT_ffffc5de = '\x01';
        }
      }
      else {
        DAT_ffffc5d8 = DAT_ffffc5d8 + -1;
      }
    }
    if (DAT_ffffc5dd == '\x01') {
      if (DAT_ffffc5d9 == '\0') {
        cVar1 = ref_getFaultStatus__(0x10);
        if (cVar1 == '\0') {
          DAT_ffffc5df = '\x01';
        }
      }
      else {
        DAT_ffffc5d9 = DAT_ffffc5d9 + -1;
      }
    }
    cVar1 = '\x01';
    if ((DAT_ffffc5de == '\x01') || (cVar1 = DAT_ffffc5df, DAT_ffffc5df == '\x01')) {
      DAT_ffffc5db = 1;
      DAT_ffffc5e0 = 0;
    }
  }
  else {
    cVar1 = ref_getFaultStatus__(0xf);
    if (cVar1 == '\0') {
      cVar1 = ref_getFaultStatus__(0x10);
      if (cVar1 == '\0') {
        DAT_ffffc5e0 = 1;
        DAT_ffffc5d8 = '\x03';
        DAT_ffffc5d9 = '\x03';
        DAT_ffffc5db = 0;
        DAT_ffffc5de = '\0';
        DAT_ffffc5df = '\0';
      }
    }
  }
  return cVar1;
}


