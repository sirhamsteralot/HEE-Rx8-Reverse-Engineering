/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00058790; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00056bf4 (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00058790(void)

{
  byte snapshot_DAT_ffffd233;
  byte snapshot_DAT_ffffd234;
  uint uVar3;
  
  snapshot_DAT_ffffd234 = DAT_ffffd234;
  snapshot_DAT_ffffd233 = DAT_ffffd233;
  FUN_0005877e();
  if (DAT_ffffd1c5 == '\x01') {
    uVar3 = FUN_000587f2();
    return uVar3;
  }
  uVar3 = (uint)(char)snapshot_DAT_ffffd233;
  if (((uVar3 != 0) || (uVar3 = (uint)DAT_ffffd233, uVar3 != 1)) &&
     ((snapshot_DAT_ffffd234 != 0 || (uVar3 = (uint)DAT_ffffd234, uVar3 != 1)))) {
    return uVar3;
  }
  uVar3 = FUN_0005882c();
  return uVar3;
}


