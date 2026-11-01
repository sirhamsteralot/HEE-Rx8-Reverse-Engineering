/* ROM address: 0x0005d8d8; body bytes: 186; decompiled */

uint FUN_0005d8d8(uint param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x17e1) {
      if ((DAT_ffffd3a8 & 0xe0) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd36a = '\0';
      }
      else {
        DAT_ffffd36a = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd397 = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0xe0) == 0) {
        DAT_ffffd36a = '\0';
      }
    }
  }
  if (DAT_ffffd36a == '\0') {
    DAT_ffffd397 = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd36a == '\x05') || (DAT_ffffd36a == '\a')) &&
          (param_1 = 0, DAT_ffffd397 == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


