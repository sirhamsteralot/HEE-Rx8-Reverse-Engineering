/* ROM address: 0x0004d070; body bytes: 188; decompiled */

void FUN_0004d070(void)

{
  DAT_ffffcf7e = DAT_ffffc023 == '\x01';
  DAT_ffffcf7f = DAT_ffffc024 == '\x01';
  if ((((DAT_ffffcfa3 == '\0') && (DAT_ffffc021 == '\x01')) ||
      ((DAT_ffffcfa5 == '\0' && (DAT_ffffc022 == '\x01')))) ||
     ((((DAT_ffffcfac == '\x01' || (DAT_ffffc023 != '\x01')) || (DAT_ffffcf70 == '\0')) ||
      (DAT_ffffcf8b == '\x01')))) {
    DAT_ffffcf7d = 0;
  }
  else if ((DAT_ffffcfad == '\0') && (DAT_ffffcf81 == '\x01')) {
    DAT_ffffcf7d = 1;
  }
  DAT_ffffcfac = 0;
  DAT_ffffcfad = DAT_ffffcf81;
  DAT_ffffcfa3 = DAT_ffffc021;
  DAT_ffffcfa5 = DAT_ffffc022;
  return;
}


