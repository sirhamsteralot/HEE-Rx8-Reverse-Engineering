/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003f756; body bytes: 136; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003fcf2 (136 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0003f756(void)

{
  uint uVar1;
  float snapshot_DAT_ffffaa70;
  
  snapshot_DAT_ffffaa70 = DAT_ffffaa70;
  if (DAT_ffffc6e0 == 1) {
    if ((1.15 <= DAT_ffffaa70) && (DAT_ffffc6dc < 0xc3)) {
      DAT_ffffc6dc = rx8_add_u16_saturate((int)(short)DAT_ffffc6dc,1);
    }
  }
  else {
    DAT_ffffc6dc = 0;
  }
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc6d7 = 0;
    DAT_ffffc6d6 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffc6e0;
    if (uVar1 == 1) {
      if (snapshot_DAT_ffffaa70 < 1.15) {
        DAT_ffffc6d6 = 1;
      }
      else {
        uVar1 = (uint)(short)DAT_ffffc6dc;
        if (0xc2 < uVar1) {
          DAT_ffffc6d7 = 1;
        }
      }
    }
  }
  return uVar1;
}


