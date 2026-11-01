/* ROM address: 0x00008d86; body bytes: 40; decompiled */

void FUN_00008d86(float param_1,byte param_2)

{
  int iVar1;
  
  param_1 = param_1 - 30.0;
  if (param_1 < 0.0) {
    param_1 = param_1 + 720.0;
  }
  iVar1 = (uint)param_2 * 8;
  *(float *)(&DAT_ffffa0d8 + iVar1) = param_1;
  (&DAT_ffffa0dd)[iVar1] = 0;
  (&DAT_ffffa0dc)[iVar1] = 1;
  return;
}


