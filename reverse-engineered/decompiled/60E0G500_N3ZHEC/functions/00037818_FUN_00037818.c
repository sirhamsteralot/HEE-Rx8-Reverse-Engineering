/* ROM address: 0x00037818; body bytes: 122; decompiled */

char FUN_00037818(void)

{
  char cVar1;
  
  if ((((DAT_ffffc2b4 == '\x01') && (DAT_ffffc2b5 == '\0')) && (DAT_ffffc297 == '\0')) &&
     (DAT_ffffc2d1 == '\0')) {
    DAT_ffffc297 = '\x01';
    DAT_ffffc2d1 = '\x0f';
    FUN_00036a74(0xf);
    DAT_ffffc2b5 = '\x01';
    DAT_ffffc2b4 = '\0';
  }
  cVar1 = DAT_ffffc2b5;
  if (DAT_ffffc2b5 == '\x01') {
    FUN_00036d68((int)DAT_ffffc2d1);
    cVar1 = DAT_ffffc2f8;
    if (DAT_ffffc2f8 == '\x01') {
      DAT_ffffc2d2 = 0;
      DAT_ffffc297 = '\0';
      DAT_ffffc2d1 = '\0';
      DAT_ffffc2b5 = '\0';
    }
  }
  return cVar1;
}


