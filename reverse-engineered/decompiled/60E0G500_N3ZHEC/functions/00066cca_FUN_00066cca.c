/* ROM address: 0x00066cca; body bytes: 166; decompiled */

void FUN_00066cca(char *param_1,uint param_2)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  char *pcVar4;
  char local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  
  iVar3 = 0;
  pcVar4 = param_1;
  if ((param_2 & 0xffff) != 0) {
    do {
      cVar2 = FUN_00066e1c(9,(int)*param_1);
      if (cVar2 == '\0') {
        uVar1 = FUN_00066e4e(9,(int)*pcVar4);
        local_28 = *pcVar4;
        local_27 = (undefined1)((uint)uVar1 >> 0x18);
        local_26 = (undefined1)((uint)uVar1 >> 0x10);
        local_25 = (undefined1)((uint)uVar1 >> 8);
        local_24 = (undefined1)uVar1;
        FUN_000688c8(9,&local_28,5);
        DAT_ffffd940 = DAT_ffffd940 + 5;
      }
      iVar3 = iVar3 + 1;
      pcVar4 = pcVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar3 < (int)(param_2 & 0xffff));
  }
  return;
}


