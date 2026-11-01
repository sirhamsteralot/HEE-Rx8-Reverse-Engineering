/* ROM address: 0x00054604; body bytes: 56; decompiled */

uint FUN_00054604(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    uVar1 = FUN_0003ebc0(&DAT_ffff9006,0);
    return uVar1;
  }
  if ((DAT_ffffd1e4 != '\x01') && (DAT_ffffd1e5 != 1)) {
    return (uint)DAT_ffffd1e5;
  }
  uVar1 = FUN_0003ebc0(&DAT_ffff9006,1);
  return uVar1;
}


