/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00042f84; body bytes: 154; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000427b8 (154 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00042f84(void)

{
  char cVar2;
  int iVar1;
  float extraout_fr0;
  float fVar3;
  float snapshot_DAT_ffffca24;
  
  fVar3 = 0.0;
  snapshot_DAT_ffffca24 = DAT_ffffca24;
  cVar2 = rx8_is_outside_tolerance_band(DAT_ffffca24,0,0x3727c5ac);
  if (cVar2 != '\0') {
    DAT_ffffca38 = ((1.0 / snapshot_DAT_ffffca24) * 2000.0) / DAT_ffffca10;
  }
  iVar1 = rx8_decode_u8_affine(0x3f800000,fVar3,(int)DAT_ffffca3f);
  DAT_ffffc9d4 = fVar3;
  if (extraout_fr0 < DAT_ffffca38) {
    DAT_ffffc9d4 = DAT_ffffc9d8 / DAT_ffffc9ec;
    if (DAT_ffffca49 == '\x01') {
      DAT_ffffc9d4 = DAT_ffffc9d4 * 0.25;
      iVar1 = 1;
    }
    else {
      iVar1 = (int)DAT_ffffca48;
      if (iVar1 == 0) {
        DAT_ffffc9d4 = DAT_ffffc9d4 * 0.15;
      }
    }
  }
  return iVar1;
}


