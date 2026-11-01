/* ROM address: 0x00036e88; body bytes: 170; decompiled */

void FUN_00036e88(void)

{
  if (DAT_ffffc2d5 == '\0') {
    if (DAT_ffffc2d6 == '\0') {
      if (DAT_ffffc2d8 == 'Z') {
        DAT_ffffc2d5 = '\x01';
      }
      else {
        DAT_ffffc2d8 = 'Z';
        DAT_ffffc2d1 = '\f';
        FUN_00036a74(0xc);
        DAT_ffffc2d7 = '\x01';
        DAT_ffffc2d6 = '\x01';
      }
    }
    else if (DAT_ffffc2d7 == '\x01') {
      FUN_00036d68((int)DAT_ffffc2d1);
      if (DAT_ffffc2f8 == '\x01') {
        DAT_ffffc2d2 = 0;
        DAT_ffffc2d7 = 0;
        DAT_ffffc2d1 = 3;
        FUN_00036a74(3);
        return;
      }
    }
    else {
      FUN_00036d68((int)DAT_ffffc2d1);
      if (DAT_ffffc2f8 == '\x01') {
        DAT_ffffc2d2 = 0;
        DAT_ffffc2d1 = '\0';
        DAT_ffffc2d5 = '\x01';
        DAT_ffffc2d6 = '\0';
      }
    }
  }
  return;
}


