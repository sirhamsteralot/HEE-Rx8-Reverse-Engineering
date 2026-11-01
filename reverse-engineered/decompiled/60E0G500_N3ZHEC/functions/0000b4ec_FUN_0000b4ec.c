/* ROM address: 0x0000b4ec; body bytes: 180; decompiled */

void FUN_0000b4ec(void)

{
  byte bVar1;
  ushort uVar2;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 auStack_24 [2];
  
  FUN_00002054(auStack_24,0xe0);
  FUN_00004bbc(0xfffff74e,0x80,1);
  FUN_00002064(auStack_24[0]);
  DAT_ffffa229 = 0;
  DAT_fffff008 = 0x80;
  bVar1 = DAT_fffff00a;
  DAT_fffff00a = bVar1 & 0xfc;
  DAT_fffff00e = 0xf8;
  DAT_fffff009 = 4;
  FUN_00002054(&uStack_28,0xe0);
  FUN_00004bbc(0xfffff72c,0x100,1);
  FUN_00002064(uStack_28);
  FUN_00002054(&local_2c,0xe0);
  FUN_00004bbc(0xfffff72c,0x80,1);
  FUN_00002064(local_2c);
  bVar1 = DAT_fffff69c;
  DAT_fffff69c = bVar1 & 0xfc | 2;
  DAT_fffff694 = 0;
  DAT_fffff688 = 0;
  uVar2 = DAT_fffff6a0;
  DAT_fffff6a0 = uVar2 & 0xffef | 0x10;
  DAT_ffffa322 = 0;
  DAT_ffffa320 = 0;
  DAT_ffffa228 = 0;
  return;
}


