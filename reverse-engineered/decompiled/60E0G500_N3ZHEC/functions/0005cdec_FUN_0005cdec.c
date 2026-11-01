/* ROM address: 0x0005cdec; body bytes: 186; decompiled */

uint FUN_0005cdec(uint param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x17c4) {
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd35e = '\0';
      }
      else {
        DAT_ffffd35e = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd37f = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd35e = '\0';
      }
    }
  }
  if (DAT_ffffd35e == '\0') {
    DAT_ffffd37f = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd35e == '\x05') || (DAT_ffffd35e == '\a')) &&
          (param_1 = 0, DAT_ffffd37f == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


