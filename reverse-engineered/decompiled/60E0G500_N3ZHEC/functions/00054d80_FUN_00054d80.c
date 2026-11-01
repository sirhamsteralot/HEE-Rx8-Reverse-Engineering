/* ROM address: 0x00054d80; body bytes: 96; decompiled */

uint FUN_00054d80(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_00011f34();
  if (((cVar2 == '\x01') && (DAT_ffffd1fb == '\0')) || (DAT_ffffd201 == '\x01')) {
    uVar1 = FUN_0003ebc0(&DAT_ffff9008,0);
  }
  else if ((DAT_ffffd1f8 == '\x01') || (uVar1 = (uint)DAT_ffffd1f9, uVar1 == 1)) {
    uVar1 = FUN_0003ebc0(&DAT_ffff9008,1);
  }
  DAT_ffffd1fb = cVar2;
  return uVar1;
}


