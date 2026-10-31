/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00003490; body bytes: 218; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000034fa) */
/* WARNING: Removing unreachable block (ram,0x00003542) */
/* Unique exact-byte match to related 60E0FC00 function at 00003490 (218 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00003490(char param_1)

{
  char cVar1;
  int snapshot_DAT_ffff764c;
  int snapshot_DAT_ffff7650;
  int iVar4;
  uint in_sr;
  uint uVar5;
  
  snapshot_DAT_ffff764c = DAT_ffff764c;
  uVar5 = in_sr & 0xfffffffe | (uint)(param_1 == '\0');
  if (((byte)uVar5 & 1) == 1) {
    if ((DAT_ffff763c == DAT_ffff763e) || (*(char *)(DAT_ffff7650 + 1) != '\0')) {
      DAT_ffff7640 = 0;
    }
    else {
      DAT_ffff7640 = 0x100;
      FUN_00003bf4(&DAT_ffff7638,uVar5,DAT_ffff7650);
    }
  }
  else {
    iVar4 = *(char *)(DAT_ffff764c + 2) * 2;
    *(undefined *)(DAT_ffff764c + 2) = (&DAT_ffff762c)[iVar4];
    snapshot_DAT_ffff7650 = DAT_ffff7650;
    if ((&DAT_ffff762d)[iVar4] != *(char *)(snapshot_DAT_ffff764c + 1)) {
      cVar1 = *(char *)(snapshot_DAT_ffff764c + 1);
      *(undefined *)(snapshot_DAT_ffff764c + 1) = (&DAT_ffff762d)[iVar4];
      DAT_ffff7640 = DAT_ffff7640 + 0x100;
      ref_consistencyCheck(&DAT_ffff7638,(int)cVar1);
      if (((*(char *)(snapshot_DAT_ffff7650 + 1) == '\0') && (DAT_ffff763c != DAT_ffff763e)) &&
         ((DAT_ffff7640 & 0x1000) == 0)) {
        FUN_00003bf4(&DAT_ffff7638,uVar5,snapshot_DAT_ffff7650);
      }
      else {
        DAT_ffff7640 = DAT_ffff7640 - 0x100;
      }
    }
  }
  return 0;
}


