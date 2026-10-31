/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00048670; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000476fc (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 FUN_00048670(void)

{
  bool bVar1;
  undefined4 snapshot_DAT_ffffb4b0;
  char cVar3;
  undefined4 *puVar4;
  
  snapshot_DAT_ffffb4b0 = DAT_ffffb4b0;
  DAT_ffffccc6 = 1;
  DAT_ffffccd0 = DAT_ffffb4b0;
  cVar3 = '\x04';
  bVar1 = true;
  puVar4 = (undefined4 *)0xffffcce4;
  while (bVar1) {
    cVar3 = cVar3 + -1;
    bVar1 = cVar3 != '\0';
    puVar4 = puVar4 + -1;
    *puVar4 = snapshot_DAT_ffffb4b0;
  }
  return 4;
}


