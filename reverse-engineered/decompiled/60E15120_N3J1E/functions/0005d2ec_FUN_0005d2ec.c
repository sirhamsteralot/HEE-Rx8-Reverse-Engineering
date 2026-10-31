/* ROM address: 0x0005d2ec; body bytes: 156; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005badc (156 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0005d2ec(int param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x175c) {
      if ((DAT_ffffd36c & 0x60) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd330 = '\0';
      }
      else {
        DAT_ffffd330 = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd35f = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0x60) == 0) {
        DAT_ffffd330 = '\0';
      }
    }
  }
  if (DAT_ffffd330 == '\0') {
    DAT_ffffd35f = (char)param_1;
  }
  else if ((DAT_ffffd330 == '\x05') || (DAT_ffffd330 == '\a')) {
    param_1 = (int)DAT_ffffd35f;
  }
  return param_1;
}


