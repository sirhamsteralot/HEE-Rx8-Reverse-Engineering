/* ROM address: 0x00060b56; body bytes: 172; decompiled */

int FUN_00060b56(uint param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = 1;
  pcVar3 = (&PTR_DAT_0007f0a8)[param_1 & 0xffff];
  for (uVar2 = 0; ((*pcVar3 != '\x1f' && (iVar4 == 1)) && ((char)uVar2 != -1));
      uVar2 = FUN_00002478(uVar2,1)) {
    cVar1 = *pcVar3;
    if ((cVar1 == '\x1b') || (cVar1 == '\x1c')) {
      if (DAT_ffffd2aa == '\x01') {
        iVar4 = 0;
      }
    }
    else if (cVar1 == '\x1d') {
      if (DAT_ffffd2a7 == '\x01') {
        iVar4 = 0;
      }
    }
    else if ((cVar1 != '\x1e') && (cVar1 = FUN_0005c7a2((int)*pcVar3), cVar1 == '\x01')) {
      iVar4 = 0;
    }
    pcVar3 = pcVar3 + 1;
  }
  return iVar4;
}


