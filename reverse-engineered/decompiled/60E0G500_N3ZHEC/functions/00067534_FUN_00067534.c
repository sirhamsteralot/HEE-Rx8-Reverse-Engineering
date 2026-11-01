/* ROM address: 0x00067534; body bytes: 140; decompiled */

undefined4 FUN_00067534(char *param_1,short param_2,char param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  cVar1 = FUN_00066e1c(8,(int)*param_1);
  if (cVar1 == '\0') {
    pcVar3 = "\x01";
    pcVar4 = pcVar3;
    for (iVar2 = 0; (&DAT_0005f7b8)[iVar2 * 8] != -1; iVar2 = iVar2 + 1) {
      if (*pcVar3 == *param_1) {
        DAT_ffffd970 = *param_1;
        (**(code **)(pcVar4 + 4))(param_1 + 1,param_2 + 0xffff,(int)param_3);
        return 0;
      }
      pcVar4 = pcVar4 + 8;
      pcVar3 = pcVar3 + 8;
    }
  }
  return 1;
}


