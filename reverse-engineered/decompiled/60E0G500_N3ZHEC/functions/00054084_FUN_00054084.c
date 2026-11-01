/* ROM address: 0x00054084; body bytes: 164; decompiled */

uint FUN_00054084(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    uVar1 = FUN_0003ebc0(&DAT_ffff8ff0,0);
    return uVar1;
  }
  if ((DAT_ffffd1d8 != '\x01') &&
     ((((((uVar1 = (uint)DAT_ffffc772, uVar1 != 1 || (uVar1 = (uint)DAT_ffffc746, uVar1 != 1)) ||
         (uVar1 = (uint)DAT_ffffc744, uVar1 != 1)) ||
        ((uVar1 = (uint)DAT_ffffc9de, uVar1 != 1 || (uVar1 = (uint)DAT_ffffc9dc, uVar1 != 1)))) ||
       ((uVar1 = (uint)DAT_ffffc9e0, uVar1 != 1 ||
        ((uVar1 = (uint)DAT_ffffcd54, uVar1 != 1 || (uVar1 = (uint)DAT_ffffc72c, uVar1 != 1)))))) ||
      ((uVar1 = (uint)DAT_ffffc728, uVar1 != 1 || (uVar1 = (uint)DAT_ffffc72a, uVar1 != 1)))))) {
    return uVar1;
  }
  uVar1 = FUN_0003ebc0(&DAT_ffff8ff0,1);
  return uVar1;
}


