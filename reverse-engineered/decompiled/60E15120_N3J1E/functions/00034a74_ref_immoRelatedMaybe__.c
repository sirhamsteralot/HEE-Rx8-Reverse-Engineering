/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00034a74; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035194 (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

int ref_immoRelatedMaybe__(void)

{
  int snapshot_DAT_ffffc270;
  int iVar2;
  
  snapshot_DAT_ffffc270 = DAT_ffffc270;
  DAT_ffffc20c = 500;
  DAT_ffffc210 = 0xfa;
  DAT_ffffc222 = 1;
  DAT_ffffc21e = 5;
  iVar2 = DAT_ffffc26c;
  if ((DAT_ffffc26c == -1) && (iVar2 = snapshot_DAT_ffffc270, DAT_ffffc270 == -1)) {
    DAT_ffffc26c = 0x10001;
    DAT_ffffc270 = 0x55aa55aa;
  }
  if (((DAT_ffffc27a == -1) && (DAT_ffffc27c == -1)) || ((DAT_ffffc27a == 0 && (DAT_ffffc27c == 0)))
     ) {
    iVar2 = 0x55aa;
    DAT_ffffc27a = 0x55aa;
    DAT_ffffc27c = -0x481d;
  }
  return iVar2;
}


