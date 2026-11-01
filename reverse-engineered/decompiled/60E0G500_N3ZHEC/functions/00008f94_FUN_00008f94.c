/* ROM address: 0x00008f94; body bytes: 130; decompiled */

undefined4 FUN_00008f94(void)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 local_8 [2];
  
  FUN_00002054(local_8,0xe0);
  bVar1 = DAT_fffff627;
  DAT_fffff627 = bVar1 & 0xf8 | 1;
  uVar2 = DAT_fffff630;
  DAT_fffff630 = uVar2 & 0xfffe;
  uVar2 = DAT_fffff66c;
  DAT_fffff66c = uVar2 & 0xfeff;
  bVar1 = DAT_fffff626;
  DAT_fffff626 = bVar1 & 0xf8 | 1;
  uVar2 = DAT_fffff630;
  DAT_fffff630 = uVar2 & 0xfffb;
  uVar2 = DAT_fffff66c;
  DAT_fffff66c = uVar2 & 0xfbff;
  bVar1 = DAT_fffff627;
  DAT_fffff627 = bVar1 & 0x8f | 0x10;
  uVar2 = DAT_fffff630;
  DAT_fffff630 = uVar2 & 0xfffd;
  uVar2 = DAT_fffff66c;
  DAT_fffff66c = uVar2 & 0xfdff;
  bVar1 = DAT_fffff626;
  DAT_fffff626 = bVar1 & 0x8f | 0x10;
  uVar2 = DAT_fffff630;
  DAT_fffff630 = uVar2 & 0xfff7;
  uVar2 = DAT_fffff66c;
  DAT_fffff66c = uVar2 & 0xf7ff;
  uVar3 = FUN_00002064(local_8[0]);
  return uVar3;
}


