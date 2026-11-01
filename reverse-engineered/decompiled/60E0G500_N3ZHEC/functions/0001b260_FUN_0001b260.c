/* ROM address: 0x0001b260; body bytes: 84; decompiled */

void FUN_0001b260(void)

{
  if (DAT_ffffaa40 < 2.5) {
    if (DAT_ffffaa40 < 2.0) {
      DAT_ffffaadd = '\0';
    }
  }
  else {
    DAT_ffffaadd = '\x01';
  }
  if (DAT_ffffaadd == '\0') {
    if (DAT_ffffaad8 < 0x13) {
      DAT_ffffaadb = 1;
      DAT_ffffaada = 0;
    }
    else {
      DAT_ffffaadb = 1;
      DAT_ffffaada = 1;
    }
  }
  else {
    DAT_ffffaadb = 0;
    DAT_ffffaada = 0;
  }
  return;
}


