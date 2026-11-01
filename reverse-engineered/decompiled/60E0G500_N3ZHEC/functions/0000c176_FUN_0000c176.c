/* ROM address: 0x0000c176; body bytes: 54; decompiled */

undefined4 FUN_0000c176(void)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 local_8 [2];
  
  FUN_00002054(local_8,0xe0);
  bVar1 = DAT_fffff629;
  DAT_fffff629 = bVar1 & 0xf8 | 1;
  uVar2 = DAT_fffff632;
  DAT_fffff632 = uVar2 & 0xffef;
  uVar2 = DAT_fffff630;
  DAT_fffff630 = uVar2 & 0xffef;
  uVar3 = FUN_00002064(local_8[0]);
  return uVar3;
}


