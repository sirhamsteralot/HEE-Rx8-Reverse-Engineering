/* ROM address: 0x00051c18; body bytes: 84; decompiled */

char FUN_00051c18(void)

{
  char cVar1;
  
  if ((((DAT_ffffd132 == '\x01') && (DAT_ffffd133 == '\0')) && (DAT_ffffd134 == '\x01')) &&
     (DAT_ffffd135 == '\0')) {
    cVar1 = FUN_0003eaa4(&DAT_ffff86ec,0x17);
    if (cVar1 != '\0') {
      DAT_ffffd12d = 1;
      return cVar1;
    }
  }
  DAT_ffffd12d = 0;
  return '\0';
}


