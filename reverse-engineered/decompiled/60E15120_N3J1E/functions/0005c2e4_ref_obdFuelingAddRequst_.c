/* ROM address: 0x0005c2e4; body bytes: 186; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005aad4 (186 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_obdFuelingAddRequst_(uint param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == -0x16ec) {
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd31e = '\0';
      }
      else {
        DAT_ffffd31e = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd33b = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd31e = '\0';
      }
    }
  }
  if (DAT_ffffd31e == '\0') {
    DAT_ffffd33b = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd31e == '\x05') || (DAT_ffffd31e == '\a')) &&
          (param_1 = 0, DAT_ffffd33b == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


