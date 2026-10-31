/* ROM address: 0x000496c6; body bytes: 92; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00049718) */
/* Unique exact-byte match to related 60E0FC00 function at 000485ca (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000496c6(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    iVar3 = (uVar4 & 0xff) * 2;
    cVar1 = (&DAT_0004e395)[iVar3];
    iVar2 = (int)cVar1;
    uVar4 = uVar4 + 1;
    if ((&DAT_0004e394)[iVar3] == DAT_ffffd39b) break;
  } while (cVar1 != -1);
  if (cVar1 == -1) {
    iVar2 = 0;
  }
  DAT_ffffcd12 = cVar1 == -1;
  return iVar2;
}


