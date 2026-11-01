/* ROM address: 0x00065738; body bytes: 118; decompiled */

void FUN_00065738(ushort *param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  
  cVar2 = (&DAT_ffff8d7c)[(uint)*param_1 * 2];
  bVar1 = *(byte *)((int)param_1 + 9);
  iVar3 = (int)(char)bVar1;
  if (*param_1 == 0) {
    cVar4 = '\0';
  }
  else {
    cVar4 = FUN_00068058((int)(short)*param_1);
  }
  if ((((cVar2 == '\x11') && (*(char *)(param_1 + 3) == -0x40)) && (cVar4 == '\0')) &&
     (bVar1 < (byte)(&DAT_0007dfea)[*param_1])) {
    iVar3 = iVar3 + 1;
  }
  FUN_00063660(iVar3);
  *(char *)(param_2 + 9) = (char)iVar3;
  return;
}


