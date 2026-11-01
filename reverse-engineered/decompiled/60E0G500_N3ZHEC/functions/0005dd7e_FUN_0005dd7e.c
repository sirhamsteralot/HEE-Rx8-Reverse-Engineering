/* ROM address: 0x0005dd7e; body bytes: 156; decompiled */

int FUN_0005dd7e(int param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x17df) {
      if ((DAT_ffffd3a8 & 0x60) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd370 = '\0';
      }
      else {
        DAT_ffffd370 = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd3a3 = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0x60) == 0) {
        DAT_ffffd370 = '\0';
      }
    }
  }
  if (DAT_ffffd370 == '\0') {
    DAT_ffffd3a3 = (char)param_1;
  }
  else if ((DAT_ffffd370 == '\x05') || (DAT_ffffd370 == '\a')) {
    param_1 = (int)DAT_ffffd3a3;
  }
  return param_1;
}


