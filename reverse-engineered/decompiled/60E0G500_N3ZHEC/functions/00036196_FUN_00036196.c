/* ROM address: 0x00036196; body bytes: 120; decompiled */

uint FUN_00036196(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffc28e;
  if (uVar1 == 0) {
    DAT_ffffc296 = 1;
    uVar1 = (uint)DAT_ffffc28c;
    if (uVar1 == 1) {
      DAT_ffffc28d = 5;
      uVar1 = FUN_00036240();
      return uVar1;
    }
  }
  else {
    if (uVar1 == 1) {
      DAT_ffffc27c = 500;
      DAT_ffffc296 = 0;
      uVar1 = FUN_00035e50();
      return uVar1;
    }
    DAT_ffffc28e = 5;
    if (DAT_ffffc284 != 0) {
      DAT_ffffc284 = DAT_ffffc284 + -1;
    }
    if (DAT_ffffc284 == 0) {
      DAT_ffffc296 = 1;
      uVar1 = (uint)DAT_ffffc28c;
      if (uVar1 == 1) {
        DAT_ffffc28d = 5;
        uVar1 = FUN_00036240();
        return uVar1;
      }
    }
  }
  return uVar1;
}


