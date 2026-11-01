/* ROM address: 0x0000ac02; body bytes: 126; decompiled */

undefined4 FUN_0000ac02(void)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 local_8 [2];
  
  FUN_00002054(local_8,0xe0);
  bVar1 = DAT_fffff45a;
  DAT_fffff45a = bVar1 & 0xf8 | 1;
  bVar1 = DAT_fffff45a;
  DAT_fffff45a = bVar1 & 0x8f | 0x10;
  bVar1 = DAT_fffff628;
  DAT_fffff628 = bVar1 & 0x8f | 0x10;
  uVar2 = DAT_fffff462;
  DAT_fffff462 = uVar2 & 0xffbf;
  uVar2 = DAT_fffff462;
  DAT_fffff462 = uVar2 & 0xff7f;
  uVar2 = DAT_fffff632;
  DAT_fffff632 = uVar2 & 0xff7f;
  uVar2 = DAT_fffff464;
  DAT_fffff464 = uVar2 & 0xfffe;
  uVar2 = DAT_fffff464;
  DAT_fffff464 = uVar2 & 0xfffe;
  uVar2 = DAT_fffff630;
  DAT_fffff630 = uVar2 & 0xff7f;
  uVar2 = DAT_fffff66c;
  DAT_fffff66c = uVar2 & 0xffbf;
  uVar2 = DAT_fffff66c;
  DAT_fffff66c = uVar2 & 0xff7f;
  uVar2 = DAT_fffff66c;
  DAT_fffff66c = uVar2 & 0x7fff;
  uVar3 = FUN_00002064(local_8[0]);
  return uVar3;
}


