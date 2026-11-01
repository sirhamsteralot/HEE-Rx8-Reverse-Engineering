/* ROM address: 0x0000c7ba; body bytes: 208; decompiled */

void FUN_0000c7ba(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  float fVar5;
  float fVar6;
  undefined4 local_10 [2];
  
  DAT_ffff9f34 = DAT_ffff9f34 & 0xbf | 0x40;
  FUN_00007188();
  fVar5 = (float)DAT_ffffa37e * ((float)DAT_ffff9f88 / 1152.0);
  if (2.1474836e+09 <= fVar5) {
    fVar5 = fVar5 - 4.2949673e+09;
  }
  fVar6 = (float)DAT_ffffa37c * ((float)DAT_ffff9f88 / 1152.0);
  sVar4 = (short)((uint)((int)fVar5 + DAT_ffff9f9c) >> 4);
  if (2.1474836e+09 <= fVar6) {
    fVar6 = fVar6 - 4.2949673e+09;
  }
  sVar3 = (short)((uint)(int)fVar6 >> 4) + sVar4;
  FUN_00002054(local_10,0xe0);
  sVar2 = DAT_fffff600;
  sVar2 = sVar2 + 3;
  if (((short)(sVar4 - sVar2) < 0) && (sVar4 = sVar2, (short)(sVar3 - sVar2) < 0)) {
    sVar3 = sVar2;
  }
  DAT_fffff61c = sVar4;
  DAT_fffff60c = sVar3;
  FUN_0000a8a4(0xfffff658,0xffff);
  DAT_fffff66a = 0xefff;
  uVar1 = DAT_fffff66c;
  DAT_fffff66c = uVar1 & 0xefff | 0x1000;
  FUN_00002064(local_10[0]);
  return;
}


