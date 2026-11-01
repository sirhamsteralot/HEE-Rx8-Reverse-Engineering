/* ROM address: 0x00006f16; body bytes: 136; decompiled */

void FUN_00006f16(int param_1)

{
  byte bVar1;
  
  if (param_1 == 0) {
    bVar1 = DAT_fffff819;
    DAT_fffff819 = bVar1 & 0xdf;
    DAT_fffff818 = 0xb;
    bVar1 = DAT_fffff76e;
    DAT_fffff76e = bVar1 & 0x7f | 0x80;
    bVar1 = DAT_fffff819;
    DAT_fffff819 = bVar1 & 0xaf | 0x80;
    bVar1 = DAT_fffff839;
    DAT_fffff839 = bVar1 & 0xdf;
    DAT_fffff838 = 0x4b;
  }
  else {
    bVar1 = DAT_fffff819;
    DAT_fffff819 = bVar1 & 0xdf;
    DAT_fffff818 = 10;
    bVar1 = DAT_fffff76e;
    DAT_fffff76e = bVar1 & 0x7f | 0x80;
    bVar1 = DAT_fffff819;
    DAT_fffff819 = bVar1 & 0xaf | 0x80;
    bVar1 = DAT_fffff839;
    DAT_fffff839 = bVar1 & 0xdf;
    DAT_fffff838 = 0x4a;
  }
  bVar1 = DAT_fffff72e;
  DAT_fffff72e = bVar1 & 0x7f | 0x80;
  bVar1 = DAT_fffff839;
  DAT_fffff839 = bVar1 & 0xaf | 0x80;
  DAT_ffff9f27 = 1;
  return;
}


