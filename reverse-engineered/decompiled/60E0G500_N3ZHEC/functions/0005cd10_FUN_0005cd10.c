/* ROM address: 0x0005cd10; body bytes: 186; decompiled */

uint FUN_0005cd10(uint param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x17c6) {
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd35d = '\0';
      }
      else {
        DAT_ffffd35d = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd37d = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd35d = '\0';
      }
    }
  }
  if (DAT_ffffd35d == '\0') {
    DAT_ffffd37d = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd35d == '\x05') || (DAT_ffffd35d == '\a')) &&
          (param_1 = 0, DAT_ffffd37d == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


