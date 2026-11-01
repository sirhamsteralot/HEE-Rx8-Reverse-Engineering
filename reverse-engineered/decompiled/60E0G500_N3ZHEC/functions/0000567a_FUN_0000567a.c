/* ROM address: 0x0000567a; body bytes: 234; decompiled */

void FUN_0000567a(void)

{
  short sVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 local_10 [2];
  
  DAT_fffff480 = 0x7fbf;
  if (DAT_ffff9f41 == '\x01') {
    if (DAT_ffff9f3c < 0x7e) {
      DAT_ffff9f3a = 0;
      DAT_ffff9f3e = DAT_ffff9f38;
    }
    else if ((ushort)(DAT_ffff9f38 - DAT_ffff9f3c) < 0x7e) {
      DAT_ffff9f3a = DAT_ffff9f38;
      DAT_ffff9f3e = 0;
    }
    else {
      DAT_ffff9f3a = DAT_ffff9f3c;
      DAT_ffff9f3e = DAT_ffff9f38 - DAT_ffff9f3c;
    }
  }
  sVar2 = DAT_fffff4c4;
  if (DAT_ffff9f40 == '\x01') {
    DAT_ffff9f42 = 1;
    uVar5 = DAT_ffff9f3a;
    if (DAT_ffff9f3e != 0) {
      bVar3 = DAT_fffff4cb;
      DAT_fffff4cb = bVar3 & 0x8f | 0x20;
      DAT_ffff9f40 = '\0';
      DAT_ffff9f41 = '\0';
    }
  }
  else {
    DAT_ffff9f42 = 0;
    uVar5 = DAT_ffff9f3e;
    if (DAT_ffff9f3a != 0) {
      bVar3 = DAT_fffff4cb;
      DAT_fffff4cb = bVar3 & 0x8f | 0x10;
      DAT_ffff9f40 = '\x01';
      if (DAT_ffff9f41 == '\x01') {
        uVar5 = 0;
      }
    }
    DAT_ffff9f41 = '\x01';
  }
  FUN_00002054(local_10,0xe0);
  sVar1 = DAT_fffff4c0;
  uVar4 = (sVar1 - sVar2) + 1;
  if (uVar5 < uVar4) {
    uVar5 = uVar4;
  }
  DAT_fffff4c4 = uVar5 + sVar2;
  FUN_00002064(local_10[0]);
  return;
}


