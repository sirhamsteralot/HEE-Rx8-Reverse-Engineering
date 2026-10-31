/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00059190; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005792c (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00059190(uint param_1)

{
  ushort snapshot_DAT_ffffd3b4;
  undefined4 uVar2;
  byte *pbVar3;
  uint uVar4;
  byte local_c [2];
  ushort uStack_a;
  
  snapshot_DAT_ffffd3b4 = DAT_ffffd3b4;
  pbVar3 = local_c;
  do {
    sh_copy_bytes_forward_r0_r1_r2();
    uVar4 = (uint)*pbVar3;
    if (uVar4 == (param_1 & 0xff)) break;
  } while (uVar4 != 0);
  if ((uVar4 == 0) || ((snapshot_DAT_ffffd3b4 & uStack_a) == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


