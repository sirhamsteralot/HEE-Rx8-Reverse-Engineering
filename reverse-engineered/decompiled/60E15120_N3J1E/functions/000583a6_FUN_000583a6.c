/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000583a6; body bytes: 88; decompiled */

uint FUN_000583a6(void)

{
  byte snapshot_DAT_ffffd231;
  uint uVar2;
  
  snapshot_DAT_ffffd231 = DAT_ffffd231;
  FUN_00058394();
  uVar2 = (uint)DAT_ffffd1c5;
  if (uVar2 == 1) {
    FUN_00058404();
    FUN_000584a8();
    FUN_00058516();
    uVar2 = FUN_000585c2();
    return uVar2;
  }
  if ((snapshot_DAT_ffffd231 == 0) && (uVar2 = (uint)DAT_ffffd231, uVar2 == 1)) {
    FUN_00058440();
    FUN_000584ae();
    FUN_0005851c();
    uVar2 = FUN_000585c8();
    return uVar2;
  }
  return uVar2;
}


