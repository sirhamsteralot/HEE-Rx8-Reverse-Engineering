/* ROM address: 0x000676aa; body bytes: 112; decompiled */

undefined4 FUN_000676aa(uint param_1)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  cVar1 = FUN_00066e1c(6,param_1);
  if (cVar1 == '\0') {
    pbVar3 = &DAT_0005f768;
    pbVar4 = pbVar3;
    for (iVar2 = 0; (&DAT_0005f768)[iVar2 * 8] != -1; iVar2 = iVar2 + 1) {
      if ((uint)*pbVar3 == (param_1 & 0xff)) {
        FUN_00067730(param_1,*(undefined4 *)(pbVar4 + 4),0xff,&DAT_0005f768,&DAT_0005f768);
        return 0;
      }
      pbVar4 = pbVar4 + 8;
      pbVar3 = pbVar3 + 8;
    }
  }
  return 1;
}


