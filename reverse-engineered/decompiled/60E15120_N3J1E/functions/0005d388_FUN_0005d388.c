/* ROM address: 0x0005d388; body bytes: 156; decompiled */

int FUN_0005d388(int param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x175d) {
      if ((DAT_ffffd36c & 0x60) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd331 = '\0';
      }
      else {
        DAT_ffffd331 = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd361 = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0x60) == 0) {
        DAT_ffffd331 = '\0';
      }
    }
  }
  if (DAT_ffffd331 == '\0') {
    DAT_ffffd361 = (char)param_1;
  }
  else if ((DAT_ffffd331 == '\x05') || (DAT_ffffd331 == '\a')) {
    param_1 = (int)DAT_ffffd361;
  }
  return param_1;
}


