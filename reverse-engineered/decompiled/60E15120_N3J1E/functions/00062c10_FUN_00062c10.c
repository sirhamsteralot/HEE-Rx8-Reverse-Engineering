/* ROM address: 0x00062c10; body bytes: 144; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061500 (144 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00062c10(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  sVar2 = FUN_00002034(&DAT_ffff8900);
  if ((sVar2 == 0) && (sVar2 = FUN_00002034(&DAT_ffff8904), sVar2 == 0)) {
    uVar6 = 0;
    for (uVar3 = 0; cVar4 = '\0', (int)uVar3 < 0x15; uVar3 = uVar3 + 1) {
      pcVar5 = (char *)(&DAT_ffff87b0 + uVar3 * 8);
      if ((DAT_ffff8798._0_1_ == '\0') || (uVar3 != DAT_ffff8900._0_2_)) {
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          cVar4 = cVar4 + cVar1;
        } while (pcVar5 < (char *)(uVar3 * 0x10 + -0x7841));
        if (cVar4 != -0x5b) goto LAB_00062c80;
      }
    }
  }
  else {
LAB_00062c80:
    uVar6 = 1;
  }
  return uVar6;
}


