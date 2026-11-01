/* ROM address: 0x00068134; body bytes: 148; decompiled */

undefined4 FUN_00068134(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  sVar2 = FUN_00002034(&DAT_ffff8fdc);
  if ((sVar2 == 0) && (sVar2 = FUN_00002034(&DAT_ffff8fe0), sVar2 == 0)) {
    uVar6 = 0;
    for (uVar3 = 0; cVar4 = '\0', (int)uVar3 < 2; uVar3 = uVar3 + 1) {
      pcVar5 = (char *)(&DAT_ffff8fc8 + uVar3 * 5);
      if ((DAT_ffff87c0 == '\0') || (uVar3 != DAT_ffff8fdc)) {
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          cVar4 = cVar4 + cVar1;
        } while (pcVar5 < (char *)(uVar3 * 10 + -0x702f));
        if (cVar4 != -0x5b) goto LAB_000681a8;
      }
    }
  }
  else {
LAB_000681a8:
    uVar6 = 1;
  }
  return uVar6;
}


