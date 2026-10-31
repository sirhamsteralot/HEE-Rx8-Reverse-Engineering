/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003af10; body bytes: 230; decompiled */

uint FUN_0003af10(void)

{
  char cVar2;
  uint uVar1;
  float snapshot_DAT_ffffb2f0;
  
  snapshot_DAT_ffffb2f0 = DAT_ffffb2f0;
  cVar2 = rx8_is_outside_tolerance_band(DAT_ffffb2f0,0x42c80000,0x3727c5ac);
  uVar1 = 1;
  if ((DAT_ffffd1c5 == '\x01') || (uVar1 = (uint)DAT_ffffd1ad, uVar1 == 1)) {
    DAT_ffffc57d = '\0';
    DAT_ffffc57f = '\0';
    DAT_ffffc57e = '\0';
    DAT_ffffc580 = '\0';
  }
  else {
    if ((snapshot_DAT_ffffb2f0 == 0.0) && (DAT_ffffd18c == 0)) {
      uVar1 = (uint)DAT_ffffc57d;
      if (DAT_ffffc57d != -1) {
        uVar1 = uVar1 + 1;
        DAT_ffffc57d = (char)uVar1;
      }
    }
    else {
      DAT_ffffc57d = '\0';
    }
    if ((snapshot_DAT_ffffb2f0 == 0.0) && (uVar1 = (uint)DAT_ffffd18c, uVar1 == 1)) {
      if (DAT_ffffc57f != -1) {
        DAT_ffffc57f = DAT_ffffc57f + '\x01';
      }
    }
    else {
      DAT_ffffc57f = '\0';
    }
    if ((cVar2 == '\0') && (uVar1 = (uint)DAT_ffffd18c, uVar1 == 1)) {
      if (DAT_ffffc57e != -1) {
        DAT_ffffc57e = DAT_ffffc57e + '\x01';
      }
    }
    else {
      DAT_ffffc57e = '\0';
    }
    if ((cVar2 == '\0') && (DAT_ffffd18c == 0)) {
      if (DAT_ffffc580 != -1) {
        DAT_ffffc580 = DAT_ffffc580 + '\x01';
      }
    }
    else {
      DAT_ffffc580 = '\0';
    }
  }
  return uVar1;
}


