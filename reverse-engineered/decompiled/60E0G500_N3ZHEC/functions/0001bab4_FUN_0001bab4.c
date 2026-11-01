/* ROM address: 0x0001bab4; body bytes: 114; decompiled */

char FUN_0001bab4(undefined1 param_1)

{
  char cVar1;
  
  if (DAT_ffffbdb4 == '\x01') {
    param_1 = (DAT_ffff9ec8 & 0x20) != 0;
    if (param_1 != DAT_ffffad92) {
      DAT_ffffad91 = '\x04';
    }
    cVar1 = param_1;
    if (DAT_ffffad91 == '\0') {
      if ((bool)param_1) {
        DAT_ffffad90 = 1;
      }
      else if (!(bool)param_1) {
        DAT_ffffad90 = 0;
      }
    }
    else {
      DAT_ffffad91 = DAT_ffffad91 + -1;
    }
  }
  else {
    DAT_ffffad90 = DAT_ffffbc37;
    cVar1 = DAT_ffffbdb4;
  }
  DAT_ffffad92 = param_1;
  return cVar1;
}


