/* ROM address: 0x00034ae2; body bytes: 298; decompiled */

void FUN_00034ae2(void)

{
  if ((DAT_ffffaa68 == '\x01') && (DAT_ffffb578 != '\x01')) {
    ref_ImmoUpdateRelated();
    FUN_000355f0();
    if (DAT_ffffc21d == '\0') {
      FUN_00034c5c();
    }
    else if (DAT_ffffc21d == '\x01') {
      FUN_00034d12();
    }
    else if (DAT_ffffc21d == '\x02') {
      FUN_00034f42();
    }
    else if (DAT_ffffc21d == '\x03') {
      FUN_00035062();
    }
    else if (DAT_ffffc21d == '\x04') {
      FUN_000351ae();
    }
    else if (DAT_ffffc21d == '\x05') {
      ref_ImmoStateReadyToDriveEngineOff();
    }
    else {
      DAT_ffffc21d = '\0';
    }
    if ((((DAT_ffffc21e == '\x05') || (DAT_ffffc21e == '\x06')) && (DAT_ffffc226 == '\0')) &&
       (DAT_ffffc229 == '\0')) {
      DAT_ffffc21f = rx8_add_u8_saturate((int)(char)DAT_ffffc21f,1);
    }
    else {
      DAT_ffffc21f = 0;
    }
    if (2 < DAT_ffffc21f) {
      DAT_ffffc21f = 0;
      DAT_ffffc1d1 = 1;
    }
  }
  else {
    DAT_ffffc21d = '\0';
    ref_setImmoLight__(0);
    inferred_ram_c1d0_ffffc1d0_ffffc1d0 = 0;
    DAT_ffffc1d1 = 0;
  }
  DAT_ffffc229 = 0;
  ref_afterImmoMain();
  FUN_0003625e();
  FUN_00036700();
  FUN_0003665a();
  FUN_00036830();
  FUN_0003677a();
  FUN_000360c8();
  FUN_00036142();
  FUN_000361e4();
  return;
}


