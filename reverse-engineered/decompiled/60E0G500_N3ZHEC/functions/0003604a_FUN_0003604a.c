/* ROM address: 0x0003604a; body bytes: 256; decompiled */

uint FUN_0003604a(void)

{
  bool bVar1;
  uint uVar2;
  
  if (DAT_ffffb5b8 <= 500.0) {
    if ((DAT_ffffb5b8 <= 0.0) && (bVar1 = DAT_ffffc292 == 0, DAT_ffffc292 = 1, bVar1)) {
      DAT_ffffc282 = 15000;
    }
  }
  else {
    DAT_ffffc292 = 0;
  }
  if (DAT_ffffc28e == '\0') {
    if (DAT_ffffc2b8 == '\0') {
      DAT_ffffc2e4 = 1;
      DAT_ffffc29b = 1;
      DAT_ffffc243 = DAT_ffffc243 | 0x40;
      DAT_ffffc2c5 = 1;
    }
    DAT_ffffc296 = 1;
  }
  else if (DAT_ffffc28e == '\x01') {
    DAT_ffffc284 = 500;
    DAT_ffffc294 = 0x7f;
    FUN_00036720(0x81);
  }
  else {
    DAT_ffffc28e = '\x05';
    if (10.0 < DAT_ffffb600) {
      if (DAT_ffffc284 != 0) {
        DAT_ffffc284 = DAT_ffffc284 + -1;
      }
      if (DAT_ffffc284 == 0) {
        DAT_ffffc296 = 1;
      }
    }
  }
  uVar2 = (uint)DAT_ffffc292;
  if (uVar2 == 1) {
    if (DAT_ffffc282 != 0) {
      DAT_ffffc282 = DAT_ffffc282 + -1;
    }
    uVar2 = (uint)DAT_ffffc292;
    if ((uVar2 == 1) && (DAT_ffffc282 == 0)) {
      uVar2 = FUN_00036720(200);
      DAT_ffffc28d = 5;
      DAT_ffffc28c = 1;
      DAT_ffffc282 = 500;
    }
  }
  return uVar2;
}


