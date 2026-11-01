/* ROM address: 0x000675fe; body bytes: 172; decompiled */

undefined1 FUN_000675fe(char *param_1,uint param_2)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  char *pcVar4;
  undefined1 uStack_28;
  undefined1 local_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  iVar3 = 0;
  uStack_28 = 1;
  pcVar4 = param_1;
  if ((param_2 & 0xffff) != 0) {
    do {
      cVar2 = FUN_00066e1c(6,(int)*param_1);
      if (cVar2 == '\0') {
        DAT_ffffd978 = *pcVar4;
        uVar1 = FUN_00066e4e(6,(int)*pcVar4);
        local_24 = (undefined1)((uint)uVar1 >> 0x18);
        DAT_ffffd979 = local_24;
        uStack_23 = (undefined1)((uint)uVar1 >> 0x10);
        DAT_ffffd97a = uStack_23;
        uStack_22 = (undefined1)((uint)uVar1 >> 8);
        DAT_ffffd97b = uStack_22;
        uStack_21 = (undefined1)uVar1;
        DAT_ffffd97c = uStack_21;
        FUN_00067a90(&DAT_ffffd978,5);
        uStack_28 = 0;
      }
      iVar3 = iVar3 + 1;
      pcVar4 = pcVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar3 < (int)(param_2 & 0xffff));
  }
  return uStack_28;
}


