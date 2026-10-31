/* ROM address: 0x0000fb8c; body bytes: 324; decompiled */

void FUN_0000fb8c(undefined4 param_1,ushort param_2)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  byte *pbVar5;
  ushort uVar7;
  char *pcVar6;
  
  pcVar4 = &DAT_ffffa4b4;
  do {
    if ((char *)0xffffa563 < pcVar4) {
      return;
    }
    uVar7 = param_2 & *(ushort *)((int)&PTR_DAT_0004e27c + (uint)(byte)pcVar4[0xc] * 2);
    if ((((pcVar4[1] == '\x01') && (uVar7 == 0)) || ((pcVar4[1] == '\0' && (uVar7 != 0)))) &&
       (iVar2 = FUN_0000fa3a(param_1,*(undefined4 *)(pcVar4 + 8)), 0x167ffff < iVar2)) {
      if (uVar7 == 0) {
        if (pcVar4[2] == '\x01') {
LAB_0000fcb2:
          pcVar4[1] = '\0';
        }
        else if (pcVar4[2] == '\0') {
          cVar3 = (*(code *)(&PTR_FUN_0004e2ac)[*pcVar4 * 4])(pcVar4);
          if (cVar3 == '\x01') goto LAB_0000fcb2;
          pcVar4[2] = '\x02';
        }
      }
      else if (pcVar4[2] == '\x01') {
        bVar1 = true;
        for (pbVar5 = (byte *)(pcVar4 + 0x10); pbVar5 < pcVar4 + 0x58; pbVar5 = pbVar5 + 0x18) {
          if (pbVar5[1] == 1) {
            if ((&injector_channel_enable_flag_ffffa017)[(uint)*pbVar5 * 0x18] == '\0') {
LAB_0000fc58:
              bVar1 = false;
              break;
            }
          }
          else if (pbVar5[1] == 2) goto LAB_0000fc58;
        }
        if (bVar1) {
          for (pcVar6 = pcVar4 + 0x10; pcVar6 < pcVar4 + 0x58; pcVar6 = pcVar6 + 0x18) {
            injector_channel_disable((int)*pcVar6);
          }
          pcVar4[2] = '\0';
          pcVar4[1] = '\x01';
        }
      }
      else if (pcVar4[2] == '\0') {
        pcVar4[1] = '\x01';
      }
    }
    pcVar4 = pcVar4 + 0x58;
  } while( true );
}


