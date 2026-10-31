/* ROM address: 0x000603b2; body bytes: 172; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005eca2 (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000603b2(uint param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = 1;
  pcVar3 = (&PTR_DAT_0007f500)[param_1 & 0xffff];
  for (uVar2 = 0; ((*pcVar3 != '\x1f' && (iVar4 == 1)) && ((char)uVar2 != -1));
      uVar2 = rx8_add_u8_saturate(uVar2,1)) {
    cVar1 = *pcVar3;
    if ((cVar1 == '\x1b') || (cVar1 == '\x1c')) {
      if (DAT_ffffd26e == '\x01') {
        iVar4 = 0;
      }
    }
    else if (cVar1 == '\x1d') {
      if (DAT_ffffd26b == '\x01') {
        iVar4 = 0;
      }
    }
    else if ((cVar1 != '\x1e') && (cVar1 = FUN_0005bffe((int)*pcVar3), cVar1 == '\x01')) {
      iVar4 = 0;
    }
    pcVar3 = pcVar3 + 1;
  }
  return iVar4;
}


