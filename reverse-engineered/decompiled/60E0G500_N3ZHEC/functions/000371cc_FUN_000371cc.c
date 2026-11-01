/* ROM address: 0x000371cc; body bytes: 122; decompiled */

char FUN_000371cc(void)

{
  char cVar1;
  
  if ((((DAT_ffffc29f == '\x01') && (DAT_ffffc2a0 == '\0')) && (DAT_ffffc297 == '\0')) &&
     (DAT_ffffc2d1 == '\0')) {
    DAT_ffffc297 = '\x01';
    DAT_ffffc2d1 = '\r';
    FUN_00036a74(0xd);
    DAT_ffffc2a0 = '\x01';
    DAT_ffffc29f = '\0';
  }
  cVar1 = DAT_ffffc2a0;
  if (DAT_ffffc2a0 == '\x01') {
    FUN_00036d68((int)DAT_ffffc2d1);
    cVar1 = DAT_ffffc2f8;
    if (DAT_ffffc2f8 == '\x01') {
      DAT_ffffc2d2 = 0;
      DAT_ffffc297 = '\0';
      DAT_ffffc2d1 = '\0';
      DAT_ffffc2a0 = '\0';
    }
  }
  return cVar1;
}


