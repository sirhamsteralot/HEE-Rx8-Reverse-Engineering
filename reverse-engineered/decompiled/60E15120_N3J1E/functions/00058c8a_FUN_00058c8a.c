/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00058c8a; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000570ee (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00058c8a(void)

{
  byte snapshot_DAT_ffffd23b;
  uint uVar2;
  
  snapshot_DAT_ffffd23b = DAT_ffffd23b;
  FUN_00058c78();
  uVar2 = (uint)DAT_ffffd1c5;
  if (uVar2 == 1) {
    uVar2 = FUN_00058cd0();
    return uVar2;
  }
  if ((snapshot_DAT_ffffd23b == 0) && (uVar2 = (uint)DAT_ffffd23b, uVar2 == 1)) {
    uVar2 = FUN_00058d0c();
    return uVar2;
  }
  return uVar2;
}


