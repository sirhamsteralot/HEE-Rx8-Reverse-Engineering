/* ROM address: 0x0005db2c; body bytes: 156; decompiled */

int FUN_0005db2c(int param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x175d) {
      if ((DAT_ffffd3a8 & 0x60) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd36d = '\0';
      }
      else {
        DAT_ffffd36d = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd39d = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0x60) == 0) {
        DAT_ffffd36d = '\0';
      }
    }
  }
  if (DAT_ffffd36d == '\0') {
    DAT_ffffd39d = (char)param_1;
  }
  else if ((DAT_ffffd36d == '\x05') || (DAT_ffffd36d == '\a')) {
    param_1 = (int)DAT_ffffd39d;
  }
  return param_1;
}


