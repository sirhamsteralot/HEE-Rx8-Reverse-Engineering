/* ROM address: 0x00035cfa; body bytes: 282; decompiled */

uint FUN_00035cfa(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffc28e;
  if (uVar1 == 3) {
    if (DAT_ffffc2e4 == '\x01') {
      DAT_ffffc290 = 0xff;
      uVar1 = FUN_00036720(9);
      DAT_ffffc28d = 0;
    }
    else {
      FUN_0003633e();
      DAT_ffffc290 = 1;
      uVar1 = FUN_00036720(9);
      DAT_ffffc27e = 500;
    }
  }
  else if (uVar1 == 4) {
    uVar1 = (uint)DAT_ffffc290;
    if (uVar1 == 1) {
      if (DAT_ffffc25c == DAT_ffffc260) {
        DAT_ffffc290 = 2;
      }
      uVar1 = FUN_00036720(9);
      return uVar1;
    }
    if (uVar1 == 2) {
      if (DAT_ffffc25c == DAT_ffffc264) {
        DAT_ffffc290 = 3;
      }
      uVar1 = FUN_00036720(9);
      return uVar1;
    }
    if (uVar1 == 3) {
      if (DAT_ffffc25c == DAT_ffffc268) {
        DAT_ffffc290 = 4;
      }
      uVar1 = FUN_00036720(9);
      return uVar1;
    }
    if (uVar1 == 4) {
      if (DAT_ffffc25c != DAT_ffffc26c) {
        uVar1 = FUN_00036720(9);
        return uVar1;
      }
      DAT_ffffc27c = 500;
      uVar1 = FUN_00036720(0xc6);
      DAT_ffffc28d = 0;
    }
  }
  else {
    DAT_ffffc28e = 5;
    if (DAT_ffffc27e != 0) {
      DAT_ffffc27e = DAT_ffffc27e + -1;
    }
    if (DAT_ffffc27e == 0) {
      FUN_00036320();
      DAT_ffffc294 = 0;
      uVar1 = FUN_00036720(1);
      DAT_ffffc29a = 1;
    }
  }
  return uVar1;
}


