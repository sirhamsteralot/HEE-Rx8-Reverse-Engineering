/* ROM address: 0x00054770; body bytes: 64; decompiled */

char FUN_00054770(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffc981;
  if ((((DAT_ffffc981 == '\x01') && (cVar1 = DAT_ffffc983, DAT_ffffc983 == '\x01')) &&
      (cVar1 = DAT_ffffca04, DAT_ffffca04 == '\x01')) &&
     (cVar1 = DAT_ffffca06, DAT_ffffca06 == '\x01')) {
    DAT_ffffd1e5 = 1;
  }
  else {
    DAT_ffffd1e5 = 0;
  }
  return cVar1;
}


