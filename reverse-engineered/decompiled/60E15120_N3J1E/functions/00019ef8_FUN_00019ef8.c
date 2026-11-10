/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00019ef8; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001ac58 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00019ef8(void)

{
  undefined4 snapshot_maf_scaled_latched_ffffa9e8;
  int iVar2;
  byte bVar3;
  
  maf_voltage_and_fault_counters();
  snapshot_maf_scaled_latched_ffffa9e8 = maf_scaled_latched_ffffa9e8;
  bVar3 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)&DAT_ffffa9f8 + iVar2) = snapshot_maf_scaled_latched_ffffa9e8;
    bVar3 = bVar3 + 1;
    *(undefined4 *)((int)&DAT_ffffaa10 + iVar2) = snapshot_maf_scaled_latched_ffffa9e8;
    iVar2 = iVar2 + 4;
  } while (bVar3 < 6);
  return iVar2;
}


