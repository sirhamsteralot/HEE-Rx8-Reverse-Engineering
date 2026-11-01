/* ROM address: 0x000057c6; body bytes: 242; decompiled */

void FUN_000057c6(void)

{
  short sVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 local_10 [2];
  
  DAT_fffff480 = 0x77ff;
  if (DAT_ffff9f4d == '\x01') {
    if (DAT_ffff9f48 < 0x7e) {
      DAT_ffff9f46 = 0;
      DAT_ffff9f4a = DAT_ffff9f44;
    }
    else if ((ushort)(DAT_ffff9f44 - DAT_ffff9f48) < 0x7e) {
      DAT_ffff9f46 = DAT_ffff9f44;
      DAT_ffff9f4a = 0;
    }
    else {
      DAT_ffff9f46 = DAT_ffff9f48;
      DAT_ffff9f4a = DAT_ffff9f44 - DAT_ffff9f48;
    }
  }
  sVar2 = DAT_fffff4e4;
  if (DAT_ffff9f4c == '\x01') {
    DAT_ffff9f4e = 1;
    uVar5 = DAT_ffff9f46;
    if (DAT_ffff9f4a != 0) {
      bVar3 = DAT_fffff4eb;
      DAT_fffff4eb = bVar3 & 0x8f | 0x10;
      DAT_ffff9f4c = '\0';
      DAT_ffff9f4d = '\0';
    }
  }
  else {
    DAT_ffff9f4e = 0;
    uVar5 = DAT_ffff9f4a;
    if (DAT_ffff9f46 != 0) {
      bVar3 = DAT_fffff4eb;
      DAT_fffff4eb = bVar3 & 0x8f | 0x20;
      DAT_ffff9f4c = '\x01';
      if (DAT_ffff9f4d == '\x01') {
        uVar5 = 0;
      }
    }
    DAT_ffff9f4d = '\x01';
  }
  FUN_00002054(local_10,0xe0);
  sVar1 = DAT_fffff4e0;
  uVar4 = (sVar1 - sVar2) + 1;
  if (uVar5 < uVar4) {
    uVar5 = uVar4;
  }
  DAT_fffff4e4 = uVar5 + sVar2;
  FUN_00002064(local_10[0]);
  return;
}


