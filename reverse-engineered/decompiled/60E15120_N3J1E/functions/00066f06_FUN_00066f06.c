/* ROM address: 0x00066f06; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000657f6 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066f06(uint param_1)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  cVar1 = FUN_00066678(6,param_1);
  if (cVar1 == '\0') {
    pbVar3 = &DAT_0005efc4;
    pbVar4 = pbVar3;
    for (iVar2 = 0; (&DAT_0005efc4)[iVar2 * 8] != -1; iVar2 = iVar2 + 1) {
      if ((uint)*pbVar3 == (param_1 & 0xff)) {
        FUN_00066f8c(param_1,*(undefined4 *)(pbVar4 + 4),0xff,&DAT_0005efc4,&DAT_0005efc4);
        return 0;
      }
      pbVar4 = pbVar4 + 8;
      pbVar3 = pbVar3 + 8;
    }
  }
  return 1;
}


