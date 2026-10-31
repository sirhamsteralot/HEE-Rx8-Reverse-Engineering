/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00053cf2; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00051e06 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_00053cf2(void)

{
  byte snapshot_DAT_ffffd1a0;
  char cVar2;
  
  snapshot_DAT_ffffd1a0 = DAT_ffffd1a0;
  cVar2 = FUN_000552ac();
  if (((cVar2 == '\0') || (snapshot_DAT_ffffd1a0 < 0x88)) || (0x87 < snapshot_DAT_ffffd1a0)) {
    cVar2 = '\0';
    DAT_ffffd1a4 = 0;
  }
  else {
    DAT_ffffd1a4 = 1;
  }
  return cVar2;
}


