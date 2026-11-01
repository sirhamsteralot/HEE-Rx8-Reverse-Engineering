/* ROM address: 0x00067d98; body bytes: 50; decompiled */

void FUN_00067d98(void)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  
  cVar3 = -0x5b;
  iVar4 = (uint)DAT_ffff8fc0 * 0x28;
  pcVar2 = (char *)(&DAT_ffff8ea8 + (uint)DAT_ffff8fc0 * 10);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    cVar3 = cVar3 - cVar1;
  } while (pcVar2 < &DAT_ffff8ecf + iVar4);
  (&DAT_ffff8ecf)[iVar4] = cVar3;
  return;
}


