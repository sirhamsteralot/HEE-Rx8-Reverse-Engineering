/* ROM address: 0x0002ed52; body bytes: 278; decompiled */

uint FUN_0002ed52(void)

{
  uint uVar1;
  
  if (DAT_ffffc00c - DAT_ffffc008 < 15.0) {
    if (DAT_ffffc00c - DAT_ffffc008 < 15.0) {
      DAT_ffffbdc1 = '\0';
    }
  }
  else {
    DAT_ffffbdc1 = '\x01';
  }
  if (DAT_ffffaae0 == '\x01') {
    if (DAT_ffffbdc0 == '\0') {
      DAT_ffffbdbc = 0;
    }
    else if (DAT_ffffbdbc != 0) {
      DAT_ffffbdbc = DAT_ffffbdbc + -1;
    }
  }
  else {
    DAT_ffffbdbc = 0;
  }
  if (DAT_ffffbd59 == '\x01') {
    if ((((DAT_ffffc01d == '\0') && (DAT_ffffc022 == '\0')) && (DAT_ffffc021 == '\0')) &&
       (DAT_ffffbdc1 == '\x01')) {
      if (DAT_ffffbdbe != '\0') {
        DAT_ffffbdbe = DAT_ffffbdbe + -1;
      }
      if (DAT_ffffbdbe != '\0') {
        DAT_ffffbdc0 = DAT_ffffaae0;
        return 1;
      }
      uVar1 = (uint)DAT_ffffbdb9;
      if (uVar1 == 1) {
        DAT_ffffbdb9 = 0;
        DAT_ffffbdbe = 0x3e;
        DAT_ffffbdc0 = DAT_ffffaae0;
        return 1;
      }
      DAT_ffffbdb9 = 1;
      DAT_ffffbdbe = 0x3e;
      DAT_ffffbdc0 = DAT_ffffaae0;
      return uVar1;
    }
    if (DAT_ffffbdc1 == '\0') {
      DAT_ffffbdb9 = 1;
      DAT_ffffbdbe = 0;
      DAT_ffffbdc0 = DAT_ffffaae0;
      return 1;
    }
  }
  if ((int)DAT_ffffbdbc != 0) {
    DAT_ffffbdbe = 0;
    DAT_ffffbdb9 = 1;
    DAT_ffffbdc0 = DAT_ffffaae0;
    return (int)DAT_ffffbdbc;
  }
  if (DAT_ffffbd59 == '\0') {
    DAT_ffffbdb9 = 0;
    DAT_ffffbdbe = 0;
    DAT_ffffbdc0 = DAT_ffffaae0;
    return 0;
  }
  DAT_ffffbdbe = 0;
  DAT_ffffbdc0 = DAT_ffffaae0;
  return 0;
}


