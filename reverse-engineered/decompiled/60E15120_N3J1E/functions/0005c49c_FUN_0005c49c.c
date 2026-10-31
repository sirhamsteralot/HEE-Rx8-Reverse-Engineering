/* ROM address: 0x0005c49c; body bytes: 170; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ac8c (170 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * FUN_0005c49c(undefined2 *param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == -0x16e6) {
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd320 = '\0';
      }
      else {
        DAT_ffffd320 = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd33f = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd320 = '\0';
      }
    }
  }
  if (DAT_ffffd320 == '\0') {
    DAT_ffffd33f = param_1 != (undefined2 *)0x0;
  }
  else if ((DAT_ffffd320 == '\a') && (param_1 = (undefined2 *)0x0, DAT_ffffd33f == '\x01')) {
    param_1 = &DAT_00010000;
  }
  return param_1;
}


