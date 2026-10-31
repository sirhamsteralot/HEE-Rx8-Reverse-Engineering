/* ROM address: 0x00049584; body bytes: 92; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000495d6) */
/* Unique exact-byte match to related 60E0FC00 function at 00048488 (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00049584(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    iVar3 = (uVar4 & 0xff) * 4;
    cVar1 = (&DAT_0004e356)[iVar3];
    iVar2 = (int)cVar1;
    uVar4 = uVar4 + 1;
    if (*(short *)(&DAT_0004e354 + iVar3) == DAT_ffffd398) break;
  } while (cVar1 != -1);
  if (cVar1 == -1) {
    iVar2 = 10;
  }
  DAT_ffffcd0f = cVar1 == -1;
  return iVar2;
}


