/* ROM address: 0x000656e8; body bytes: 56; decompiled */

void FUN_000656e8(ushort *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)*(char *)((int)param_1 + 7);
  if ((byte)(&DAT_0007dfea)[*param_1] <= *(byte *)(param_2 + 9)) {
    iVar1 = 0;
  }
  FUN_000635ee(iVar1);
  *(char *)(param_2 + 7) = (char)iVar1;
  return;
}


