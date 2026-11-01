/* ROM address: 0x0005da90; body bytes: 156; decompiled */

int FUN_0005da90(int param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x175c) {
      if ((DAT_ffffd3a8 & 0x60) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd36c = '\0';
      }
      else {
        DAT_ffffd36c = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd39b = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0x60) == 0) {
        DAT_ffffd36c = '\0';
      }
    }
  }
  if (DAT_ffffd36c == '\0') {
    DAT_ffffd39b = (char)param_1;
  }
  else if ((DAT_ffffd36c == '\x05') || (DAT_ffffd36c == '\a')) {
    param_1 = (int)DAT_ffffd39b;
  }
  return param_1;
}


