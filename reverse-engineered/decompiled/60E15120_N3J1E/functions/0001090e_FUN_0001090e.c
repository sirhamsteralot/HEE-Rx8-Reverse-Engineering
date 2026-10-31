/* ROM address: 0x0001090e; body bytes: 322; decompiled */

void FUN_0001090e(undefined4 param_1,ushort param_2)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char *pcVar5;
  ushort uVar6;
  char *pcVar7;
  byte *pbVar8;
  
  pcVar5 = &DAT_ffffa578;
  do {
    if ((char *)0xffffa5cf < pcVar5) {
      return;
    }
    iVar2 = FUN_00010800(param_1,*(undefined4 *)(pcVar5 + 4));
    if (0x149ffff < iVar2) {
      bVar1 = true;
      cVar4 = *pcVar5;
      for (pcVar7 = pcVar5 + 0xc; pcVar7 < pcVar5 + 0x2c; pcVar7 = pcVar7 + 0x10) {
        if (pcVar7[3] == '\x01') {
          cVar3 = FUN_00008ee6((int)*pcVar7);
          if (cVar3 != '\x01') {
LAB_0001097a:
            bVar1 = false;
            break;
          }
        }
        else if (pcVar7[3] == '\x02') goto LAB_0001097a;
      }
      cVar4 = (*(code *)(&PTR_LAB_0004e304)[cVar4 * 4])(pcVar5,iVar2);
      for (pbVar8 = (byte *)(pcVar5 + 0xc); pbVar8 < pcVar5 + 0x2c; pbVar8 = pbVar8 + 0x10) {
        uVar6 = *(ushort *)((int)&PTR_DAT_0004e2d4 + (uint)*pbVar8 * 2) & param_2;
        if (((pbVar8[4] == 1) && (uVar6 == 0)) || ((pbVar8[4] == 0 && (uVar6 != 0)))) {
          if (uVar6 == 0) {
            if (pbVar8[3] == 1) {
LAB_00010a56:
              pbVar8[4] = 0;
            }
            else if (pbVar8[3] == 0) {
              if (cVar4 == '\x01') goto LAB_00010a56;
              pbVar8[3] = 2;
            }
          }
          else if (pbVar8[3] == 1) {
            if (bVar1) {
              FUN_00008e28((int)(char)*pbVar8);
              pbVar8[3] = 0;
              pbVar8[4] = 1;
            }
          }
          else if (pbVar8[3] == 0) {
            pbVar8[4] = 1;
          }
        }
      }
    }
    pcVar5 = pcVar5 + 0x2c;
  } while( true );
}


