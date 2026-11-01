/* ROM address: 0x00052ed2; body bytes: 128; decompiled */

void FUN_00052ed2(void)

{
  char cVar1;
  
  if (DAT_ffffd079 == '\x01') {
    DAT_ffffd155 = 0;
    DAT_ffffd156 = 0;
  }
  else if ((DAT_ffffd075 == '\x01') || (DAT_ffffcfb4 == '\x01')) {
    cVar1 = FUN_0003eaa4(&DAT_ffff8706,0);
    if ((cVar1 == '\x01') && (cVar1 = FUN_000671a4(0x7a), cVar1 == '\0')) {
      DAT_ffffd155 = 1;
    }
    cVar1 = FUN_0003eaa4(&DAT_ffff8708,0);
    if ((cVar1 == '\x01') && (cVar1 = FUN_000671a4(0x7a), cVar1 == '\0')) {
      DAT_ffffd156 = 1;
    }
  }
  FUN_00053688();
  return;
}


