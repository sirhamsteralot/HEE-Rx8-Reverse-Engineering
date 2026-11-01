/* ROM address: 0x00053e3c; body bytes: 56; decompiled */

uint FUN_00053e3c(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    uVar1 = FUN_0003ebc0(&DAT_ffff8fe8,0);
    return uVar1;
  }
  if ((DAT_ffffd1cc != '\x01') && (DAT_ffffc5b3 != 1)) {
    return (uint)DAT_ffffc5b3;
  }
  uVar1 = FUN_0003ebc0(&DAT_ffff8fe8,1);
  return uVar1;
}


