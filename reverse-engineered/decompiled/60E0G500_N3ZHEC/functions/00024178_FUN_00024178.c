/* ROM address: 0x00024178; body bytes: 48; decompiled */

uint FUN_00024178(void)

{
  uint uVar1;
  
  FUN_0002432a();
  uVar1 = FUN_0000b99c(&DAT_ffffb4b0,&DAT_ffffb4e8,0x1c);
  if ((uVar1 & 0xff) == 0) {
    DAT_ffffb4ac = 0;
    uVar1 = FUN_0002431c();
    return uVar1;
  }
  DAT_ffffb4ac = 1;
  return uVar1;
}


