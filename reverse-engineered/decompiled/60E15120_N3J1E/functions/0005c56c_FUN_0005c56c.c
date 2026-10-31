/* ROM address: 0x0005c56c; body bytes: 186; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ad5c (186 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005c56c(uint param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x17c6) {
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd321 = '\0';
      }
      else {
        DAT_ffffd321 = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd341 = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd321 = '\0';
      }
    }
  }
  if (DAT_ffffd321 == '\0') {
    DAT_ffffd341 = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd321 == '\x05') || (DAT_ffffd321 == '\a')) &&
          (param_1 = 0, DAT_ffffd341 == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


