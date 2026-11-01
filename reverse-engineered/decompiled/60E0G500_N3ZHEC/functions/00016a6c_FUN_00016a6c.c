/* ROM address: 0x00016a6c; body bytes: 128; decompiled */

void FUN_00016a6c(undefined1 param_1)

{
  byte bVar1;
  undefined4 local_20;
  undefined4 auStack_1c [2];
  
  DAT_ffffdf94 = -1;
  DAT_ffffdf92 = param_1;
  FUN_00002054(auStack_1c,0xe0);
  FUN_00004bbc(0xfffff746,0x40,0);
  FUN_00002064(auStack_1c[0]);
  bVar1 = 0;
  while ((bVar1 < 200 && (DAT_ffffdf94 == -1))) {
    FUN_0000239c(1);
    bVar1 = bVar1 + 1;
  }
  FUN_00002054(&local_20,0xe0);
  FUN_00004bbc(0xfffff746,0x40,1);
  FUN_00002064(local_20);
  return;
}


