/* ROM address: 0x00066d90; body bytes: 140; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065680 (140 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066d90(char *param_1,short param_2,char param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  cVar1 = FUN_00066678(8,(int)*param_1);
  if (cVar1 == '\0') {
    pcVar3 = "\x01";
    pcVar4 = pcVar3;
    for (iVar2 = 0; (&DAT_0005f014)[iVar2 * 8] != -1; iVar2 = iVar2 + 1) {
      if (*pcVar3 == *param_1) {
        DAT_ffffd934 = *param_1;
        (**(code **)(pcVar4 + 4))(param_1 + 1,param_2 + 0xffff,(int)param_3);
        return 0;
      }
      pcVar4 = pcVar4 + 8;
      pcVar3 = pcVar3 + 8;
    }
  }
  return 1;
}


