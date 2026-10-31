/* ROM address: 0x000673e0; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065cd0 (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000673e0(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  sVar2 = FUN_00002034(&DAT_ffff8f98);
  if ((sVar2 == 0) && (sVar2 = FUN_00002034(&DAT_ffff8f9c), sVar2 == 0)) {
    uVar6 = 0;
    for (uVar3 = 0; cVar4 = '\0', (int)uVar3 < 7; uVar3 = uVar3 + 1) {
      pcVar5 = (char *)(&DAT_ffff8e80 + uVar3 * 10);
      if ((DAT_ffff8798._0_1_ == '\0') || (uVar3 != DAT_ffff8f98)) {
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          cVar4 = cVar4 + cVar1;
        } while (pcVar5 < &DAT_ffff8ea8 + uVar3 * 10);
        if (cVar4 != -0x5b) goto LAB_00067456;
      }
    }
  }
  else {
LAB_00067456:
    uVar6 = 1;
  }
  return uVar6;
}


