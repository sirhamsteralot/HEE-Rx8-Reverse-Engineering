/* ROM address: 0x0003712a; body bytes: 122; decompiled */

char FUN_0003712a(void)

{
  char cVar1;
  
  if ((((DAT_ffffc29b == '\x01') && (DAT_ffffc29c == '\0')) && (DAT_ffffc297 == '\0')) &&
     (DAT_ffffc2d1 == '\0')) {
    DAT_ffffc297 = '\x01';
    DAT_ffffc2d1 = '\x01';
    FUN_00036a74(1);
    DAT_ffffc29c = '\x01';
    DAT_ffffc29b = '\0';
  }
  cVar1 = DAT_ffffc29c;
  if (DAT_ffffc29c == '\x01') {
    FUN_00036d68((int)DAT_ffffc2d1);
    cVar1 = DAT_ffffc2f8;
    if (DAT_ffffc2f8 == '\x01') {
      DAT_ffffc2d2 = 0;
      DAT_ffffc297 = '\0';
      DAT_ffffc2d1 = '\0';
      DAT_ffffc29c = '\0';
    }
  }
  return cVar1;
}


