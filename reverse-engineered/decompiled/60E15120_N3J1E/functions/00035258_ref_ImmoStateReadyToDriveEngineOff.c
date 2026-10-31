/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00035258; body bytes: 108; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035978 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_ImmoStateReadyToDriveEngineOff(void)

{
  int snapshot_DAT_ffffc208;
  uint uVar2;
  
  snapshot_DAT_ffffc208 = DAT_ffffc208;
  uVar2 = (uint)DAT_ffffc21e;
  if (uVar2 != 1) {
    DAT_ffffc21e = 5;
    if (DAT_ffffc212 != 0) {
      DAT_ffffc212 = DAT_ffffc212 + -1;
    }
    if (DAT_ffffc212 == 0) {
      ref_ImmoBadStateSet_();
      DAT_ffffc21d = 5;
      uVar2 = FUN_00035738(200);
      DAT_ffffc212 = 500;
    }
    return uVar2;
  }
  while (DAT_ffffc208 == snapshot_DAT_ffffc208) {
    ref_Immo_Keygen_related_ADC();
  }
  DAT_ffffc20c = 500;
  uVar2 = FUN_00034e68();
  return uVar2;
}


