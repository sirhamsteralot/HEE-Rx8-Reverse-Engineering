/* ROM address: 0x000394c6; body bytes: 74; decompiled */

char FUN_000394c6(void)

{
  if (DAT_ffffbfa4 == '\x01') {
    DAT_ffffc56e = '\x06';
  }
  else if (DAT_ffffc56e != '\0') {
    DAT_ffffc56e = DAT_ffffc56e + -1;
  }
  if (DAT_ffffc56e == '\0') {
    DAT_ffffc56f = 0;
  }
  else if (DAT_ffffbfa4 == '\x01') {
    DAT_ffffc56f = 1;
  }
  return DAT_ffffbfa4;
}


