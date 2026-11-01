/* ROM address: 0x00025c50; body bytes: 148; decompiled */

void FUN_00025c50(void)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  char cVar4;
  undefined4 local_18;
  undefined2 uStack_14;
  
  uStack_14 = FUN_0000231c(0,25000);
  FUN_00002054(&local_18,0xe0);
  DAT_ffff9f3c = uStack_14;
  DAT_ffff9f38 = 25000;
  DAT_ffff9f42 = 0;
  DAT_ffff9f40 = 0;
  DAT_ffff9f41 = 1;
  sVar2 = DAT_fffff4c0;
  DAT_fffff4c4 = sVar2 + 1;
  bVar3 = DAT_fffff4cb;
  DAT_fffff4cb = bVar3 & 0x8f | 0x20;
  DAT_fffff480 = 0xffbf;
  uVar1 = DAT_fffff482;
  DAT_fffff482 = uVar1 & 0xffbf | 0x40;
  DAT_ffff9f43 = 0x5a;
  cVar4 = FUN_00009f12();
  if (cVar4 == '\0') {
    do {
      uVar1 = DAT_fffff480;
    } while ((uVar1 & 0x40) == 0);
    DAT_fffff4c4 = sVar2 + 0x9c6;
    DAT_fffff480 = 0xffbf;
  }
  FUN_00002064(local_18);
  return;
}


