/* ROM address: 0x00049de6; body bytes: 94; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00049e64) */

int FUN_00049de6(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    iVar3 = (uVar4 & 0xff) * 2;
    cVar1 = (&DAT_0004eb31)[iVar3];
    iVar2 = (int)cVar1;
    uVar4 = uVar4 + 1;
    if ((&DAT_0004eb30)[iVar3] == DAT_ffffd3d6) break;
  } while (cVar1 != -1);
  if (cVar1 == -1) {
    iVar2 = 2;
  }
  DAT_ffffcd51 = cVar1 == -1;
  return iVar2;
}


