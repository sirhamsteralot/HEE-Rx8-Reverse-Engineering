/* ROM address: 0x0000ccda; body bytes: 54; decompiled */

void FUN_0000ccda(byte param_1,char param_2,char param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0000cee8((int)(char)param_1,&DAT_ffffe4b0);
  FUN_00009e26((int)param_2,(int)param_3,param_4,iVar1 + (param_1 & 0xf) * 8);
  return;
}


