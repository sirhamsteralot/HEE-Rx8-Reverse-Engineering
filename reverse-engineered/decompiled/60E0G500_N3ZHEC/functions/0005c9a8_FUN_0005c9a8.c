/* ROM address: 0x0005c9a8; body bytes: 186; decompiled */

uint FUN_0005c9a8(uint param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == -0x16fa) {
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd359 = '\0';
      }
      else {
        DAT_ffffd359 = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd375 = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd359 = '\0';
      }
    }
  }
  if (DAT_ffffd359 == '\0') {
    DAT_ffffd375 = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd359 == '\x05') || (DAT_ffffd359 == '\a')) &&
          (param_1 = 0, DAT_ffffd375 == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


