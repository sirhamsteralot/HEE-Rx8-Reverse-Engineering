/* ROM address: 0x000427c6; body bytes: 130; decompiled */

uint FUN_000427c6(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc98d = 0;
    DAT_ffffc98c = 0;
    DAT_ffffc992 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffc98e;
    if (uVar1 == 1) {
      if (DAT_ffffaaf0 <= 44.0) {
        if (0x9b < DAT_ffffc994) {
          DAT_ffffc98c = 1;
        }
        uVar1 = FUN_00002460((int)(short)DAT_ffffc994,1);
        DAT_ffffc992 = 0;
        DAT_ffffc994 = (short)uVar1;
        return uVar1;
      }
      if (0x9b < DAT_ffffc992) {
        DAT_ffffc98d = 1;
      }
      uVar1 = FUN_00002460((int)(short)DAT_ffffc992,1);
      DAT_ffffc992 = (ushort)uVar1;
    }
    else {
      DAT_ffffc992 = 0;
    }
  }
  DAT_ffffc994 = 0;
  return uVar1;
}


