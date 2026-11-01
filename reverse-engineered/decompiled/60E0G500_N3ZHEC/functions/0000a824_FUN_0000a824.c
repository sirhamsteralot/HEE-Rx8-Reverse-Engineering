/* ROM address: 0x0000a824; body bytes: 44; decompiled */

undefined4 FUN_0000a824(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 local_8 [2];
  
  FUN_00002054(local_8,0xe0);
  uVar1 = DAT_fffff738;
  uVar2 = DAT_fffff738;
  DAT_fffff738 = ~(uVar1 | 0x7fff) + (uVar2 & 0x7fff);
  uVar3 = FUN_00002064(local_8[0]);
  return uVar3;
}


