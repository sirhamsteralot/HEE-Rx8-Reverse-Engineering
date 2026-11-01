/* ROM address: 0x000370b0; body bytes: 122; decompiled */

char FUN_000370b0(void)

{
  char cVar1;
  
  if ((((DAT_ffffc29d == '\x01') && (DAT_ffffc29e == '\0')) && (DAT_ffffc297 == '\0')) &&
     (DAT_ffffc2d1 == '\0')) {
    DAT_ffffc297 = '\x01';
    DAT_ffffc2d1 = '\x02';
    FUN_00036a74(2);
    DAT_ffffc29e = '\x01';
    DAT_ffffc29d = '\0';
  }
  cVar1 = DAT_ffffc29e;
  if (DAT_ffffc29e == '\x01') {
    FUN_00036d68((int)DAT_ffffc2d1);
    cVar1 = DAT_ffffc2f8;
    if (DAT_ffffc2f8 == '\x01') {
      DAT_ffffc2d2 = 0;
      DAT_ffffc297 = '\0';
      DAT_ffffc2d1 = '\0';
      DAT_ffffc29e = '\0';
    }
  }
  return cVar1;
}


