/* ROM address: 0x0005ca88; body bytes: 186; decompiled */

uint FUN_0005ca88(uint param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == -0x16ec) {
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd35a = '\0';
      }
      else {
        DAT_ffffd35a = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd377 = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd35a = '\0';
      }
    }
  }
  if (DAT_ffffd35a == '\0') {
    DAT_ffffd377 = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd35a == '\x05') || (DAT_ffffd35a == '\a')) &&
          (param_1 = 0, DAT_ffffd377 == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


