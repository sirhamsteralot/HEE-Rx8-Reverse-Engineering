/* ROM address: 0x00053e84; body bytes: 96; decompiled */

uint FUN_00053e84(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_00011f34();
  if (((cVar2 == '\x01') && (DAT_ffffd1cd == '\0')) || (DAT_ffffd201 == '\x01')) {
    uVar1 = FUN_0003ebc0(&DAT_ffff8fea,0);
  }
  else if ((DAT_ffffc5b2 == '\x01') || (uVar1 = (uint)DAT_ffffc5b3, uVar1 == 1)) {
    uVar1 = FUN_0003ebc0(&DAT_ffff8fea,1);
  }
  DAT_ffffd1cd = cVar2;
  return uVar1;
}


