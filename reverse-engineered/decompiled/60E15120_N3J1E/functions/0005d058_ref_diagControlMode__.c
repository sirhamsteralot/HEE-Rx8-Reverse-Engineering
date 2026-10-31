/* ROM address: 0x0005d058; body bytes: 186; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005b848 (186 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_diagControlMode__(uint param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == -0x16eb) {
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd32d = '\0';
      }
      else {
        DAT_ffffd32d = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd359 = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd32d = '\0';
      }
    }
  }
  if (DAT_ffffd32d == '\0') {
    DAT_ffffd359 = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd32d == '\x05') || (DAT_ffffd32d == '\a')) &&
          (param_1 = 0, DAT_ffffd359 == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


