/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000588ce; body bytes: 92; decompiled */

uint FUN_000588ce(void)

{
  byte snapshot_DAT_ffffd235;
  byte snapshot_DAT_ffffd236;
  uint uVar3;
  
  snapshot_DAT_ffffd236 = DAT_ffffd236;
  snapshot_DAT_ffffd235 = DAT_ffffd235;
  FUN_000588bc();
  if (DAT_ffffd1c5 == '\x01') {
    uVar3 = FUN_00058930();
    return uVar3;
  }
  uVar3 = (uint)(char)snapshot_DAT_ffffd235;
  if (((uVar3 != 0) || (uVar3 = (uint)DAT_ffffd235, uVar3 != 1)) &&
     ((snapshot_DAT_ffffd236 != 0 || (uVar3 = (uint)DAT_ffffd236, uVar3 != 1)))) {
    return uVar3;
  }
  uVar3 = FUN_00058974();
  return uVar3;
}


