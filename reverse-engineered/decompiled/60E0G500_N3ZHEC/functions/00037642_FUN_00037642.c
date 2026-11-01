/* ROM address: 0x00037642; body bytes: 122; decompiled */

char FUN_00037642(void)

{
  char cVar1;
  
  if ((((DAT_ffffc2ae == '\x01') && (DAT_ffffc2af == '\0')) && (DAT_ffffc297 == '\0')) &&
     (DAT_ffffc2d1 == '\0')) {
    DAT_ffffc297 = '\x01';
    DAT_ffffc2d1 = '\t';
    FUN_00036a74(9);
    DAT_ffffc2af = '\x01';
    DAT_ffffc2ae = '\0';
  }
  cVar1 = DAT_ffffc2af;
  if (DAT_ffffc2af == '\x01') {
    FUN_00036d68((int)DAT_ffffc2d1);
    cVar1 = DAT_ffffc2f8;
    if (DAT_ffffc2f8 == '\x01') {
      DAT_ffffc2d2 = 0;
      DAT_ffffc297 = '\0';
      DAT_ffffc2d1 = '\0';
      DAT_ffffc2af = '\0';
    }
  }
  return cVar1;
}


