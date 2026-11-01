/* ROM address: 0x00054138; body bytes: 134; decompiled */

uint FUN_00054138(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_00011f34();
  if (((cVar2 == '\x01') && (DAT_ffffd1d9 == '\0')) || (DAT_ffffd201 == '\x01')) {
    FUN_0003ebc0(&DAT_ffff8ff2,0);
    uVar1 = FUN_0003ebc0(&DAT_ffff8ff4,0);
  }
  else {
    if ((DAT_ffffc773 == '\x01') || (DAT_ffffc772 == '\x01')) {
      FUN_0003ebc0(&DAT_ffff8ff2,1);
    }
    if ((DAT_ffffcd55 == '\x01') || (uVar1 = (uint)DAT_ffffcd54, uVar1 == 1)) {
      uVar1 = FUN_0003ebc0(&DAT_ffff8ff4,1);
    }
  }
  DAT_ffffd1d9 = cVar2;
  return uVar1;
}


