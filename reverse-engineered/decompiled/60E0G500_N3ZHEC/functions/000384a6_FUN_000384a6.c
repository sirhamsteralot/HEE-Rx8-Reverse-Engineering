/* ROM address: 0x000384a6; body bytes: 136; decompiled */

char FUN_000384a6(void)

{
  char cVar1;
  
  if ((((DAT_ffffc2cb == '\x01') && (DAT_ffffc2cc == '\0')) && (DAT_ffffc297 == '\0')) &&
     (DAT_ffffc2d1 == '\0')) {
    DAT_ffffc297 = '\x01';
    DAT_ffffc2d1 = '\n';
    FUN_00036a74(10);
    DAT_ffffc2cc = '\x01';
    DAT_ffffc2cb = '\0';
  }
  cVar1 = DAT_ffffc2cc;
  if (DAT_ffffc2cc == '\x01') {
    FUN_00036d68((int)DAT_ffffc2d1);
    cVar1 = DAT_ffffc2f8;
    if (DAT_ffffc2f8 == '\x01') {
      DAT_ffffc2d2 = 0;
      DAT_ffffc297 = '\0';
      DAT_ffffc2d1 = '\0';
      DAT_ffffc2cc = '\0';
      DAT_ffffc2cd = 1;
    }
  }
  return cVar1;
}


