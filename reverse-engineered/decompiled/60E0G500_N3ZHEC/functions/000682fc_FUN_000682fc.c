/* ROM address: 0x000682fc; body bytes: 48; decompiled */

void FUN_000682fc(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  
  cVar4 = -0x5b;
  iVar2 = (uint)DAT_ffff8fdc * 10;
  pcVar3 = (char *)(&DAT_ffff8fc8 + (uint)DAT_ffff8fdc * 5);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    cVar4 = cVar4 - cVar1;
  } while (pcVar3 < &DAT_ffff8fd0 + iVar2);
  (&DAT_ffff8fd0)[iVar2] = cVar4;
  return;
}


