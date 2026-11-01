/* ROM address: 0x0005dccc; body bytes: 178; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0005dccc(uint param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x175f) {
      if ((DAT_ffffd3a8 & 0x60) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd36f = '\0';
      }
      else {
        DAT_ffffd36f = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          _DAT_ffffd3a1 = DAT_ffffd352;
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0x60) == 0) {
        DAT_ffffd36f = '\0';
      }
    }
  }
  if (DAT_ffffd36f == '\0') {
    _DAT_ffffd3a1 = (ushort)param_1;
  }
  else if ((DAT_ffffd36f == '\x05') || (DAT_ffffd36f == '\a')) {
    param_1 = (uint)_DAT_ffffd3a1;
  }
  return param_1;
}


