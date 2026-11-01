/* ROM address: 0x00010806; body bytes: 248; decompiled */

void FUN_00010806(undefined4 param_1,char param_2)

{
  bool bVar1;
  undefined4 uVar2;
  char cVar3;
  char cVar4;
  char *pcVar5;
  char cVar6;
  char *pcVar7;
  
  pcVar5 = &DAT_ffffa578;
  do {
    if ((char *)0xffffa5cf < pcVar5) {
      return;
    }
    if (*pcVar5 != param_2) {
      uVar2 = FUN_000107f0(param_1,*(undefined4 *)(pcVar5 + 4));
      cVar4 = *pcVar5;
      *pcVar5 = param_2;
      FUN_00010f00(pcVar5);
      cVar3 = (*(code *)(&PTR_LAB_0004eab0)[param_2 * 4])(pcVar5,uVar2);
      cVar6 = cVar4;
      if (cVar3 == '\x01') {
        if (pcVar5[1] == '\x01') {
          bVar1 = true;
          for (pcVar7 = pcVar5 + 0xc; pcVar7 < pcVar5 + 0x2c; pcVar7 = pcVar7 + 0x10) {
            if (pcVar7[3] == '\x01') {
              cVar4 = FUN_00008ee6((int)*pcVar7);
              if (cVar4 != '\x01') {
LAB_0001089c:
                bVar1 = false;
                break;
              }
            }
            else if (pcVar7[3] == '\x02') goto LAB_0001089c;
          }
          if (bVar1) {
            for (pcVar7 = pcVar5 + 0xc; pcVar7 < pcVar5 + 0x2c; pcVar7 = pcVar7 + 0x10) {
              FUN_00008e28((int)*pcVar7);
              pcVar7[3] = '\0';
            }
            pcVar5[1] = '\0';
            cVar6 = param_2;
          }
        }
        else {
          cVar6 = param_2;
          if (pcVar5[1] != '\0') {
            cVar6 = cVar4;
          }
        }
      }
      *pcVar5 = cVar6;
      FUN_00010f00(pcVar5);
    }
    pcVar5 = pcVar5 + 0x2c;
  } while( true );
}


