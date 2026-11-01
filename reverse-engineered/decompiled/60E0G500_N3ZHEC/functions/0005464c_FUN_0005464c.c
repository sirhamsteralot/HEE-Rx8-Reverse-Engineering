/* ROM address: 0x0005464c; body bytes: 96; decompiled */

uint FUN_0005464c(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_00011f34();
  if (((cVar2 == '\x01') && (DAT_ffffd1e7 == '\0')) || (DAT_ffffd201 == '\x01')) {
    uVar1 = FUN_0003ebc0(&DAT_ffff9004,0);
  }
  else if ((DAT_ffffd1e6 == '\x01') || (uVar1 = (uint)DAT_ffffd1e5, uVar1 == 1)) {
    uVar1 = FUN_0003ebc0(&DAT_ffff9004,1);
  }
  DAT_ffffd1e7 = cVar2;
  return uVar1;
}


