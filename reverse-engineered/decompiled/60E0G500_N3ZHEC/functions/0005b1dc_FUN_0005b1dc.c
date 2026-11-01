/* ROM address: 0x0005b1dc; body bytes: 54; decompiled */

int FUN_0005b1dc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0003eb24(&DAT_ffff9138 + param_1 * 8,0);
  *(short *)(&DAT_ffffd2f4 + param_1 * 4) = (short)((uint)uVar1 >> 0x10);
  iVar2 = (param_1 * 2 + 1) * 2;
  *(short *)(&DAT_ffffd2f4 + iVar2) = (short)uVar1;
  return iVar2;
}


