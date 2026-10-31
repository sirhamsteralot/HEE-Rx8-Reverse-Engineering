/* ROM address: 0x0005d210; body bytes: 186; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ba00 (186 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005d210(uint param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x17de) {
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd32f = '\0';
      }
      else {
        DAT_ffffd32f = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd35d = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd32f = '\0';
      }
    }
  }
  if (DAT_ffffd32f == '\0') {
    DAT_ffffd35d = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd32f == '\x05') || (DAT_ffffd32f == '\a')) &&
          (param_1 = 0, DAT_ffffd35d == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


