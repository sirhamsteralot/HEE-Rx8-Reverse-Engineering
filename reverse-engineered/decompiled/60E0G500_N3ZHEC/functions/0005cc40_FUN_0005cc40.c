/* ROM address: 0x0005cc40; body bytes: 170; decompiled */

undefined2 * FUN_0005cc40(undefined2 *param_1)

{
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == -0x16e6) {
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd35c = '\0';
      }
      else {
        DAT_ffffd35c = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd37b = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd35c = '\0';
      }
    }
  }
  if (DAT_ffffd35c == '\0') {
    DAT_ffffd37b = param_1 != (undefined2 *)0x0;
  }
  else if ((DAT_ffffd35c == '\a') && (param_1 = (undefined2 *)0x0, DAT_ffffd37b == '\x01')) {
    param_1 = &DAT_00010000;
  }
  return param_1;
}


