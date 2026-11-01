/* ROM address: 0x0000f2ac; body bytes: 112; decompiled */

undefined * FUN_0000f2ac(void)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = FUN_00010230();
  DAT_ffffa4b3 = DAT_ffff9f94;
  if (cVar1 == '\x01') {
    if (4 < DAT_ffff9f94) {
      if (DAT_ffff9f94 < 0xb) {
        DAT_ffffa4b0 = 0;
        DAT_ffffa4b1 = 0;
        DAT_ffffa4b3 = DAT_ffff9f94;
        return &DAT_000792fd;
      }
      DAT_ffffa4b0 = 0;
      DAT_ffffa4b1 = 0;
      DAT_ffffa4b3 = DAT_ffff9f94;
      return &DAT_000792fd;
    }
    pcVar2 = "\x01";
  }
  else {
    if ((undefined *)(uint)DAT_ffffce6e != &UNK_00000001) {
      DAT_ffffa4b0 = 0;
      DAT_ffffa4b1 = 0;
      DAT_ffffa4b3 = DAT_ffff9f94;
      return (undefined *)(uint)DAT_ffffce6e;
    }
    pcVar2 = "";
  }
  DAT_ffffa4b1 = *pcVar2;
  DAT_ffffa4b0 = DAT_ffffa4b1;
  return (undefined *)(int)DAT_ffffa4b1;
}


