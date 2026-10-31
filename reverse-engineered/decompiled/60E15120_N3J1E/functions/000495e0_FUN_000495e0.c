/* ROM address: 0x000495e0; body bytes: 94; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00049632) */
/* Unique exact-byte match to related 60E0FC00 function at 000484e4 (94 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000495e0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    iVar3 = (uVar4 & 0xff) * 8;
    cVar1 = (&DAT_0004e378)[iVar3];
    iVar2 = (int)cVar1;
    uVar4 = uVar4 + 1;
    if (*(int *)(&DAT_0004e374 + iVar3) == DAT_ffffd394) break;
  } while (cVar1 != -1);
  if (cVar1 == -1) {
    iVar2 = 0;
  }
  DAT_ffffcd10 = cVar1 == -1;
  return iVar2;
}


