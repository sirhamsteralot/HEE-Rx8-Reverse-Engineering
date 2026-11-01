/* ROM address: 0x0005dbf4; body bytes: 178; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0005dbf4(uint param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x175e) {
      if ((DAT_ffffd3a8 & 0x60) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd36e = '\0';
      }
      else {
        DAT_ffffd36e = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          _DAT_ffffd39f = DAT_ffffd352;
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0x60) == 0) {
        DAT_ffffd36e = '\0';
      }
    }
  }
  if (DAT_ffffd36e == '\0') {
    _DAT_ffffd39f = (ushort)param_1;
  }
  else if ((DAT_ffffd36e == '\x05') || (DAT_ffffd36e == '\a')) {
    param_1 = (uint)_DAT_ffffd39f;
  }
  return param_1;
}


