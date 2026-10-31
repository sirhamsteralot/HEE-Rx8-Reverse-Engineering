/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005820e; body bytes: 72; decompiled */

uint FUN_0005820e(void)

{
  byte snapshot_DAT_ffffd230;
  uint uVar2;
  
  snapshot_DAT_ffffd230 = DAT_ffffd230;
  FUN_000581fc();
  uVar2 = (uint)DAT_ffffd1c5;
  if (uVar2 == 1) {
    FUN_0005825c();
    uVar2 = FUN_000582e0();
    return uVar2;
  }
  if ((snapshot_DAT_ffffd230 == 0) && (uVar2 = (uint)DAT_ffffd230, uVar2 == 1)) {
    FUN_00058262();
    uVar2 = FUN_0005831c();
    return uVar2;
  }
  return uVar2;
}


