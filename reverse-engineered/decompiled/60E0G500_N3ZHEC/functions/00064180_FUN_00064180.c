/* ROM address: 0x00064180; body bytes: 38; decompiled */

void FUN_00064180(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)DAT_ffff8d74 * 0x34;
  (&DAT_ffff8962)[iVar1] = (&DAT_ffff8962)[iVar1] + ((&DAT_ffff8938)[iVar1] - param_1);
  (&DAT_ffff8938)[iVar1] = param_1;
  return;
}


