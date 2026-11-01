/* ROM address: 0x0006588e; body bytes: 110; decompiled */

void FUN_0006588e(ushort *param_1,int param_2)

{
  char cVar1;
  char cVar3;
  int iVar2;
  
  if (*param_1 == 0) {
    cVar3 = '\0';
  }
  else {
    cVar3 = FUN_00068058((int)(short)*param_1);
  }
  cVar1 = (&DAT_ffff8d7c)[(uint)*param_1 * 2];
  iVar2 = (int)(char)*(byte *)(param_1 + 5);
  if ((cVar1 == '\x11') && (cVar3 == '\0')) {
    iVar2 = 0x50;
  }
  else if (((cVar1 == '\x10') || (cVar1 == '\0')) && (*(byte *)(param_1 + 5) < 0x50)) {
    iVar2 = iVar2 + 1;
  }
  FUN_00063744(iVar2);
  *(char *)(param_2 + 10) = (char)iVar2;
  return;
}


