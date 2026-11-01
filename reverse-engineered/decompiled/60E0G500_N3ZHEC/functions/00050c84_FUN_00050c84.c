/* ROM address: 0x00050c84; body bytes: 194; decompiled */

uint FUN_00050c84(void)

{
  char cVar1;
  uint uVar2;
  
  if ((DAT_ffffd075 == '\x01') || (DAT_ffffcfb4 == '\x01')) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  if (DAT_ffffd07a == '\x01') {
    DAT_ffffd081 = 0;
  }
  else if (((uVar2 == 1) && (cVar1 = FUN_0003eaa4(&DAT_ffff86cc,0), cVar1 == '\x01')) &&
          (cVar1 = FUN_000671a4(0x2e), cVar1 == '\0')) {
    DAT_ffffd081 = 1;
    FUN_0003ebc0(&DAT_ffff86cc,0);
  }
  if (DAT_ffffd079 == '\x01') {
    DAT_ffffd082 = 0;
    uVar2 = 1;
  }
  else if (uVar2 == 1) {
    uVar2 = FUN_0003eaa4(&DAT_ffff86ce,0);
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 1) {
      uVar2 = FUN_000671a4(0x2e);
      uVar2 = uVar2 & 0xff;
      if (uVar2 == 0) {
        DAT_ffffd082 = 1;
        uVar2 = FUN_0003ebc0(&DAT_ffff86ce,0);
        return uVar2;
      }
    }
  }
  return uVar2;
}


