/* ROM address: 0x0000fa4e; body bytes: 242; decompiled */

void FUN_0000fa4e(undefined4 param_1,char param_2)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  char *pcVar5;
  
  pcVar3 = &DAT_ffffa4b4;
  do {
    if ((char *)0xffffa563 < pcVar3) {
      return;
    }
    if ((*pcVar3 != param_2) &&
       (iVar2 = FUN_0000fa3a(param_1,*(undefined4 *)(pcVar3 + 8)),
       *(int *)(&DAT_0004e2a4 + param_2 * 0x10) < iVar2)) {
      if (pcVar3[2] == '\x01') {
        bVar1 = true;
        for (pbVar4 = (byte *)(pcVar3 + 0x10); pbVar4 < pcVar3 + 0x58; pbVar4 = pbVar4 + 0x18) {
          if (pbVar4[1] == 1) {
            if ((&injector_channel_enable_flag_ffffa017)[(uint)*pbVar4 * 0x18] == '\0') {
LAB_0000fb32:
              bVar1 = false;
              break;
            }
          }
          else if (pbVar4[1] == 2) goto LAB_0000fb32;
        }
        if (bVar1) {
          for (pcVar5 = pcVar3 + 0x10; pcVar5 < pcVar3 + 0x58; pcVar5 = pcVar5 + 0x18) {
            injector_channel_disable((int)*pcVar5);
            pcVar5[1] = '\0';
          }
          pcVar3[2] = '\0';
          *pcVar3 = param_2;
        }
      }
      else if (pcVar3[2] == '\0') {
        *pcVar3 = param_2;
      }
    }
    pcVar3 = pcVar3 + 0x58;
  } while( true );
}


