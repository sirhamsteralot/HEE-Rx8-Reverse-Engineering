/* ROM address: 0x00009ea2; body bytes: 92; decompiled */

void FUN_00009ea2(void)

{
  ushort uVar1;
  undefined4 local_4;
  
  FUN_00002054(&local_4,0xe0);
  FUN_00004bbc(0xfffff74e,8,0);
  FUN_00002064(local_4);
  do {
    do {
      FUN_0000239c(&DAT_00001388);
      FUN_0000a850();
      uVar1 = DAT_fffff74e;
    } while ((uVar1 & 1) == 0);
    FUN_00009efe();
  } while( true );
}


