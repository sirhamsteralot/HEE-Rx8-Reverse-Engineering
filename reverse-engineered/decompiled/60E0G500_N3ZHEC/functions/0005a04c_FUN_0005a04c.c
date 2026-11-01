/* ROM address: 0x0005a04c; body bytes: 144; decompiled */

char FUN_0005a04c(void)

{
  if (((DAT_ffffa41c == '\x01') && (DAT_ffffce18 == '\0')) && (DAT_ffffd2ad == '\0')) {
    DAT_ffffd29a = 1;
  }
  else {
    DAT_ffffd29a = 0;
  }
  if (((DAT_ffffa41c == '\0') && (DAT_ffffce18 == '\0')) &&
     ((DAT_ffffd2ad == '\0' && (DAT_ffffaada == '\x01')))) {
    DAT_ffffd29b = 1;
  }
  else {
    DAT_ffffd29b = 0;
  }
  if (((DAT_ffffa41c != '\x01') || (DAT_ffffb600 <= 20.0)) || (14.60938 <= DAT_ffffb600)) {
    DAT_ffffd29c = 0;
  }
  else {
    DAT_ffffd29c = 1;
  }
  return DAT_ffffa41c;
}


