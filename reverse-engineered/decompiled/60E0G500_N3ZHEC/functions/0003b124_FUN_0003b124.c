/* ROM address: 0x0003b124; body bytes: 174; decompiled */

char FUN_0003b124(void)

{
  char cVar1;
  
  DAT_ffffc5c4 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006b96c);
  DAT_ffffc5b6 = DAT_ffffc12c < DAT_ffffc5c4;
  DAT_ffffc5b7 = '\x01';
  if (DAT_ffffb13a == '\x01') {
    DAT_ffffc5ac = 0x20;
  }
  else if (DAT_ffffc5ac != 0) {
    DAT_ffffc5ac = DAT_ffffc5ac + -1;
  }
  if ((((((bool)DAT_ffffc5b6) && (cVar1 = FUN_0003eaa4(&DAT_ffff8fea,0), cVar1 == '\0')) &&
       (DAT_ffffaaf9 == '\x01')) && ((DAT_ffffc5b7 == '\x01' && (cVar1 = '\0', DAT_ffffc5ac == 0))))
     || (cVar1 = DAT_ffffd2a9, DAT_ffffd2a9 == '\x01')) {
    DAT_ffffc5b8 = 1;
  }
  else {
    DAT_ffffc5b8 = 0;
  }
  return cVar1;
}


