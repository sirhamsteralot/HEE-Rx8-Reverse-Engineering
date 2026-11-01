/* ROM address: 0x00026238; body bytes: 156; decompiled */

void FUN_00026238(void)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  char cVar4;
  undefined4 local_1c;
  undefined2 uStack_18;
  
  uStack_18 = FUN_0000231c(0,1000);
  FUN_00002054(&local_1c,0xe0);
  DAT_ffff9f48 = uStack_18;
  DAT_ffff9f44 = 1000;
  DAT_ffff9f4e = 0;
  DAT_ffff9f4c = 0;
  DAT_ffff9f4d = 1;
  sVar2 = DAT_fffff4e0;
  DAT_fffff4e4 = sVar2 + 1;
  bVar3 = DAT_fffff4eb;
  DAT_fffff4eb = bVar3 & 0x8f | 0x10;
  DAT_fffff480 = 0xf7ff;
  uVar1 = DAT_fffff482;
  DAT_fffff482 = uVar1 & 0xf7ff | 0x800;
  DAT_ffff9f4f = 0x5a;
  cVar4 = FUN_00009f12();
  if (cVar4 == '\0') {
    do {
      uVar1 = DAT_fffff480;
    } while ((uVar1 & 0x800) == 0);
    DAT_fffff4e4 = sVar2 + 0x9c6;
    DAT_fffff480 = 0xf7ff;
  }
  FUN_00002064(local_1c);
  return;
}


