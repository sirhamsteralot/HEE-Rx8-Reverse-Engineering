/* ROM address: 0x00064530; body bytes: 152; decompiled */

undefined4 FUN_00064530(void)

{
  char cVar1;
  char cVar3;
  undefined2 uVar2;
  undefined2 *puVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  cVar3 = FUN_00002044(&DAT_ffff8e9a);
  if (((cVar3 != '\0') || (cVar3 = FUN_00002044(&DAT_ffff8e9c), cVar3 != '\0')) ||
     (cVar3 = FUN_00002044(&DAT_ffff8e98), cVar3 != '\0')) {
    uVar8 = 1;
  }
  cVar3 = '\0';
  pcVar6 = &DAT_ffff8d7c;
  iVar7 = 0x8c;
  do {
    pcVar5 = pcVar6;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      cVar3 = cVar3 + cVar1;
    } while (pcVar5 < pcVar6 + 2);
    iVar7 = iVar7 + -1;
    pcVar6 = pcVar6 + 2;
  } while (iVar7 != 0);
  if ((char)(cVar3 + DAT_ffff8e94._0_1_) == -0x5b) {
    uVar2 = FUN_00002420();
    puVar4 = &DAT_ffff8e96;
  }
  else {
    if ((char)(cVar3 + DAT_ffff8e96._0_1_) != -0x5b) {
      return 1;
    }
    uVar2 = FUN_00002420((int)DAT_ffff8e96._0_1_);
    puVar4 = &DAT_ffff8e94;
  }
  *puVar4 = uVar2;
  return uVar8;
}


