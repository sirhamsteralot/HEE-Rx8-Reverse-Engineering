/* ROM address: 0x0000bed8; body bytes: 98; decompiled */

bool FUN_0000bed8(void)

{
  ushort uVar1;
  undefined4 local_1c;
  undefined4 auStack_18 [2];
  
  FUN_00002054(auStack_18,0xe0);
  FUN_00004bbc(0xfffff74e,0x400,1);
  FUN_00002064(auStack_18[0]);
  FUN_0000239c(1);
  uVar1 = DAT_fffff738;
  FUN_00002054(&local_1c,0xe0);
  FUN_00004bbc(0xfffff74e,0x400,0);
  FUN_00002064(local_1c);
  return (uVar1 & 0x800) == 0;
}


