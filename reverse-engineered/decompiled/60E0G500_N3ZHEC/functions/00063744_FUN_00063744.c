/* ROM address: 0x00063744; body bytes: 32; decompiled */

void FUN_00063744(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)DAT_ffff8928 * 0x10;
  (&DAT_ffff87e6)[iVar1] = (&DAT_ffff87e6)[iVar1] + ((&DAT_ffff87e2)[iVar1] - param_1);
  (&DAT_ffff87e2)[iVar1] = param_1;
  return;
}


