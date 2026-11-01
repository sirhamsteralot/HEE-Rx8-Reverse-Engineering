/* ROM address: 0x0000bf3a; body bytes: 102; decompiled */

void FUN_0000bf3a(void)

{
  ushort uVar1;
  undefined4 local_18;
  undefined4 auStack_14 [2];
  
  FUN_00002054(auStack_14,0xe0);
  uVar1 = DAT_fffff75c;
  DAT_fffff75c = uVar1 & 0xfdff;
  uVar1 = DAT_fffff732;
  DAT_fffff732 = uVar1 & 0xffcf;
  FUN_00004bbc(0xfffff738,0x400,0);
  FUN_00002054(&local_18,0xe0);
  FUN_00004bbc(0xfffff74e,0x400,1);
  FUN_00002064(local_18);
  uVar1 = DAT_fffff732;
  DAT_fffff732 = uVar1 & 0xffcf | 0x10;
  FUN_00002064(auStack_14[0]);
  return;
}


