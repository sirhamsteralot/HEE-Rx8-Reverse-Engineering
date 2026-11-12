/* ROM address: 0x0002e15e; body bytes: 278; decompiled */

uint FUN_0002e15e(void)

{
  uint uVar1;
  
  if (cruise_target_speed_kmh_ffffbfa4 - DAT_ffffbfa0 < 15.0) {
    if (cruise_target_speed_kmh_ffffbfa4 - DAT_ffffbfa0 < 15.0) {
      DAT_ffffbd55 = '\0';
    }
  }
  else {
    DAT_ffffbd55 = '\x01';
  }
  if (DAT_ffffaa68 == '\x01') {
    if (DAT_ffffbd54 == '\0') {
      DAT_ffffbd50 = 0;
    }
    else if (DAT_ffffbd50 != 0) {
      DAT_ffffbd50 = DAT_ffffbd50 + -1;
    }
  }
  else {
    DAT_ffffbd50 = 0;
  }
  if (DAT_ffffbced == '\x01') {
    if ((((DAT_ffffbfb5 == '\0') && (DAT_ffffbfba == '\0')) && (DAT_ffffbfb9 == '\0')) &&
       (DAT_ffffbd55 == '\x01')) {
      if (DAT_ffffbd52 != '\0') {
        DAT_ffffbd52 = DAT_ffffbd52 + -1;
      }
      if (DAT_ffffbd52 != '\0') {
        DAT_ffffbd54 = DAT_ffffaa68;
        return 1;
      }
      uVar1 = (uint)DAT_ffffbd4d;
      if (uVar1 == 1) {
        DAT_ffffbd4d = 0;
        DAT_ffffbd52 = 0x3e;
        DAT_ffffbd54 = DAT_ffffaa68;
        return 1;
      }
      DAT_ffffbd4d = 1;
      DAT_ffffbd52 = 0x3e;
      DAT_ffffbd54 = DAT_ffffaa68;
      return uVar1;
    }
    if (DAT_ffffbd55 == '\0') {
      DAT_ffffbd4d = 1;
      DAT_ffffbd52 = 0;
      DAT_ffffbd54 = DAT_ffffaa68;
      return 1;
    }
  }
  if ((int)DAT_ffffbd50 != 0) {
    DAT_ffffbd52 = 0;
    DAT_ffffbd4d = 1;
    DAT_ffffbd54 = DAT_ffffaa68;
    return (int)DAT_ffffbd50;
  }
  if (DAT_ffffbced == '\0') {
    DAT_ffffbd4d = 0;
    DAT_ffffbd52 = 0;
    DAT_ffffbd54 = DAT_ffffaa68;
    return 0;
  }
  DAT_ffffbd52 = 0;
  DAT_ffffbd54 = DAT_ffffaa68;
  return 0;
}


