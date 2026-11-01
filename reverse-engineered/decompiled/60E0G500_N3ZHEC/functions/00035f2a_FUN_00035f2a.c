/* ROM address: 0x00035f2a; body bytes: 230; decompiled */

undefined4 * FUN_00035f2a(void)

{
  undefined4 *puVar1;
  
  if (DAT_ffffc28e == '\x02') {
    if (DAT_ffffc274 == DAT_ffffc270) {
      FUN_000362ac();
      DAT_ffffc294 = 0x7f;
      puVar1 = (undefined4 *)FUN_00036720(0x81);
      return puVar1;
    }
    FUN_00036320();
    DAT_ffffc294 = 0x81;
    puVar1 = (undefined4 *)FUN_00036720(1);
    DAT_ffffc29a = 1;
  }
  else {
    if (DAT_ffffc28e == '\x01') {
      DAT_ffffc27c = 500;
      puVar1 = (undefined4 *)FUN_00035e50();
      return puVar1;
    }
    DAT_ffffc28e = '\x05';
    if (500.0 < DAT_ffffb5b8) {
      DAT_ffffc298 = '\x01';
    }
    if ((DAT_ffffc298 == '\x01') && (DAT_ffffc280 != 0)) {
      DAT_ffffc280 = DAT_ffffc280 + -1;
    }
    if (DAT_ffffc280 == 0) {
      FUN_00026130(0);
      DAT_ffffc240 = 0;
    }
    puVar1 = &DAT_000360d0;
    if (10.0 < DAT_ffffb600) {
      if (DAT_ffffc286 != 0) {
        DAT_ffffc286 = DAT_ffffc286 + -1;
      }
      puVar1 = &DAT_000360d0;
      if (DAT_ffffc286 == 0) {
        FUN_00036320();
        DAT_ffffc294 = 0x80;
        puVar1 = (undefined4 *)FUN_00036720(1);
        DAT_ffffc29a = 1;
      }
    }
  }
  return puVar1;
}


