/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005866e; body bytes: 64; decompiled */

uint FUN_0005866e(void)

{
  byte snapshot_DAT_ffffd232;
  uint uVar2;
  
  snapshot_DAT_ffffd232 = DAT_ffffd232;
  FUN_0005865c();
  uVar2 = (uint)DAT_ffffd1c5;
  if (uVar2 == 1) {
    uVar2 = FUN_000586fa();
    return uVar2;
  }
  if ((snapshot_DAT_ffffd232 == 0) && (uVar2 = (uint)DAT_ffffd232, uVar2 == 1)) {
    uVar2 = FUN_00058700();
    return uVar2;
  }
  return uVar2;
}


