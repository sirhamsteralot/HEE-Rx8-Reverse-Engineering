/* ROM address: 0x0005cec8; body bytes: 186; decompiled */

uint FUN_0005cec8(uint param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x17c3) {
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd35f = '\0';
      }
      else {
        DAT_ffffd35f = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd381 = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd35f = '\0';
      }
    }
  }
  if (DAT_ffffd35f == '\0') {
    DAT_ffffd381 = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd35f == '\x05') || (DAT_ffffd35f == '\a')) &&
          (param_1 = 0, DAT_ffffd381 == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


