/* ROM address: 0x00049e6e; body bytes: 92; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00049ec0) */

int FUN_00049e6e(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    iVar3 = (uVar4 & 0xff) * 2;
    cVar1 = (&DAT_0004eb39)[iVar3];
    iVar2 = (int)cVar1;
    uVar4 = uVar4 + 1;
    if ((&DAT_0004eb38)[iVar3] == DAT_ffffd3d7) break;
  } while (cVar1 != -1);
  if (cVar1 == -1) {
    iVar2 = 0;
  }
  DAT_ffffcd52 = cVar1 == -1;
  return iVar2;
}


