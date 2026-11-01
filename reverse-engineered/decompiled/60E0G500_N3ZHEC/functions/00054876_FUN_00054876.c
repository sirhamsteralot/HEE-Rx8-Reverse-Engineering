/* ROM address: 0x00054876; body bytes: 178; decompiled */

undefined4 FUN_00054876(void)

{
  char cVar1;
  
  cVar1 = FUN_0003eaa4(&DAT_ffff86cc,0);
  if ((((((cVar1 == '\0') && (cVar1 = FUN_0003eaa4(&DAT_ffff86c8,0), cVar1 == '\0')) &&
        (cVar1 = FUN_0003eaa4(&DAT_ffff86e8,0), cVar1 == '\0')) &&
       ((cVar1 = FUN_0003eaa4(&DAT_ffff86fe,0), cVar1 == '\0' &&
        (cVar1 = FUN_0003eaa4(&DAT_ffff8700,0), cVar1 == '\0')))) &&
      ((cVar1 = FUN_0003eaa4(&DAT_ffff86f0,0), cVar1 == '\0' &&
       ((cVar1 = FUN_0003eaa4(&DAT_ffff86f2,0), cVar1 == '\0' &&
        (cVar1 = FUN_0003eaa4(&DAT_ffff86f6,0), cVar1 == '\0')))))) &&
     ((cVar1 = FUN_0003eaa4(&DAT_ffff8706,0), cVar1 == '\0' &&
      (cVar1 = FUN_0003eaa4(&DAT_ffff86fa,0), cVar1 == '\0')))) {
    DAT_ffffd1ec = 0;
    return 0;
  }
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffd1ec = 0;
    return 1;
  }
  DAT_ffffd1ec = 1;
  return 1;
}


