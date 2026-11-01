/* ROM address: 0x00063ce4; body bytes: 174; decompiled */

undefined4 FUN_00063ce4(void)

{
  char cVar1;
  short sVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  
  sVar2 = FUN_00002034(&DAT_ffff8d74);
  if ((sVar2 == 0) && (sVar2 = FUN_00002034(&DAT_ffff8d78), sVar2 == 0)) {
    uVar6 = 0;
    for (uVar4 = 0; cVar3 = '\0', (int)uVar4 < 0x15; uVar4 = uVar4 + 1) {
      iVar8 = uVar4 * 0x34;
      pcVar5 = (char *)(&DAT_ffff8930 + uVar4 * 0x1a);
      pcVar7 = &DAT_ffff893a + iVar8;
      if ((DAT_ffff87c0 == '\0') || (uVar4 != DAT_ffff8d74)) {
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          cVar3 = cVar3 + cVar1;
        } while (pcVar5 < (char *)(iVar8 + -0x76c7));
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          cVar3 = cVar3 + cVar1;
        } while (pcVar7 < &DAT_ffff8962 + iVar8);
        if ((char)(cVar3 + (&DAT_ffff8962)[iVar8]) != -0x5b) goto LAB_00063d70;
      }
    }
  }
  else {
LAB_00063d70:
    uVar6 = 1;
  }
  return uVar6;
}


