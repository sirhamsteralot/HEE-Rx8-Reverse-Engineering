/* ROM address: 0x000070ac; body bytes: 170; decompiled */

int FUN_000070ac(char param_1)

{
  byte bVar1;
  undefined4 uVar2;
  char cVar3;
  
  uVar2 = FUN_00003920(0xb0);
  bVar1 = DAT_fffff002;
  DAT_fffff002 = bVar1 & 0xb;
  DAT_fffff000 = 0x80;
  bVar1 = DAT_fffff002;
  DAT_fffff002 = bVar1 & 0xfc;
  DAT_fffff006 = 0xf0;
  DAT_fffff001 = 4;
  if (param_1 == '\0') {
    FUN_00004bbc(0xfffff72c,0x4000,0);
    FUN_00004bbc(0xfffff72c,0x8000,0);
  }
  else {
    if (param_1 != '\x01') {
      FUN_00004bbc(0xfffff72c,0x4000,0);
    }
    else {
      FUN_00004bbc(0xfffff72c,0x4000,1);
    }
    FUN_00004bbc(0xfffff72c,0x8000,param_1 != '\x01');
  }
  bVar1 = DAT_fffff002;
  DAT_fffff002 = bVar1 & 0xb | 0x30;
  cVar3 = FUN_000071ea(0xff);
  FUN_00003934(uVar2);
  return (int)cVar3;
}


