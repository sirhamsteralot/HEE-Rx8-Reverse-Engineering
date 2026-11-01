/* ROM address: 0x0000c02c; body bytes: 170; decompiled */

int FUN_0000c02c(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  undefined4 local_10 [2];
  
  FUN_00002054(local_10,0xe0);
  uVar4 = DAT_fffff75c;
  DAT_fffff75c = uVar4 & 0xfdff | 0x200;
  FUN_00002064(local_10[0]);
  bVar1 = DAT_fffff022;
  DAT_fffff022 = bVar1 & 0xb | 0x30;
  DAT_fffff023 = 0;
  bVar1 = DAT_fffff024;
  DAT_fffff024 = bVar1 & 0x7f | 0x78;
  do {
    bVar1 = DAT_fffff024;
  } while ((bVar1 & 0x40) == 0);
  bVar2 = DAT_fffff025;
  bVar1 = DAT_fffff024;
  DAT_fffff024 = bVar1 & 0xbf | 0xb8;
  DAT_fffff023 = 0;
  bVar1 = DAT_fffff024;
  DAT_fffff024 = bVar1 & 0x7f | 0x78;
  do {
    bVar1 = DAT_fffff024;
  } while ((bVar1 & 0x40) == 0);
  bVar3 = DAT_fffff025;
  bVar1 = DAT_fffff024;
  DAT_fffff024 = bVar1 & 0xbf | 0xb8;
  bVar1 = DAT_fffff022;
  DAT_fffff022 = bVar1 & 0xb;
  FUN_00002054(local_10,0xe0);
  uVar4 = DAT_fffff75c;
  DAT_fffff75c = uVar4 & 0xfdff;
  FUN_00002064(local_10[0]);
  return (uint)bVar2 * 0x100 + (uint)bVar3;
}


