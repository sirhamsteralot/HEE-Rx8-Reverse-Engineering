/* ROM address: 0x00053f78; body bytes: 56; decompiled */

uint FUN_00053f78(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    uVar1 = FUN_0003ebc0(&DAT_ffff8fec,0);
    return uVar1;
  }
  if ((DAT_ffffd1d0 != '\x01') && (DAT_ffffcb3a != 1)) {
    return (uint)DAT_ffffcb3a;
  }
  uVar1 = FUN_0003ebc0(&DAT_ffff8fec,1);
  return uVar1;
}


