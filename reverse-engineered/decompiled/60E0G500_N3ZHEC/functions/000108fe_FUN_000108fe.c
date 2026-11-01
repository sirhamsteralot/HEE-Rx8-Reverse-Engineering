/* ROM address: 0x000108fe; body bytes: 334; decompiled */

void FUN_000108fe(undefined4 param_1,ushort param_2)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char *pcVar5;
  int iVar6;
  ushort uVar7;
  char *pcVar8;
  byte *pbVar9;
  
  pcVar5 = &DAT_ffffa578;
  do {
    if ((char *)0xffffa5cf < pcVar5) {
      return;
    }
    iVar2 = FUN_000107f0(param_1,*(undefined4 *)(pcVar5 + 4));
    if (*pcVar5 == '\0') {
      iVar6 = -0x1e0000;
    }
    else {
      iVar6 = 0x14a0000;
    }
    if (iVar6 <= iVar2) {
      bVar1 = true;
      cVar4 = *pcVar5;
      for (pcVar8 = pcVar5 + 0xc; pcVar8 < pcVar5 + 0x2c; pcVar8 = pcVar8 + 0x10) {
        if (pcVar8[3] == '\x01') {
          cVar3 = FUN_00008ee6((int)*pcVar8);
          if (cVar3 != '\x01') {
LAB_000109b2:
            bVar1 = false;
            break;
          }
        }
        else if (pcVar8[3] == '\x02') goto LAB_000109b2;
      }
      cVar4 = (*(code *)(&PTR_LAB_0004eab0)[cVar4 * 4])(pcVar5,iVar2);
      for (pbVar9 = (byte *)(pcVar5 + 0xc); pbVar9 < pcVar5 + 0x2c; pbVar9 = pbVar9 + 0x10) {
        uVar7 = *(ushort *)((int)&PTR_DAT_0004ea80 + (uint)*pbVar9 * 2) & param_2;
        if (((pbVar9[4] == 1) && (uVar7 == 0)) || ((pbVar9[4] == 0 && (uVar7 != 0)))) {
          if (uVar7 == 0) {
            if (pbVar9[3] == 1) {
LAB_00010a50:
              pbVar9[4] = 0;
            }
            else if (pbVar9[3] == 0) {
              if (cVar4 == '\x01') goto LAB_00010a50;
              pbVar9[3] = 2;
            }
          }
          else if (pbVar9[3] == 1) {
            if (bVar1) {
              FUN_00008e28((int)(char)*pbVar9);
              pbVar9[3] = 0;
              pbVar9[4] = 1;
            }
          }
          else if (pbVar9[3] == 0) {
            pbVar9[4] = 1;
          }
        }
      }
    }
    pcVar5 = pcVar5 + 0x2c;
  } while( true );
}


