/* ROM address: 0x0003cbd6; body bytes: 106; decompiled */

char FUN_0003cbd6(void)

{
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc625 = 0;
  }
  else {
    if (((DAT_ffffc621 != '\x01') && (DAT_ffffc62d != '\x01')) && (DAT_ffffc623 != '\x01')) {
      if (DAT_ffffc622 != '\x01') {
        return DAT_ffffc622;
      }
      if (DAT_ffffc62e != '\x01') {
        return DAT_ffffc62e;
      }
      if (DAT_ffffc624 != '\x01') {
        return DAT_ffffc624;
      }
      DAT_ffffc625 = 0;
      DAT_ffffc626 = 1;
      return '\x01';
    }
    DAT_ffffc625 = 1;
  }
  DAT_ffffc626 = 0;
  return '\x01';
}


