/* ROM address: 0x00008dae; body bytes: 58; decompiled */

void FUN_00008dae(undefined4 param_1,byte param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00003920(0x10);
  iVar2 = (uint)param_2 * 8;
  *(undefined4 *)(&DAT_ffffa0d8 + iVar2) = param_1;
  (&DAT_ffffa0dd)[iVar2] = 0;
  (&DAT_ffffa0dc)[iVar2] = 2;
  FUN_000091c6((int)(char)param_2);
  FUN_00003934(uVar1);
  return;
}


