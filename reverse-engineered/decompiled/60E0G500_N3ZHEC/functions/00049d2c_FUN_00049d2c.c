/* ROM address: 0x00049d2c; body bytes: 92; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00049d7e) */

int FUN_00049d2c(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    iVar3 = (uVar4 & 0xff) * 4;
    cVar1 = (&DAT_0004eafa)[iVar3];
    iVar2 = (int)cVar1;
    uVar4 = uVar4 + 1;
    if (*(short *)(&DAT_0004eaf8 + iVar3) == DAT_ffffd3d4) break;
  } while (cVar1 != -1);
  if (cVar1 == -1) {
    iVar2 = 10;
  }
  DAT_ffffcd4f = cVar1 == -1;
  return iVar2;
}


