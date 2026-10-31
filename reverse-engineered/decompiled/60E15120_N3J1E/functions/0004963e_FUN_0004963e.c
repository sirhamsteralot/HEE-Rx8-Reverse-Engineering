/* ROM address: 0x0004963e; body bytes: 94; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000496bc) */

int FUN_0004963e(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    iVar3 = (uVar4 & 0xff) * 2;
    cVar1 = (&DAT_0004e38d)[iVar3];
    iVar2 = (int)cVar1;
    uVar4 = uVar4 + 1;
    if ((&DAT_0004e38c)[iVar3] == DAT_ffffd39a) break;
  } while (cVar1 != -1);
  if (cVar1 == -1) {
    iVar2 = 2;
  }
  DAT_ffffcd11 = cVar1 == -1;
  return iVar2;
}


