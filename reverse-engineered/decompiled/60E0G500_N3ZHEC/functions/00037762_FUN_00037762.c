/* ROM address: 0x00037762; body bytes: 142; decompiled */

void FUN_00037762(void)

{
  if ((DAT_ffffc2b4 == '\0') && (DAT_ffffc2cb == '\0')) {
    if ((DAT_ffffc2b2 == '\x01') &&
       (((DAT_ffffc2b3 == '\0' && (DAT_ffffc297 == '\0')) && (DAT_ffffc2d1 == '\0')))) {
      DAT_ffffc297 = '\x01';
      DAT_ffffc2d1 = '\x0e';
      FUN_00036a74(0xe);
      DAT_ffffc2b3 = '\x01';
      DAT_ffffc2b2 = '\0';
    }
    if ((DAT_ffffc2b3 == '\x01') && (FUN_00036d68((int)DAT_ffffc2d1), DAT_ffffc2f8 == '\x01')) {
      DAT_ffffc2d2 = 0;
      DAT_ffffc297 = '\0';
      DAT_ffffc2d1 = '\0';
      DAT_ffffc2b3 = '\0';
    }
  }
  return;
}


