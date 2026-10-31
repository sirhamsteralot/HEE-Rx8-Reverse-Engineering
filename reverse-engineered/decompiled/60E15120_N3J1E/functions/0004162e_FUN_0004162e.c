/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004162e; body bytes: 142; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00040e62 (142 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004162e(void)

{
  uint uVar1;
  float snapshot_DAT_ffffb354;
  
  uVar1 = (uint)DAT_ffffd1c5;
  if (uVar1 == 1) {
    DAT_ffffc916 = 0;
    DAT_ffffc918 = 0;
  }
  else {
    snapshot_DAT_ffffb354 = DAT_ffffb354;
    if (DAT_ffffb354 < 90.0) {
      uVar1 = (uint)DAT_ffffc910;
      if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcd09, uVar1 == 0)) {
        uVar1 = rx8_add_u16_saturate((int)DAT_ffffc916,1);
        DAT_ffffc916 = (short)uVar1;
      }
      else {
        DAT_ffffc916 = 0;
      }
    }
    if (10.0 <= snapshot_DAT_ffffb354) {
      uVar1 = (uint)DAT_ffffc910;
      if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcd08, uVar1 == 1)) {
        uVar1 = rx8_add_u16_saturate((int)DAT_ffffc918,1);
        DAT_ffffc918 = (short)uVar1;
      }
      else {
        DAT_ffffc918 = 0;
      }
    }
  }
  return uVar1;
}


