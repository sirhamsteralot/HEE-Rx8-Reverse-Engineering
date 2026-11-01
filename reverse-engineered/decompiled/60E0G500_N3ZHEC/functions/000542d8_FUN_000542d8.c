/* ROM address: 0x000542d8; body bytes: 212; decompiled */

uint FUN_000542d8(void)

{
  uint uVar1;
  char cVar2;
  
  if (DAT_ffffd201 == '\x01') {
    FUN_0003ebc0(&DAT_ffff8ffa,0);
    FUN_0003ebc0(&DAT_ffff8ffc,0);
    uVar1 = FUN_0003ebc0(&DAT_ffff8ff8,0);
    return uVar1;
  }
  if (DAT_ffffd081 == '\x01') {
    FUN_0003ebc0(&DAT_ffff8ffa,0);
  }
  else if (DAT_ffffd082 == '\x01') {
    FUN_0003ebc0(&DAT_ffff8ffa,1);
  }
  if (DAT_ffffd130 == '\x01') {
    FUN_0003ebc0(&DAT_ffff8ffc,0);
  }
  else if (DAT_ffffd131 == '\x01') {
    FUN_0003ebc0(&DAT_ffff8ffc,1);
  }
  cVar2 = FUN_00060194(0x2c,0);
  if (((cVar2 != '\x01') && (cVar2 = FUN_00060194(0x2d,0), cVar2 != '\x01')) &&
     (cVar2 = FUN_00060194(0x30,0), cVar2 != '\x01')) {
    uVar1 = FUN_0003eaa4(&DAT_ffff8ffa,0);
    if ((uVar1 & 0xff) != 1) {
      return uVar1 & 0xff;
    }
    uVar1 = FUN_0003eaa4(&DAT_ffff8ffc,0);
    if ((uVar1 & 0xff) != 1) {
      return uVar1 & 0xff;
    }
  }
  uVar1 = FUN_0003ebc0(&DAT_ffff8ff8,1);
  return uVar1;
}


