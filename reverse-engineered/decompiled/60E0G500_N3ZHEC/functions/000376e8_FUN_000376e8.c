/* ROM address: 0x000376e8; body bytes: 122; decompiled */

char FUN_000376e8(void)

{
  char cVar1;
  
  if ((((DAT_ffffc2b0 == '\x01') && (DAT_ffffc2b1 == '\0')) && (DAT_ffffc297 == '\0')) &&
     (DAT_ffffc2d1 == '\0')) {
    DAT_ffffc297 = '\x01';
    DAT_ffffc2d1 = '\b';
    FUN_00036a74(8);
    DAT_ffffc2b1 = '\x01';
    DAT_ffffc2b0 = '\0';
  }
  cVar1 = DAT_ffffc2b1;
  if (DAT_ffffc2b1 == '\x01') {
    FUN_00036d68((int)DAT_ffffc2d1);
    cVar1 = DAT_ffffc2f8;
    if (DAT_ffffc2f8 == '\x01') {
      DAT_ffffc2d2 = 0;
      DAT_ffffc297 = '\0';
      DAT_ffffc2d1 = '\0';
      DAT_ffffc2b1 = '\0';
    }
  }
  return cVar1;
}


