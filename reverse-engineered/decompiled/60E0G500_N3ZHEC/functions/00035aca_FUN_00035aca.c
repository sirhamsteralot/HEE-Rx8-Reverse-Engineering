/* ROM address: 0x00035aca; body bytes: 298; decompiled */

void FUN_00035aca(void)

{
  if ((DAT_ffffaae0 == '\x01') && (DAT_ffffb5e8 != '\x01')) {
    FUN_00036e88();
    FUN_000365d8();
    if (DAT_ffffc28d == '\0') {
      FUN_00035c44();
    }
    else if (DAT_ffffc28d == '\x01') {
      FUN_00035cfa();
    }
    else if (DAT_ffffc28d == '\x02') {
      FUN_00035f2a();
    }
    else if (DAT_ffffc28d == '\x03') {
      FUN_0003604a();
    }
    else if (DAT_ffffc28d == '\x04') {
      FUN_00036196();
    }
    else if (DAT_ffffc28d == '\x05') {
      FUN_00036240();
    }
    else {
      DAT_ffffc28d = '\0';
    }
    if ((((DAT_ffffc28e == '\x05') || (DAT_ffffc28e == '\x06')) && (DAT_ffffc296 == '\0')) &&
       (DAT_ffffc299 == '\0')) {
      DAT_ffffc28f = FUN_00002478((int)(char)DAT_ffffc28f,1);
    }
    else {
      DAT_ffffc28f = 0;
    }
    if (2 < DAT_ffffc28f) {
      DAT_ffffc28f = 0;
      DAT_ffffc241 = 1;
    }
  }
  else {
    DAT_ffffc28d = '\0';
    FUN_00026130(0);
    DAT_ffffc240 = 0;
    DAT_ffffc241 = 0;
  }
  DAT_ffffc299 = 0;
  FUN_000378f0();
  FUN_00037246();
  FUN_000376e8();
  FUN_00037642();
  FUN_00037818();
  FUN_00037762();
  FUN_000370b0();
  FUN_0003712a();
  FUN_000371cc();
  return;
}


