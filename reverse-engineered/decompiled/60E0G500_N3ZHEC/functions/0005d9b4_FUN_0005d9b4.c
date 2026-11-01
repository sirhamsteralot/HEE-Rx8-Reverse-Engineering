/* ROM address: 0x0005d9b4; body bytes: 186; decompiled */

uint FUN_0005d9b4(uint param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x17de) {
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd36b = '\0';
      }
      else {
        DAT_ffffd36b = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd399 = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd36b = '\0';
      }
    }
  }
  if (DAT_ffffd36b == '\0') {
    DAT_ffffd399 = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd36b == '\x05') || (DAT_ffffd36b == '\a')) &&
          (param_1 = 0, DAT_ffffd399 == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


