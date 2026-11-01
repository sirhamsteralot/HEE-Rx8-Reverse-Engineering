/* ROM address: 0x0006936a; body bytes: 34; decompiled */

void FUN_0006936a(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_fffff430;
  (&DAT_ffffde40)[param_1 & 0xff] = param_2 * 4000 + iVar1;
  (&DAT_ffffde38)[param_1 & 0xff] = 1;
  return;
}


