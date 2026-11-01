/* ROM address: 0x00037246; body bytes: 228; decompiled */

void FUN_00037246(void)

{
  char cVar1;
  
  if (DAT_ffffaae0 == '\x01') {
    if (DAT_ffffb5b8 < 500.0) {
      cVar1 = FUN_00056f4e(0x271);
    }
    else {
      cVar1 = '\0';
    }
    DAT_ffffc2aa = cVar1 == '\x01';
    FUN_000373b8();
    FUN_00037406();
    if ((((DAT_ffffc242 == '3') || ((DAT_ffffc2e5 & 2) != 0)) || (DAT_ffffc2aa == '\x01')) &&
       ((cVar1 = FUN_000565e2(0), cVar1 == '\0' || (cVar1 = FUN_000565e2(2), cVar1 == '\0')))) {
      FUN_0003744c();
      FUN_00037528();
    }
    else {
      FUN_00037354();
    }
  }
  else if ((DAT_ffffc2b6 == '\x01') && ((DAT_ffffc2e5 & 2) == 0)) {
    FUN_00037354();
  }
  else {
    DAT_ffffc2a8 = 0;
    DAT_ffffc2b7 = 0;
    DAT_ffffc2a4 = 0;
    DAT_ffffc2ac = 0;
  }
  DAT_ffffc2b6 = DAT_ffffaae0;
  return;
}


