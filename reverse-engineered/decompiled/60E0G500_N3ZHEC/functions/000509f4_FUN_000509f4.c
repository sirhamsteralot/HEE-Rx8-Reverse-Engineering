/* ROM address: 0x000509f4; body bytes: 146; decompiled */

uint FUN_000509f4(void)

{
  uint uVar1;
  char cVar2;
  
  if (DAT_ffffd079 == '\x01') {
    DAT_ffffd07e = 0;
    DAT_ffffd07f = 0;
    uVar1 = 1;
  }
  else if ((DAT_ffffd075 == '\x01') || (uVar1 = (uint)DAT_ffffcfb4, uVar1 == 1)) {
    cVar2 = FUN_0003eaa4(&DAT_ffff86c8,0);
    if ((cVar2 == '\x01') && (cVar2 = FUN_000671a4(0x31), cVar2 == '\0')) {
      DAT_ffffd07e = 1;
      FUN_0003ebc0(&DAT_ffff86c8,0);
    }
    uVar1 = FUN_0003eaa4(&DAT_ffff86ca,0);
    uVar1 = uVar1 & 0xff;
    if (uVar1 == 1) {
      uVar1 = FUN_000671a4(0x31);
      uVar1 = uVar1 & 0xff;
      if (uVar1 == 0) {
        DAT_ffffd07f = 1;
        uVar1 = FUN_0003ebc0(&DAT_ffff86ca,0);
        return uVar1;
      }
    }
  }
  return uVar1;
}


