/* ROM address: 0x000675f4; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065ee4 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000675f4(void)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  
  cVar3 = -0x5b;
  iVar4 = (uint)DAT_ffff8f98 * 0x28;
  pcVar2 = (char *)(&DAT_ffff8e80 + (uint)DAT_ffff8f98 * 10);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    cVar3 = cVar3 - cVar1;
  } while (pcVar2 < &DAT_ffff8ea7 + iVar4);
  (&DAT_ffff8ea7)[iVar4] = cVar3;
  return;
}


