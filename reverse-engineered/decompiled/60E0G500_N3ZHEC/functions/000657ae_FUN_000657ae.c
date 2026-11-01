/* ROM address: 0x000657ae; body bytes: 130; decompiled */

void FUN_000657ae(ushort *param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  
  cVar2 = (&DAT_ffff8d7c)[(uint)*param_1 * 2];
  bVar1 = *(byte *)(param_1 + 4);
  iVar3 = (int)(char)bVar1;
  if (*param_1 == 0) {
    cVar4 = '\0';
  }
  else {
    cVar4 = FUN_00068058((int)(short)*param_1);
  }
  if ((((cVar2 != ' ') && (*(char *)(param_1 + 3) == -0x3f)) && (cVar4 == '\0')) &&
     ((DAT_ffff8ea6 == '\x01' && (bVar1 < (byte)(&DAT_0007e076)[*param_1])))) {
    iVar3 = iVar3 + 1;
  }
  FUN_000636d2(iVar3);
  *(char *)(param_2 + 8) = (char)iVar3;
  return;
}


