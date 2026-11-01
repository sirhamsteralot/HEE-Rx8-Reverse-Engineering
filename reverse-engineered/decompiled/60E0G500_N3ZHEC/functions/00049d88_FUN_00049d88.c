/* ROM address: 0x00049d88; body bytes: 94; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00049dda) */

int FUN_00049d88(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    iVar3 = (uVar4 & 0xff) * 8;
    cVar1 = (&DAT_0004eb1c)[iVar3];
    iVar2 = (int)cVar1;
    uVar4 = uVar4 + 1;
    if (*(int *)(&DAT_0004eb18 + iVar3) == DAT_ffffd3d0) break;
  } while (cVar1 != -1);
  if (cVar1 == -1) {
    iVar2 = 0;
  }
  DAT_ffffcd50 = cVar1 == -1;
  return iVar2;
}


