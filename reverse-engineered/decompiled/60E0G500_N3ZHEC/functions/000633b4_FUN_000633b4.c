/* ROM address: 0x000633b4; body bytes: 144; decompiled */

undefined4 FUN_000633b4(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  sVar2 = FUN_00002034(&DAT_ffff8928);
  if ((sVar2 == 0) && (sVar2 = FUN_00002034(&DAT_ffff892c), sVar2 == 0)) {
    uVar6 = 0;
    for (uVar3 = 0; cVar4 = '\0', (int)uVar3 < 0x15; uVar3 = uVar3 + 1) {
      pcVar5 = (char *)(&DAT_ffff87d8 + uVar3 * 8);
      if ((DAT_ffff87c0 == '\0') || (uVar3 != DAT_ffff8928)) {
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          cVar4 = cVar4 + cVar1;
        } while (pcVar5 < (char *)(uVar3 * 0x10 + -0x7819));
        if (cVar4 != -0x5b) goto LAB_00063424;
      }
    }
  }
  else {
LAB_00063424:
    uVar6 = 1;
  }
  return uVar6;
}


