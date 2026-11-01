/* ROM address: 0x0004fde4; body bytes: 204; decompiled */

char FUN_0004fde4(void)

{
  if ((((((DAT_ffffd002 == '\x01') || (DAT_ffffcffc == '\x01')) && (DAT_ffffd036 == '\0')) &&
       (DAT_ffffcfe2 <= DAT_ffffcfe6)) ||
      (((DAT_ffffcffb == '\x01' || (DAT_ffffcffc == '\x01')) &&
       ((DAT_ffffd037 == '\0' && (DAT_ffffcfe4 <= DAT_ffffcfe6)))))) ||
     ((DAT_ffffd03d == '\0' && (DAT_ffffd12e == '\x01')))) {
    DAT_ffffd034 = DAT_ffffcfec;
  }
  else if ((DAT_ffffd035 == '\n') && (DAT_ffffd034 != '\0')) {
    DAT_ffffd034 = DAT_ffffd034 + -1;
  }
  DAT_ffffd03d = DAT_ffffd12e;
  if ((DAT_ffffcffa == '\x01') && (DAT_ffffcfe2 <= DAT_ffffcfe6)) {
    DAT_ffffd036 = 1;
  }
  else {
    DAT_ffffd036 = 0;
  }
  return DAT_ffffcffa;
}


