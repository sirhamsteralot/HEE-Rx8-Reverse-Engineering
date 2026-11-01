/* ROM address: 0x00053fc0; body bytes: 96; decompiled */

uint FUN_00053fc0(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_00011f34();
  if (((cVar2 == '\x01') && (DAT_ffffd1d1 == '\0')) || (DAT_ffffd201 == '\x01')) {
    uVar1 = FUN_0003ebc0(&DAT_ffff8fee,0);
  }
  else if ((DAT_ffffcb3b == '\x01') || (uVar1 = (uint)DAT_ffffcb3a, uVar1 == 1)) {
    uVar1 = FUN_0003ebc0(&DAT_ffff8fee,1);
  }
  DAT_ffffd1d1 = cVar2;
  return uVar1;
}


