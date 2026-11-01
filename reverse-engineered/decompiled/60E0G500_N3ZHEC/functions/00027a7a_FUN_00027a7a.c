/* ROM address: 0x00027a7a; body bytes: 102; decompiled */

void FUN_00027a7a(void)

{
  if (660.0 <= DAT_ffffb5b8) {
    DAT_ffffb72e = '\0';
  }
  if ((DAT_ffffa41c == '\0') && (DAT_ffffb72e == '\x01')) {
    DAT_ffffb714 = 4;
    DAT_ffffb716 = 0xf;
  }
  else if (DAT_ffffb71c == '\0') {
    DAT_ffffb714 = 0xff;
    DAT_ffffb716 = 0xf;
  }
  else if (DAT_ffffb714 != 0) {
    DAT_ffffb714 = DAT_ffffb714 + -1;
  }
  return;
}


