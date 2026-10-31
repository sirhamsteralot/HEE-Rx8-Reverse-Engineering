/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00058a16; body bytes: 92; decompiled */

uint FUN_00058a16(void)

{
  byte snapshot_DAT_ffffd237;
  byte snapshot_DAT_ffffd238;
  uint uVar3;
  
  snapshot_DAT_ffffd238 = DAT_ffffd238;
  snapshot_DAT_ffffd237 = DAT_ffffd237;
  FUN_00058a04();
  if (DAT_ffffd1c5 == '\x01') {
    uVar3 = FUN_00058a78();
    return uVar3;
  }
  uVar3 = (uint)(char)snapshot_DAT_ffffd237;
  if (((uVar3 != 0) || (uVar3 = (uint)DAT_ffffd237, uVar3 != 1)) &&
     ((snapshot_DAT_ffffd238 != 0 || (uVar3 = (uint)DAT_ffffd238, uVar3 != 1)))) {
    return uVar3;
  }
  uVar3 = FUN_00058abc();
  return uVar3;
}


