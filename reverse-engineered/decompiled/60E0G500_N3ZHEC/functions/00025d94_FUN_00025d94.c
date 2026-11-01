/* ROM address: 0x00025d94; body bytes: 70; decompiled */

void FUN_00025d94(void)

{
  undefined4 local_c [2];
  
  DAT_ffffb5e4 = DAT_ffffcd01 != '\x01';
  FUN_00002054(local_c,0xe0);
  FUN_00004bbc(0xfffff746,0x800,DAT_ffffb5e4 == '\x01');
  FUN_00002064(local_c[0]);
  return;
}


