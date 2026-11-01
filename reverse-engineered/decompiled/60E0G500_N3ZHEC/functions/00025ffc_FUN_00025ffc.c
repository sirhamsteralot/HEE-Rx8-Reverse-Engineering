/* ROM address: 0x00025ffc; body bytes: 102; decompiled */

void FUN_00025ffc(void)

{
  undefined4 local_14;
  short sStack_10;
  
  sStack_10 = FUN_0000231c(0,0x100);
  FUN_00002054(&local_14,0xe0);
  DAT_ffff9f52 = 0;
  DAT_ffff9f5c = 0;
  DAT_ffff9f5a = sStack_10;
  DAT_ffff9f56 = 0x100;
  DAT_ffff9f58 = sStack_10;
  DAT_ffff9f54 = 0x100;
  if (sStack_10 == 0) {
    FUN_00004bbc(0xfffff746,0x10,0);
  }
  else {
    FUN_00004bbc(0xfffff746,0x10,1);
  }
  FUN_00002064(local_14);
  return;
}


