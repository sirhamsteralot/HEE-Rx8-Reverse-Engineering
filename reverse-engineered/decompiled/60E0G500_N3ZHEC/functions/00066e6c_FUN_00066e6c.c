/* ROM address: 0x00066e6c; body bytes: 80; decompiled */

undefined4 FUN_00066e6c(char param_1,char *param_2,ushort param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_3 != 0) {
    do {
      cVar1 = FUN_00066ebc((int)*param_2);
      if (cVar1 != param_1) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 1;
    } while (iVar2 < (int)(uint)param_3);
  }
  return 0;
}


