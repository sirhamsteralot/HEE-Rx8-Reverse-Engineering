/* ROM address: 0x0001064c; body bytes: 210; decompiled */

void FUN_0001064c(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar4 = (uint)DAT_ffff9f97;
  if (0xb < uVar4) {
    uVar4 = uVar4 - 0xc;
  }
  for (pcVar5 = &DAT_ffffa578; pcVar5 < &DAT_ffffa5d0; pcVar5 = pcVar5 + 0x2c) {
    iVar1 = FUN_000107f0(uVar4 * 0x1e0000,*(undefined4 *)(pcVar5 + 4));
    iVar2 = FUN_000107c4(0x1680000 - iVar1);
    pcVar5[9] = 0x167ffff < iVar2;
    for (pcVar7 = pcVar5 + 0xc; pcVar6 = pcVar7, pcVar7 < pcVar5 + 0x2c; pcVar7 = pcVar7 + 0x10) {
      while (pcVar6 = pcVar6 + 1, pcVar6 < pcVar7 + 3) {
        FUN_00008e28((int)*pcVar6);
      }
      *pcVar7 = pcVar7[(byte)pcVar5[9] + 1];
      pcVar7[3] = '\0';
    }
    FUN_00010f00(pcVar5);
    cVar3 = (*(code *)(&PTR_LAB_0004eab0)[*pcVar5 * 4])(pcVar5,iVar1);
    if (cVar3 == '\x01') {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x02';
    }
    pcVar5[1] = cVar3;
  }
  return;
}


