/* ROM address: 0x000627e4; body bytes: 40; decompiled */

uint FUN_000627e4(uint param_1)

{
  bool bVar1;
  int iVar2;
  
  param_1 = param_1 & 0xff;
  if ((param_1 == 1) && (iVar2 = (int)DAT_ffff87b0._0_2_, bVar1 = DAT_ffff87b0._0_2_ != -1, bVar1))
  {
    param_1 = FUN_00002430(iVar2 + 1);
    DAT_ffff87b0 = param_1;
  }
  return param_1;
}


