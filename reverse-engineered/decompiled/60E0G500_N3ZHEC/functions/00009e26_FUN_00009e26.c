/* ROM address: 0x00009e26; body bytes: 48; decompiled */

uint FUN_00009e26(int param_1,uint param_2,char *param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = param_1 + param_2;
  pcVar3 = (char *)(param_4 + (param_2 & 0xff));
  for (; (param_2 & 0xff) < (uVar2 & 0xff); param_2 = param_2 + 1) {
    cVar1 = *param_3;
    do {
      *pcVar3 = cVar1;
    } while (*pcVar3 != cVar1);
    pcVar3 = pcVar3 + 1;
    param_3 = param_3 + 1;
  }
  return param_2;
}


