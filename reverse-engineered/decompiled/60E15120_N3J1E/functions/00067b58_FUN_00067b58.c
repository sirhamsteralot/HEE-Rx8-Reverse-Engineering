/* ROM address: 0x00067b58; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066448 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067b58(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  
  cVar4 = -0x5b;
  iVar2 = (uint)DAT_ffff8fb4 * 10;
  pcVar3 = (char *)(&DAT_ffff8fa0 + (uint)DAT_ffff8fb4 * 5);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    cVar4 = cVar4 - cVar1;
  } while (pcVar3 < &DAT_ffff8fa8 + iVar2);
  (&DAT_ffff8fa8)[iVar2] = cVar4;
  return;
}


