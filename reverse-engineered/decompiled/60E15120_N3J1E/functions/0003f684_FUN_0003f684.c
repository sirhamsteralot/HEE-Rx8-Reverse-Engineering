/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003f684; body bytes: 136; decompiled */

uint FUN_0003f684(void)

{
  uint uVar1;
  float snapshot_DAT_ffffaa70;
  
  snapshot_DAT_ffffaa70 = DAT_ffffaa70;
  if (DAT_ffffc6df == 1) {
    if ((DAT_ffffaa70 < 0.85) && (DAT_ffffc6da < 0xc3)) {
      DAT_ffffc6da = rx8_add_u16_saturate((int)(short)DAT_ffffc6da,1);
    }
  }
  else {
    DAT_ffffc6da = 0;
  }
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc6d5 = 0;
    DAT_ffffc6d4 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffc6df;
    if (uVar1 == 1) {
      if (0.85 <= snapshot_DAT_ffffaa70) {
        DAT_ffffc6d4 = 1;
      }
      else {
        uVar1 = (uint)(short)DAT_ffffc6da;
        if (0xc2 < uVar1) {
          DAT_ffffc6d5 = 1;
        }
      }
    }
  }
  return uVar1;
}


