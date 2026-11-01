/* ROM address: 0x00052f52; body bytes: 136; decompiled */

char FUN_00052f52(void)

{
  char cVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffd14a = 0;
  }
  else {
    cVar1 = FUN_0003eaa4(&DAT_ffff8706,0);
    if (cVar1 != '\x01') {
      cVar1 = FUN_0003eaa4(&DAT_ffff86f0,0);
      if (cVar1 != '\x01') {
        cVar1 = FUN_0003eaa4(&DAT_ffff86f2,0);
        if (cVar1 != '\x01') {
          cVar1 = FUN_0003eaa4(&DAT_ffff86f6,0);
          if (cVar1 != '\x01') {
            cVar1 = FUN_0003eaa4(&DAT_ffff86fa,0);
            if (cVar1 != '\x01') {
              cVar1 = FUN_0003eaa4(&DAT_ffff86fe,0);
              if (cVar1 != '\x01') {
                cVar1 = FUN_0003eaa4(&DAT_ffff8700,0);
                if (cVar1 != '\x01') {
                  return cVar1;
                }
              }
            }
          }
        }
      }
    }
    DAT_ffffd14a = 1;
  }
  return '\x01';
}


