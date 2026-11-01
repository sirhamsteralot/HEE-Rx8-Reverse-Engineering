/* ROM address: 0x0002bb80; body bytes: 86; decompiled */

uint FUN_0002bb80(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_00009890(&DAT_0004e9f8);
  if (cVar2 == '\0') {
    FUN_0000e038();
    FUN_0002bd66();
    uVar1 = FUN_0002bdb0();
    DAT_ffffbc24 = 0;
    DAT_ffffbc26 = 0;
  }
  else {
    DAT_ffffbc24 = FUN_00002460((int)(short)DAT_ffffbc24,1);
    uVar1 = (uint)DAT_ffffbc24;
    if ((DAT_ffffbc24 & 3) == 0) {
      uVar1 = FUN_00002460((int)DAT_ffffbc26,1);
      DAT_ffffbc26 = (short)uVar1;
    }
  }
  return uVar1;
}


