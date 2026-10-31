/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00058b52; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00056fb6 (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00058b52(void)

{
  byte snapshot_DAT_ffffd239;
  byte snapshot_DAT_ffffd23a;
  uint uVar3;
  
  snapshot_DAT_ffffd23a = DAT_ffffd23a;
  snapshot_DAT_ffffd239 = DAT_ffffd239;
  FUN_00058b40();
  if (DAT_ffffd1c5 == '\x01') {
    uVar3 = FUN_00058bb4();
    return uVar3;
  }
  uVar3 = (uint)(char)snapshot_DAT_ffffd239;
  if (((uVar3 != 0) || (uVar3 = (uint)DAT_ffffd239, uVar3 != 1)) &&
     ((snapshot_DAT_ffffd23a != 0 || (uVar3 = (uint)DAT_ffffd23a, uVar3 != 1)))) {
    return uVar3;
  }
  uVar3 = FUN_00058bf4();
  return uVar3;
}


