/* ROM address: 0x00065688; body bytes: 96; decompiled */

void FUN_00065688(ushort *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)((int)param_1 + 7);
  iVar2 = (int)cVar1;
  if (cVar1 == -0x80) {
    iVar2 = 0xc0;
    if (*(char *)(param_2 + 6) != -0x40) {
      iVar2 = 0;
    }
  }
  else if ((cVar1 == -0x40) && ((byte)(&DAT_0007dfea)[*param_1] <= *(byte *)(param_2 + 9))) {
    iVar2 = 0;
  }
  FUN_000635ee(iVar2);
  *(char *)(param_2 + 7) = (char)iVar2;
  return;
}


