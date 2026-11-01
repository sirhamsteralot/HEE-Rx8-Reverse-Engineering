/* ROM address: 0x0004b60c; body bytes: 64; decompiled */

void FUN_0004b60c(void)

{
  if (DAT_ffffce19 == DAT_ffffce1d) {
    if (DAT_ffffce1c != '\0') {
      DAT_ffffce1c = DAT_ffffce1c + -1;
    }
  }
  else if (DAT_ffffce19 == '\x01') {
    DAT_ffffce1c = '\0';
  }
  else {
    DAT_ffffce1c = '\0';
  }
  DAT_ffffce1d = DAT_ffffce19;
  return;
}


