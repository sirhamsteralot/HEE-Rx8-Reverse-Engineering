/* ROM address: 0x00007188; body bytes: 98; decompiled */

void FUN_00007188(void)

{
  byte bVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_00003920(0xb0);
  bVar1 = DAT_fffff002;
  DAT_fffff002 = bVar1 & 0xb;
  DAT_fffff000 = 0x80;
  bVar1 = DAT_fffff002;
  DAT_fffff002 = bVar1 & 0xfc;
  DAT_fffff006 = 0xf0;
  DAT_fffff001 = 4;
  FUN_00004bbc(0xfffff72c,0x4000,1);
  FUN_00004bbc(0xfffff72c,0x8000,1);
  bVar1 = DAT_fffff002;
  DAT_fffff002 = bVar1 & 0xb | 0x30;
  FUN_000071ea((int)(char)(DAT_ffff9f34 | DAT_ffff9f35));
  FUN_00003934(uVar2);
  return;
}


