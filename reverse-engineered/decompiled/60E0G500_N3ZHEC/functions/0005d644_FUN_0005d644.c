/* ROM address: 0x0005d644; body bytes: 186; decompiled */

uint FUN_0005d644(uint param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == -0x16ff) {
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd367 = '\0';
      }
      else {
        DAT_ffffd367 = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd391 = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd367 = '\0';
      }
    }
  }
  if (DAT_ffffd367 == '\0') {
    DAT_ffffd391 = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd367 == '\x05') || (DAT_ffffd367 == '\a')) &&
          (param_1 = 0, DAT_ffffd391 == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


