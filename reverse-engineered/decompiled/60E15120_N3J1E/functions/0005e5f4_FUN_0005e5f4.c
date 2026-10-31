/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005e5f4; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ce00 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005e5f4(void)

{
  uint uVar1;
  float snapshot_DAT_ffffad20;
  
  uVar1 = (uint)DAT_ffffaa81;
  if (uVar1 == 1) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff9174,0);
  }
  snapshot_DAT_ffffad20 = DAT_ffffad20;
  if ((0.55 <= DAT_ffffad20) && (DAT_ffffd38c < 0.55)) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff9176,0);
  }
  DAT_ffffd38c = snapshot_DAT_ffffad20;
  return uVar1;
}


