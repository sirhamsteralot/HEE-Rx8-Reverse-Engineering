/* ROM address: 0x000076b8; body bytes: 108; decompiled */

void FUN_000076b8(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = DAT_fffff42a;
  DAT_fffff42a = bVar1 & 0xfc | 1;
  uVar2 = DAT_fffff42e;
  DAT_fffff42e = uVar2 & 0xfffe;
  bVar1 = DAT_fffff6e4;
  DAT_fffff6e4 = bVar1 & 0xfc | 1;
  uVar2 = DAT_fffff6ea;
  DAT_fffff6ea = uVar2 & 0xfffd;
  uVar2 = DAT_fffff6ea;
  DAT_fffff6ea = uVar2 & 0xfffe;
  uVar2 = DAT_fffff6ea;
  DAT_fffff6ea = uVar2 & 0xfff7;
  DAT_fffff6e0 = 200;
  bVar1 = DAT_fffff6e4;
  DAT_fffff6e4 = bVar1 & 0xfb | 4;
  bVar1 = DAT_fffff6e4;
  DAT_fffff6e4 = bVar1 & 0xf7;
  bVar1 = DAT_fffff6e4;
  DAT_fffff6e4 = bVar1 & 0xef;
  bVar1 = DAT_fffff6e4;
  DAT_fffff6e4 = bVar1 & 0xbf;
  bVar1 = DAT_fffff6e4;
  DAT_fffff6e4 = bVar1 & 0xdf;
  bVar1 = DAT_fffff6e4;
  DAT_fffff6e4 = bVar1 & 0x7f;
  DAT_fffff6d4 = 0xfa000;
  return;
}


