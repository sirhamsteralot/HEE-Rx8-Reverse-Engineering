/* ROM address: 0x00035e50; body bytes: 178; decompiled */

uint FUN_00035e50(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffc28e;
  if (uVar1 == 1) {
    uVar1 = (uint)DAT_ffffc291;
    if (uVar1 == 1) {
      FUN_00036320();
      DAT_ffffc294 = 0;
      uVar1 = FUN_00036720(1);
      DAT_ffffc29a = 1;
    }
    else if (uVar1 == 3) {
      DAT_ffffc28d = 0;
    }
    else if (uVar1 == 2) {
      if ((DAT_ffffc2f2 == 0) || (2 < DAT_ffffc2f2)) {
        FUN_00026130(0);
        DAT_ffffc240 = 0;
      }
      else {
        DAT_ffffc2f2 = DAT_ffffc2f2 - 1;
        DAT_ffffc29f = 1;
        FUN_00026130(1);
        DAT_ffffc240 = 1;
        DAT_ffffc298 = 0;
      }
      DAT_ffffc286 = 0x2ee;
      FUN_000363b6();
      uVar1 = FUN_00036720(7);
      DAT_ffffc28d = 2;
    }
  }
  else {
    if (uVar1 == 3) {
      uVar1 = FUN_00035cfa();
      return uVar1;
    }
    DAT_ffffc28e = 5;
  }
  return uVar1;
}


