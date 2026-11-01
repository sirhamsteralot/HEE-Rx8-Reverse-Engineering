/* ROM address: 0x0000bdfa; body bytes: 54; decompiled */

int FUN_0000bdfa(undefined4 param_1)

{
  short sVar1;
  undefined4 local_c;
  undefined4 uStack_8;
  
  uStack_8 = param_1;
  FUN_0000bf3a();
  FUN_0000bfa0(uStack_8,2);
  sVar1 = FUN_0000c02c();
  uStack_8._0_2_ = sVar1;
  FUN_00002054(&local_c,0xe0);
  FUN_00004bbc(0xfffff74e,0x400,0);
  FUN_00002064(local_c);
  return (int)uStack_8._0_2_;
}


