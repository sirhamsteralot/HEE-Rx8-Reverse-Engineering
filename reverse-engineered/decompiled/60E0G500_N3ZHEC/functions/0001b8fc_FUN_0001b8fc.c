/* ROM address: 0x0001b8fc; body bytes: 238; decompiled */

char FUN_0001b8fc(void)

{
  DAT_ffffaaf0 = DAT_ffffa1d4;
  if (50.0 < DAT_ffffa1d4) {
    if (55.0 < DAT_ffffa1d4) {
      DAT_ffffaaf9 = 0;
    }
  }
  else {
    DAT_ffffaaf9 = 1;
  }
  if (50.0 <= DAT_ffffa1d4) {
    if (55.0 <= DAT_ffffa1d4) {
      DAT_ffffad83 = '\x01';
    }
  }
  else {
    DAT_ffffad83 = '\0';
  }
  if (((DAT_ffffad70 - 0.0146 <= DAT_ffffad6c) && (DAT_ffffaae8 < DAT_ffffae74 - 0.0146)) ||
     ((DAT_ffffad6c < DAT_ffffad70 + 0.0146 && (DAT_ffffae74 + 0.0146 <= DAT_ffffaae8)))) {
    DAT_ffffad84 = '\x01';
  }
  if ((((DAT_ffffad83 == '\0') && (0.9899999 <= DAT_ffffae74)) && (DAT_ffffae74 < 1.01)) &&
     ((DAT_ffffad84 == '\x01' && (DAT_ffffa428 == '\x01')))) {
    DAT_ffffaaf8 = 1;
  }
  if (((DAT_ffffad83 == '\x01') || (DAT_ffffae74 < 0.9899999)) || (1.01 <= DAT_ffffae74)) {
    DAT_ffffaaf8 = 0;
  }
  DAT_ffffad6c = DAT_ffffaae8;
  DAT_ffffad70 = DAT_ffffae74;
  return DAT_ffffad83;
}


