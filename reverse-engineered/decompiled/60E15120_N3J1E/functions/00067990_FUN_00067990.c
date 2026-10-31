/* ROM address: 0x00067990; body bytes: 148; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066280 (148 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067990(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  sVar2 = FUN_00002034(&DAT_ffff8fb4);
  if ((sVar2 == 0) && (sVar2 = FUN_00002034(&DAT_ffff8fb8), sVar2 == 0)) {
    uVar6 = 0;
    for (uVar3 = 0; cVar4 = '\0', (int)uVar3 < 2; uVar3 = uVar3 + 1) {
      pcVar5 = (char *)(&DAT_ffff8fa0 + uVar3 * 5);
      if ((DAT_ffff8798._0_1_ == '\0') || (uVar3 != DAT_ffff8fb4)) {
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          cVar4 = cVar4 + cVar1;
        } while (pcVar5 < (char *)(uVar3 * 10 + -0x7057));
        if (cVar4 != -0x5b) goto LAB_00067a04;
      }
    }
  }
  else {
LAB_00067a04:
    uVar6 = 1;
  }
  return uVar6;
}


