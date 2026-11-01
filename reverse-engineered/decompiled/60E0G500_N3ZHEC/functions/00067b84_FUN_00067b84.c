/* ROM address: 0x00067b84; body bytes: 150; decompiled */

undefined4 FUN_00067b84(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  sVar2 = FUN_00002034(&DAT_ffff8fc0);
  if ((sVar2 == 0) && (sVar2 = FUN_00002034(&DAT_ffff8fc4), sVar2 == 0)) {
    uVar6 = 0;
    for (uVar3 = 0; cVar4 = '\0', (int)uVar3 < 7; uVar3 = uVar3 + 1) {
      pcVar5 = (char *)(&DAT_ffff8ea8 + uVar3 * 10);
      if ((DAT_ffff87c0 == '\0') || (uVar3 != DAT_ffff8fc0)) {
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          cVar4 = cVar4 + cVar1;
        } while (pcVar5 < &DAT_ffff8ed0 + uVar3 * 10);
        if (cVar4 != -0x5b) goto LAB_00067bfa;
      }
    }
  }
  else {
LAB_00067bfa:
    uVar6 = 1;
  }
  return uVar6;
}


