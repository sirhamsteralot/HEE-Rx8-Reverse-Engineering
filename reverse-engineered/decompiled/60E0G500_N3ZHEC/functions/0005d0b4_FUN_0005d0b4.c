/* ROM address: 0x0005d0b4; body bytes: 156; decompiled */

int FUN_0005d0b4(int param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x172d) {
      if ((DAT_ffffd3a8 & 0x40) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd361 = '\0';
      }
      else {
        DAT_ffffd361 = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd385 = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0x40) == 0) {
        DAT_ffffd361 = '\0';
      }
    }
  }
  if (DAT_ffffd361 == '\0') {
    DAT_ffffd385 = (char)param_1;
  }
  else if ((DAT_ffffd361 == '\x05') || (DAT_ffffd361 == '\a')) {
    param_1 = (int)DAT_ffffd385;
  }
  return param_1;
}


