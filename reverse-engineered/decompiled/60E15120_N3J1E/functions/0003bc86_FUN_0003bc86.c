/* ROM address: 0x0003bc86; body bytes: 106; decompiled */

char FUN_0003bc86(void)

{
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc5b5 = 0;
  }
  else {
    if (((DAT_ffffc5b1 != '\x01') && (DAT_ffffc5bd != '\x01')) && (DAT_ffffc5b3 != '\x01')) {
      if (DAT_ffffc5b2 != '\x01') {
        return DAT_ffffc5b2;
      }
      if (DAT_ffffc5be != '\x01') {
        return DAT_ffffc5be;
      }
      if (DAT_ffffc5b4 != '\x01') {
        return DAT_ffffc5b4;
      }
      DAT_ffffc5b5 = 0;
      DAT_ffffc5b6 = 1;
      return '\x01';
    }
    DAT_ffffc5b5 = 1;
  }
  DAT_ffffc5b6 = 0;
  return '\x01';
}


